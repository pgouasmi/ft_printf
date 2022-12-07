/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf22.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:19:09 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/07 19:53:05 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_sc
{
	int len;
	int width;
}				t_sc;

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putchar (int c, t_sc *sc)
{
	write(1, &c, 1);
	sc->len++;
}

void ft_putstr(const char *s, t_sc *sc)
{
	while (*s)
	{
		ft_putchar(*s, sc);
		s++;
	}	
}

const char *ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (s);
	if (!s)
		return (s);
	return (NULL);
}
void	ft_putnbr_base(long long int n, const char *base, t_sc *sc)
{
	size_t			nbr;
	int				base_length;

	base_length = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-', sc);
		nbr = n * -1;
	}
	else 
		nbr = n;
	if (nbr < base_length)
		ft_putchar(base[nbr], sc);
	else
	{
		ft_putnbr_base(nbr / base_length, base, sc);
		ft_putnbr_base(nbr % base_length, base, sc);
	}

}
const char *ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr_base(va_arg(arg, int), "0123456789", sc);
	if (*format == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", sc);
	if (*format == 'x')
		ft_putnbr_base(va_arg(arg, int), "0123456789abcdef", sc);
	if (*format == 'X')
		ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF", sc);
	if (*format == 's')
		ft_putstr(va_arg(arg, const char *), sc);
	if (*format == 'c')
		ft_putchar(va_arg(arg, int), sc);
	if (*format == '%')
		ft_putchar('%', sc);
	if (*format == 'p')
	{
		ft_putstr("0x", sc);
		ft_putnbr_base(va_arg(arg, void *), "0123456789abcdef", sc);
	}
	format++;
	return (format);
}
/*cherche dans la string la premiere occurence de '%' avec strchr et enregisttre tous les caracteres precedant le '%' dans la string next
si un '%' est trouve, sc.width devient la  */
const char *ft_puttext(t_sc *sc, const char *format)
{
	const char *next;

	next = ft_strchr(format, '%');
	if (next)
	{
		sc->width = next - format; // difference d'adressessssssssss du premier caractere de chaque string 
	}
	else
		sc->width = ft_strlen(format);
	write (1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		++format;
	return (format);
}

int ft_printf(const char *format, ...)
{
	va_list arg;
	t_sc sc;
	sc.len = 0;
	sc.width = 0;

	if (write(1, 0, 0))
		return (-1);
	va_start(arg, format);
	while (*format)
		{
			if (*format == '%')
				format = ft_search_arg(arg, format + 1, &sc);
			else 
				format = ft_puttext(&sc, format);
			if (!format)
			{
				write(1, "null", 6);
				va_end(arg);
				return (6);
			}
		}
		va_end(arg);
		return (sc.len);
}

int main()
{
	int age = 45;

	ft_printf("%d\n", ft_printf("z%sca%dca%u%p%%\n", "yes", -123, 789456, &age));
	printf("%d\n", printf("z%sca%dca%u%p%%\n", "yes", -123, 789456, &age));
}