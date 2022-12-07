#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar (int c, t_sc *sc);
void	ft_putstr(const char *s, t_sc *sc);
void	ft_putnbr_base(long long int n, const char *base, t_sc *sc);

#endif