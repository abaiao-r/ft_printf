/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:10:22 by andrefranci       #+#    #+#             */
/*   Updated: 2022/11/22 15:10:47 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_ptr(unsigned long long n, char *base, int j, int fe)
{
	int	i;

	i = 0;
	if (!n && fe == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (fe == 0)
	{
		ft_putstr("0x");
		i = i + 2; 
	}
	if (n / j > 0)
		i = i + ft_putnbr_ptr(n / j, base, j);
	write(1, &base[n % j], 1);
	i++;
	return (i);
}

static int	format(char *s, va_list args)
{
	int	i;

	if (s[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i] == 'p')
		return (ft_putnbr_ptr(va_arg(args, long int), "0123456789abcdef", 16,
				0));
	else if (s[i] == 'i' || s[i] == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 10));
	else if (s[i] == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10));
	else if (s[i] == 'x')
		return (ft_putnbr_base(args, unsigned int), "0123456789abcdef", 16);
	else if (s[i] == 'X')
		return (ft_putnbr_base(args, unsigned int), "0123456789ABCDEF", 16);
	else if (s[i] == '%')
		return (write(1, "%%", 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		size;

	va_start(args, s);
	size = 0;
	while (*s)
	{
		if (*s != '%')
		{
			write(1, &*s, 1);
			size++;
		}
		else
		{
			s++;
			size = size + format(*s, args);
		}
		s++;
	}
	va_end(args);
	return (size);
}

/* int main(void)
{
	printf("%i: ", ft_printf("\nmy func = %d\n", -1));
	printf("\n%i: ", printf("\nmy func = %d\n", -1));
	return (0);
} */