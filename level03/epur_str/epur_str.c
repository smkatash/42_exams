/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:06:04 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 03:25:28 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	skip_whitespace(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0')
	{
		while ((s[i] != ' ' && s[i] != '\t') && s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		skip_whitespace(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
