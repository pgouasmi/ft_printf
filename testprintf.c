/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/02 14:31:24 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_error(char *base, int *error)
{
	long int	i;
	long int	j;

	i = 0;
	j = 1;
	while (base[j])
	{
		while (base[i])
		{
			if (i != j)
			{
				if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
					*error = 1;
				else
					i++;
			}
			else
				i++;
		}
		j++;
		i = 0;
	}
	*error = 0;
}

long int	ft_length(char *base)
{
	long int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base_X(int nbr, size_t *writtenChar)
{
	int			error;
	long int	lnbr;
	char *base = "0123456789ABCDEF";

	ft_error(base, &error);
	if (error == 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			(*writtenChar)++;
			nbr = nbr * -1;
		}
		lnbr = nbr;
		if (ft_length(base) <= 1)
		{
			write(1, "Error\n", 6);
			(*writtenChar)++;
		}
		if (lnbr < ft_length(base))
		{
			write(1, &base[lnbr % ft_length(base)], 1);
			(*writtenChar)++;
		}
		if (lnbr > ft_length(base))
		{
			write(1, &base[lnbr / ft_length(base)], 1);
			write(1, &base[lnbr % ft_length(base)], 1);
			(*writtenChar) += 2;
		}
	}
}

void	ft_putnbr_base_x(size_t nbr, size_t *writtenChar)
{
	int		error;
	size_t	lnbr;
	char *base = "0123456789abcdef";

	printf("\n%zu\n\n", nbr);

	ft_error(base, &error);
	if (error == 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			(*writtenChar)++;
			nbr = nbr * -1;
		}
		lnbr = nbr;
		if (ft_length(base) <= 1)
		{
			write(1, "Error\n", 6);
			(*writtenChar)++;
		}
		if (lnbr < ft_length(base))
		{
			write(1, &base[lnbr % ft_length(base)], 1);
			(*writtenChar)++;
		}
		if (lnbr > ft_length(base))
		{
			write(1, &base[lnbr / ft_length(base)], 1);
			write(1, &base[lnbr % ft_length(base)], 1);
			(*writtenChar) += 2;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list parameterInfos;
	size_t	writtenChar;
	char	currentChar;
	char 	*str;
	size_t	i;

	if (write(1, 0, 0) != 0)
		return(-1);
	writtenChar = 0;
	i = 0;
	va_start(parameterInfos, format);
	while((currentChar = format[i]))
	{
		i++;
		if (currentChar != '%')
		{
			write(1, &currentChar, 1);
			writtenChar++;
		}
		else 
		{
			if (format[i] == 's')
			{
				str = va_arg(parameterInfos, char *);
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}
			}
			if (format[i] == 'c')
			{
				str[0] = va_arg(parameterInfos, int);
				currentChar = str[0];
				write(1, &currentChar, 1);
				writtenChar++;
			}
			else if (format[i] == 'i')
			{
				str = ft_itoa(va_arg(parameterInfos, int));
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}	
			}
			else if (format[i] == 'd')
			{
				str = ft_itoa(va_arg(parameterInfos, int));
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}	
			}
			else if (format[i] == '%' )
			{
				write(1, &currentChar, 1);
				writtenChar++;
			}
			else if (format[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr_base_x(va_arg(parameterInfos, size_t), &writtenChar);
			}
			/*
			else if (format[i] == 'o')
			{
				base = 8;
				str = ft_itoa(va_arg(parameterInfos, int), base);
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}	
			}
			*/
			else if (format[i] == 'u')
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
			else if (format[i] == 'X')
				ft_putnbr_base_X(va_arg(parameterInfos, int), &writtenChar);
			else if (format[i] == 'x')
				ft_putnbr_base_x(va_arg(parameterInfos, int), &writtenChar);
			i++;
		}
	}
	va_end(parameterInfos);
	return (writtenChar);
}


int main()
{
	char prenom[] = "pascal";
	char nom[] = "gsm";
	int	age = -215617;
	//const char format[] = "sd";
	ft_printf("%X\n\n", age);
	// printf("%zd\n", &age);
	// printf("%p\n", &age);
	// ft_printf("%p\n", &age);
	return(0);
}