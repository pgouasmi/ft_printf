/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:05:35 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/11/23 18:50:35 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_pos_neg(const char *str, int *i)
{
	if (str[(*i)] == '-')
	{
		(*i)++;
		return (0);
	}
	else if (str[(*i)] == '+')
	{
		(*i)++;
		return (1);
	}
	else if (str[(*i)] >= '0' && str[(*i)] <= '9')
		return (1);
	else
		return (2);
}

void	ft_skipws(const char *str, int *i)
{
	while (str[(*i)] == '\t' || str[(*i)] == '\n'
		|| str[(*i)] == '\v' || str[(*i)] == '\f'
		|| str[(*i)] == '\r' || str[(*i)] == ' ')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	long long int	result;
	int				i;
	int				*p_i;
	int				sign;

	i = 0;
	result = 0;
	p_i = &i;
	ft_skipws(str, p_i);
	sign = check_pos_neg(str, p_i);
	if (sign == 2)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != ((result * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (sign == 0)
		result = result * -1;
	return ((int)result);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = " 		 +214646849";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/