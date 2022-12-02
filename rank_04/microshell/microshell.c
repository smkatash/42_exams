#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define UNDEF 0
#define PIPE 1
#define SEPARATOR 2
#define EOL 3
#define STDIN 0
#define STDOUT 1

typedef struct s_shell
{
	int	token;
	char **cmds;
	int	len;
	int	pipe;
	int fd[2];
	struct s_shell *next;
	struct s_shell *prev;
}	t_shell;


void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_shell *lst)
{
	t_shell	*tmp;
	t_shell	*next;

	tmp = lst;
	while (tmp)
	{
		next = tmp->next;
		free_array(tmp->cmds);
		free(tmp);
		tmp = next;
	}
}

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd, int status)
{
	write(fd, str, ft_strlen(str));
	if (status)
		exit(status);
}

int	counter(char **str)
{
	int	i;

	i = 0;
	while(str[i] && strcmp(str[i], ";") != 0 \
		&& strcmp(str[i], "|") != 0)
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		ft_putstr_fd("error: fatal\n", 2, 1);
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char **get_cmd(char **str, int len, int *tok)
{
	char	**arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		ft_putstr_fd("error: fatal\n", 2, 1);
	while (i < len)
	{
		arr[i] = ft_strdup(str[i]);
		i++;
	}
	arr[i] = NULL;
	*tok = i;
	return (arr);
}

int	set_token(char *str)
{
	if (str == NULL)
		return (EOL);
	else if (strcmp(str, "|") == 0)
		return (PIPE);
	else if (strcmp(str, ";") == 0)
		return (SEPARATOR);
	return (UNDEF);
}

void	push_back(t_shell **head, t_shell *node)
{
	t_shell	*tmp;

	tmp = *head;
	if (*head == NULL)
		*head = node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
}

int	lexer(t_shell **head, char **str)
{
	t_shell *new;
	int		tok;

	tok = 0;
	new = malloc(sizeof(t_shell));
	if (!new)
		ft_putstr_fd("error: fatal\n", 2, 1);
	new->len = counter(str);
	new->cmds = get_cmd(str, new->len, &tok);
	new->token = set_token(str[tok]);
	new->pipe = 0;
	new->next = NULL;
	new->prev = NULL;
	push_back(head, new);
	return (tok);
}

t_shell	*parse(int argc, char **argv)
{
	t_shell	*head;
	int	i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], ";") == 0)
		{
			i++;
			continue;
		}
		i += lexer(&head, &argv[i]);
		i++;
	}
	return (head);
}

void	run_child(t_shell *node, char **envp)
{
	if (node->token == PIPE && dup2(node->fd[STDOUT], STDOUT_FILENO) < 0)
		ft_putstr_fd("error: fatal\n", 2, 1);
	if (node->prev && node->prev->token == PIPE && \
		dup2(node->prev->fd[STDIN], STDIN_FILENO) < 0)
		ft_putstr_fd("error: fatal\n", 2, 1);
	if (execve(node->cmds[0], node->cmds, envp) == -1)
	{
		ft_putstr_fd("error: cannot execute ", 2, 0);
		ft_putstr_fd(node->cmds[0], 2, 0);
		ft_putstr_fd("\n", 2, 1);
	}
	exit(EXIT_SUCCESS);
}

int	run_cmd(t_shell *node, char **envp)
{
	int	status;
	pid_t pid;

	status = 0;
	pid = 0;
	if (strcmp(node->cmds[0], "cd") == 0)
	{
		if (node->len < 2)
		{
			ft_putstr_fd("error: cd: bad arguments\n", 2, 0);
            status = 1;
		}
		else if (chdir(node->cmds[1]) != 0)
        {
            ft_putstr_fd("error: cd: cannot change directory to ", 2, 0);
		    ft_putstr_fd(node->cmds[1], 2, 0);
		    ft_putstr_fd("\n", 2, 0);
            status = 1;
        }
	}
	else
	{
		if (node->token == PIPE || (node->prev && node->prev->token == PIPE))
		{
			if (pipe(node->fd))
				ft_putstr_fd("error: fatal\n", 2, 1);
			node->pipe = 1;
		}
		pid = fork();
		if (pid < 0)
			ft_putstr_fd("error: fatal\n", 2, 1);
		else if (pid == 0)
			run_child(node, envp);
		else
		{
			waitpid(pid, &status, 0);
			if (node->pipe == 1)
			{
				close(node->fd[STDOUT]);
				if (node->token == EOL || node->token == SEPARATOR)
					close(node->fd[STDIN]);
			}
			if (node->prev && node->prev->token == PIPE)
				close(node->prev->fd[STDIN]);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}
	}
	return (status);
}

int	execute(t_shell *head, char **envp)
{
	t_shell	*node;
	int		status;

	status = 0;
	node = head;
	while (node)
	{
		status = run_cmd(node, envp);
		node = node->next;
	}
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	t_shell *lst;

	status = 0;
	lst = NULL;
	if (argc > 1)
	{
		lst = parse(argc, argv);
		if (lst)
		{
			status = execute(lst, envp);
			free_list(lst);
		}
	}
	return (status);
}
