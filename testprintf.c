/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/01 17:20:47 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
int	ft_digit_count(unsigned int n, int *div, int base)
{
	int	i;
	
	i = 1;
	while (n / *div >= base)
	{
		*div = *div * base;
		i++;
	}
	return (i);
}

char	*ft_put_digit(char *str, unsigned int nbr, int i, int diviseur, int basevalue)
{
	char *base;
	
	if (basevalue <= 10)
	{
		while (diviseur >= 1)
		{
			str[i] = nbr / diviseur + 48;
			nbr = nbr - ((str[i] - 48) * diviseur);
			diviseur = diviseur / basevalue;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}

char	*ft_itoa(int n, int base)
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
		str = malloc(sizeof(char) * ft_digit_count(nbr, &div, base) + 2);
	}
	else
		str = malloc(sizeof(char) * ft_digit_count(nbr, &div, base) + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[i] = '-';
		nbr = n * -1;
		i++;
	}
		return (ft_put_digit(str, nbr, i, div, base));
}

int	ft_printf(const char *format, ...)
{
	va_list parameterInfos;
	size_t	writtenChar;
	char	currentChar;
	char 	*str;
	size_t	i;
	int base;

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
				base = 10;
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
			else if (format[i] == 'd')
			{
				base = 10;
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
			else if (format[i] == '%' )
			{
				write(1, &currentChar, 1);
				writtenChar++;
			}
			else if (format[i] == 'p')
			{
				str = va_arg(parameterInfos, void *);
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}
			}
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
			else if (format[i] == 'u')
			{
				base = 10;
				int nbr = va_arg(parameterInfos, int);
				if (nbr < 0)
					nbr *= -1;
				str = ft_itoa(nbr, base);
				currentChar = *str;
				while(*str)
				{
					currentChar = *str;
					write(1, &currentChar, 1);
					writtenChar++;
					str++;
				}	
			}
			else if (format[i] == 'x')
			{
				base = 16;
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
			i++;
		}
	}
	return (writtenChar);
}


int main()
{
	char prenom[] = "pascal";
	char nom[] = "gsm";
	int	age = -27;
	//const char format[] = "sd";
	ft_printf("Je m'apppp%dppp%%pp%cpelle %s\n", age, 'Z', prenom);
}