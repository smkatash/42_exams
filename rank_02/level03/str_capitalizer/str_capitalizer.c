/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:27:38 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/21 01:54:31 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	first_letter(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			c = s[i] - 32;
			write(1, &c, 1);
			i++;
			break ;
		}
		else if (s[i] >= 65 && s[i] <= 90)
		{
			c = s[i];
			write(1, &c, 1);
			i++;
			break ;
		}
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void	capitalize(char *s)
{
	int		i;
	char	c;

	i = first_letter(s);
	while (s[i])
	{
		if (s[i - 1] == ' ')
		{
			if (s[i] >= 97 && s[i] <= 122)
				c = s[i] - 32;
			else
				c = s[i];
		}
		else
		{
			if (s[i] >= 65 && s[i] <= 90)
				c = s[i] + 32;
			else
				c = s[i];
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			capitalize(argv[i]);
			if (i != (argc -1))
				write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
