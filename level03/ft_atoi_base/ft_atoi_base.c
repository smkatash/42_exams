/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:51:18 by ktashbae          #+#    #+#             */
/*   Updated: 2022/07/20 06:12:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	base(char c, int base)
{
	char	*lower;
	char	*upper;
	int		i;

	i = 0;
	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == lower[i] || c == upper[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		neg;
	int		num;
	char	*s;

	i = 0;
	neg = 1;
	num = 0;
	s = (char *)str;
	if ((s[i] == '-' || s[i] == '+') && s[i] != '\0')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (base(s[i], str_base) != -1)
	{
		num = (num * str_base) + base(s[i], str_base);
		i++;
	}
	return (num * neg);
}

// int	main(void)
// {
// 	char	*str;
// 	int		result;

// 	str = "12fdb3";
// 	result = ft_atoi_base(str, 16);
// 	printf("%d\n", result);
// 	return (0);
// }
