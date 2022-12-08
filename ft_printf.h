/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:15 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/12/08 16:43:20 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_pf(int c, size_t *char_count);
void	ft_putstr_pf(const char *s, size_t *char_count);
void	ft_putnbr_base(long long int n, const char *base, size_t *char_count);
void	ft_putnbr_base_p(size_t n, const char *base, size_t *char_count);

#endif