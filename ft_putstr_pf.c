/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:40:52 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/08 16:40:15 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(const char *s, size_t *char_count)
{
	if (!s)
		ft_putstr_pf((const char *)"(null)", char_count);
	else
	{
		while (*s)
		{
			ft_putchar_pf(*s, char_count);
			s++;
		}
	}
}
