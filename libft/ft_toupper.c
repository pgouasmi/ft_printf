/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:28:54 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/11/23 18:50:45 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		ch = ch - 32;
	return (ch);
}

/*
#include <stdio.h>
int	main()
{
	char c = '9';
	printf("%c devient %c\n", c, ft_toupper(c));
}
*/
