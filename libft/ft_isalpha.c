/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:29:18 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/11/28 13:24:31 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if character is alphabetical
 * As described by man ascii(7)
 */
int	ft_isalpha(int c)
{
	return (
		('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z')
	);
}

/*
#include <stdio.h>
int	main()
{
	char c = '8';
	printf("%d\n", ft_isalpha(c));
}
*/
