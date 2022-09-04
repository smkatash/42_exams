/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:57:29 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/04 18:41:14 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*positive(int nbr, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[len--] = '\0';
	while (nbr != 0)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

char	*negative(int nbr, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[len + 1] = '\0';
	while (nbr != 0 && len > 0)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	int		cp;
	int		neg;

	len = 0;
	neg = 1;
	if (nbr < 0)
	{
		neg = -1;
		nbr = nbr * -1;
	}
	cp = nbr;
	while (cp != 0)
	{
		cp = cp / 10;
		len++;
	}
	if (neg == -1)
		str = negative(nbr, len);
	else
		str = positive(nbr, len);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(0);
// 	printf("%s\n", str);
// 	str = ft_itoa(5269);
// 	printf("%s\n", str);
// 	str = ft_itoa(-258);
// 	printf("%s\n", str);
// 	return (0);
// }
