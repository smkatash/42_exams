#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define UNDEF 0
#define PIPE 1
#define SEPARATOR 2
#define EOL 3
#define STDIN 0
#define STDOUT 1

typedef struct s_shell {
	int		token;
	int		len;
	char	**cmd;
	int		fd[2];
	int		pipe_flag;
	struct s_shell *prev;
	struct s_shell *next;
}	t_shell;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int	fd, int status)
{
	write(fd, str, ft_strlen(str));
	if (status)
		exit(status);
}

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

void	free_list(t_shell *head)
{
	t_shell	*temp;
	t_shell	*prev;

	temp = head;
	while (temp)
	{
		prev = temp->next;
		free_array(temp->cmd);
		free(temp);
		temp = prev;
	}
}

int	cmd_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && (strcmp(argv[i], "|") != 0) \
		&& (strcmp(argv[i], ";")) != 0)
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int		i;
	char	*dst;

	if (!str)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		ft_putstr_fd("error: fatal\n", 2, 1);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	set_token(char *str)
{
	if (str == NULL)
		return (EOL);
	if (strcmp(str, "|") == 0)
		return (PIPE);
	if (strcmp(str, ";") == 0)
		return (SEPARATOR);
	return (UNDEF);
}

void	push_back(t_shell **lst, t_shell *new)
{
	t_shell	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

int	lexer(t_shell **head, char **argv)
{
	t_shell	*new;
	int		i;

	new = malloc(sizeof(t_shell));
	if (!new)
		ft_putstr_fd("error: fatal\n", 2, 1);
	new->len = cmd_len(argv);
	new->cmd = malloc(sizeof(char*) * (new->len + 1));
	if (!new->cmd)
		ft_putstr_fd("error: fatal\n", 2, 1);
	i = 0;
	while (i < new->len)
	{
		new->cmd[i] = ft_strdup(argv[i]);
		i++;
	}
	new->cmd[i] = NULL;
	new->token = set_token(argv[i]);
	new->pipe_flag = 0;
	new->prev = NULL;
	new->next = NULL;
	push_back(head, new);
	return (i);
}

t_shell	*parse(char **argv, int argc)
{
	t_shell	*head;
	int		i;

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

void	cd_cmd(char **argv, int argc)
{
	if (argc > 3 || argv[2] == NULL)
		ft_putstr_fd("error: cd: bad arguments\n", 2, 1);
	if (chdir(argv[2]) != 0)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", 2, 0);
		ft_putstr_fd(argv[2], 2, 0);
		ft_putstr_fd("\n", 2, 1);
	}
}

void	child_process(t_shell *node, char **envp)
{
	if (node->token == PIPE && (dup2(node->fd[STDOUT], STDOUT_FILENO) < 0))
		ft_putstr_fd("error: fatal\n", 2, 1);
	if (node->prev && node->prev->token == PIPE \
		&& (dup2(node->prev->fd[STDIN], STDIN_FILENO) < 0))
		ft_putstr_fd("error: fatal\n", 2, 1);
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		ft_putstr_fd("error: cannot execute ", 2, 0);
		ft_putstr_fd(node->cmd[0], 2, 0);
		ft_putstr_fd("\n", 2, 1);
	}
	exit(EXIT_SUCCESS);
}

int	run_cmd(t_shell *node, char **envp)
{
	int		status;
	pid_t	pid;

	status = 0;
	if (node->token == PIPE || (node->prev && node->prev->token == PIPE))
	{
		if (pipe(node->fd))
			ft_putstr_fd("error: fatal\n", 2, 1);
		node->pipe_flag = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		child_process(node, envp);
	}
	else if (pid < 0)
		ft_putstr_fd("error: fatal\n", 2, 1);
	else
	{
		waitpid(pid, &status, 0);
		if (node->pipe_flag == 1)
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
	return (status);
}

int	execute(t_shell *lst, char **envp)
{
	t_shell	*node;
	int		status;

	status = 0;
	node = lst;
	while (node)
	{
		status = run_cmd(node, envp);
		node = node->next;
	}
	return (status);
}

int main(int argc, char **argv, char **envp)
{
	
	t_shell	*lst;
	int		status;

	lst = NULL;
	status = 0;
	if (argc > 1)
	{
		if (strcmp(argv[1], "cd") == 0)
			cd_cmd(argv, argc);
		else
		{
			lst = parse(argv, argc);
			if (lst)
			{
				status = execute(lst, envp);
				free_list(lst);
			}
		}
	}
	return (status);
}
