/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:26:31 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/08 16:39:39 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_p(size_t n, const char *base, size_t *char_count)
{
	size_t	base_length;

	base_length = ft_strlen(base);
	ft_putstr_pf("0x", char_count);
	if (n < base_length)
		ft_putchar_pf(base[n], char_count);
	else
	{
		ft_putnbr_base(n / base_length, base, char_count);
		ft_putnbr_base(n % base_length, base, char_count);
	}
}
