/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exapnd_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:29:09 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 03:50:30 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add_three_spaces(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = 'c';
	while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			write(1, " ", 1);
			write(1, " ", 1);
			write(1, " ", 1);
		}
	}
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		add_three_spaces(argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
