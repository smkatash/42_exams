/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:52:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/07/24 02:46:19 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_last(char *str, int len)
{
	while (len >= 0)
	{
		while(str[len] != '\0' && (str[len] == '\t' || str[len] == ' '))
			len--;
		while(str[len] != '\0' && str[len] != '\t' && str[len] != ' ')
			len--;
		if(str[len] != '\0' && (str[len] == '\t' || str[len] == ' '))
			return (1);
		len--;
	}
	return (0);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	read_reverse(char *str)
{
	int		len;
	int		w_len;
	int		i;
	char	*rev;

	len = 0;
	while (str[len])
		len++;
	rev = malloc(sizeof(char) * (len + 1));
	if (!rev)
		rev = NULL;
	len--;
	i = 0;
	while(len >= 0)
	{
		w_len = 0;
		while (str[len] != '\0' && str[len] != '\t' && str[len] != ' ')
		{
			len--;
			w_len++;
		}
		len++;
		while (str[len] != '\0' && str[len] != '\t' && str[len] != ' ')
			rev[i++] = str[len++];
		if (check_last(str, len) == 1)
			rev[i++] = ' ';
		len = len - w_len - 2;
	}
	rev[i] = '\0';
	put_str(rev);
	free(rev);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		read_reverse(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}