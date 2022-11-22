/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:43:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 17:29:42 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
			str[i++] = s1[i++];
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_one_line(char *text)
{
	char	*line;
	int		len;

	if (!text)
		return (NULL);
	len = 0;
	while (text[len] && text[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (text[len] && text[len] != '\n')
	{
		line[len] = text[len];
		len++;
	}
	line[len] = '\n';
	line[++len] = '\0';
	return (line);
}

char	*update_text(char *text)
{
	int		i;
	int		j;
	char	*update;

	i = 0;
	while(text[i] && text[i] != '\n')
		i++;
	if(!text[i])
	{
		free(text);
		return (NULL);
	}
	update = malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!update)
		return (NULL);
	i++;
	j = 0;
	while(text[i])
		update[j++] = text[i++];
	update[j] = '\0';
	free(text);
	return (update);
}

char	*get_next_line(int fd)
{
	int			n;
	char		*buff;
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	n = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (n != 0 && !ft_strchr(text, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	line = get_one_line(text);
	text = update_text(text);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open(argv[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }