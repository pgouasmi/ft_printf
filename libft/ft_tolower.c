/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:47:25 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/11/23 18:50:43 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		ch = ch + 32;
	return (ch);
}

/*
#include <stdio.h>
int	main()
{
	char c = 'a';
	printf("%c devient %c\n", c, ft_tolower(c));
}
*/
