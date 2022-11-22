/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:29:29 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/04 11:33:58 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h> 
#include <limits.h> 

int	print_string(char *str)
{
	int	len = 0;

	if (!str)
		str = "(null)";
	len = 0;
	while(str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	print_hex(unsigned num, int ret)
{
	char	d;
	if (num >= 16)
	{
		ret = print_hex(num / 16, ret);
		ret = print_hex(num % 16, ret);
	}
	if (num < 10)
	{
		d = num + '0';
		write(1, &d, 1);
		ret++;
	}
	else if (num < 16)
	{
		d = num + 'W';
		write(1, &d, 1);
		ret++;
	}
	return ret;
}

int	ft_putnbr(long long num, int ret)
{
	char	d;

	if (num > 9)
	{
		ret = ft_putnbr(num / 10, ret);
		ret = ft_putnbr(num % 10, ret);
	}
	else
	{
		d = num + '0';
		write(1, &d, 1);
		ret++;
	}
	return ret;
}

int	print_digit(long long num)
{
	long long	neg;
	int	ret;

	neg = 1;
	ret = 0;
	if (num < 0)
	{
		neg = -1;
		write(1, "-", 1);
		ret += 1;
	}
	num *= neg;
	ret = ft_putnbr(num, ret);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	char	*args;
	int		g_value;
	va_list	ptr;

	va_start(ptr, format);
	args = (char *)format;
	g_value = 0;
	while (*args)
	{
		if (*args == '%')
		{
			args++;
			if (*args == 's')
				g_value += print_string(va_arg(ptr, char *));
			else if (*args == 'd')
				g_value += print_digit(va_arg(ptr, int));
			else if (*args == 'x')
				g_value += print_hex(va_arg(ptr, unsigned int), 0);
			else
				args++;
		}
		else
			g_value += write(1, &(*args), 1);
		args++;
	}
	va_end(ptr);
	return (g_value);
}

// int	main(void)
// {
// 	char *str;

// 	str = "hello, world!";
// 	printf("Orig: %s\n", str);
// 	ft_printf("Mine: %s\n", str);
// 	ft_printf("Mine: %s is %d and %x\n", "Number", 42, 01);
// 	printf("Orig: %s is %d and %x\n", "Number", 42, 01);
// 	ft_printf("Mine: %s for %d is %x\n", "Hexadecimal is", INT_MAX, -42);
// 	printf("Orig: %s for %d is %x\n", "Hexadecimal is", INT_MAX, -42);
// 	printf("Orig: %d\n", INT_MIN);
// 	ft_printf("Mine: %d\n", INT_MIN);
// 	printf("%x\n", INT_MAX);
// 	ft_printf("%x\n", INT_MAX);
// 	return (0);
// }
