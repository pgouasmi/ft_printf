/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/07 16:37:07 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

int	ft_digit_count(unsigned int n, int *div)
{
	int	i;
	
	i = 1;
	while (n / *div >= 10)
	{
		*div = *div * 10;
		i++;
	}
	return (i);
}

char	*ft_put_digit(char *str, unsigned int nbr, int i, int diviseur)
{
	while (diviseur >= 1)
	{
		str[i] = nbr / diviseur + 48;
		nbr = nbr - ((str[i] - 48) * diviseur);
		diviseur = diviseur / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char				*str;
	int					i;
	int					div;
	unsigned int		nbr;

	i = 0;
	div = 1;
	nbr = n;
	if (n < 0)
	{
		nbr = nbr * -1;
		str = malloc(sizeof(char) * ft_digit_count(nbr, &div) + 2);
	}
	else
		str = malloc(sizeof(char) * ft_digit_count(nbr, &div) + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[i] = '-';
		nbr = n * -1;
		i++;
	}
	str = ft_put_digit(str, nbr, i, div);
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_X(int nbr, size_t *writtenChar, char *base)
{
	long	nbr_l;
	char	nbr_c[32];
	int		base_divider;
	int		i;

	if (!ft_check_base(base))
		return ;
	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-');
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(nbr_c[i]);
		(*writtenChar)++;
	}
}

void	ft_putnbr_base_x(size_t nbr, size_t *writtenChar, char *base)
{
	size_t	nbr_l;
	char	nbr_c[32];
	int		base_divider;
	int		i;

	if (!ft_check_base(base))
		return ;
	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-');
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(nbr_c[i]);
		(*writtenChar)++;
	}
}


int	check_arg_validity(const char *format, ...)
{
	va_list parameterInfos;
	size_t	i;

	va_start(parameterInfos, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%' && format[i + 2] == '%')
				return (0);
			else if (format[i + 1] != 'c' || format[i + 1] != 's' || format[i + 1] != 'p'
			|| format[i + 1] != 'd' || format[i + 1] != 'i' || format[i + 1] != 'u'
			|| format[i + 1] != 'x' || format[i + 1] != 'X')
				return (0);
		}
		i++;
	}
	return (1);
}


int	ft_printf(const char *format, ...)
{
	va_list parameterInfos;
	size_t	writtenChar;
	char	currentChar;
	char 	*str;

	if (write(1, 0, 0) != 0)
		return(-1);
	writtenChar = 0;
	va_start(parameterInfos, format);
	while((currentChar = *format))
	{
		format++;
		if (currentChar != '%')
		{
			write(1, &currentChar, 1);
			writtenChar++;
		}
		else 
		{
			if (*format == 's')
			{
				str = va_arg(parameterInfos, char *);
				writtenChar += ft_strlen(str);
				ft_putstr_fd(s, 1);
			}
			if (*format == 'c')
			{
				currentChar = va_arg(parameterInfos, int);
				ft_putchar_fd(currentChar, 1);
				writtenChar++;
			}
			else if (*format == 'i' || *format == 'd')
			{
				str = ft_itoa(va_arg(parameterInfos, int));
				writtenChar += ft_strlen(str);
				ft_putstr_fd(s, 1);
			}
			else if (*format == '%' )
			{
				write(1, &currentChar, 1);
				writtenChar++;
			}

			else if (*format == 'p')
			{
				write(1, "0x", 2);
				writtenChar += 2;
				ft_putnbr_base_x((size_t)va_arg(parameterInfos, void *), &writtenChar);
			}
			else if (*format == 'u')
			{
				int nbr = va_arg(parameterInfos, int);
				if (nbr < 0)
					nbr *= -1;
				str = ft_itoa(nbr);
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}	
			}
			else if (*format == 'X')
				ft_putnbr_base_X(va_arg(parameterInfos, int), &writtenChar, "0123456789ABCDEF");

			else if (*format == 'x')
				ft_putnbr_base_x(va_arg(parameterInfos, size_t), &writtenChar, "0123456789abcdef");
			format++;
		}
	}
	va_end(parameterInfos);
	return (writtenChar);
}

int main()
{
	char prenom[] = "pascal";
	char nom[] = "gsm";
	int	age = 161561451;
	ft_printf("%p\n", &age);
	printf("%p\n", &age);

	return(0);
}
*/