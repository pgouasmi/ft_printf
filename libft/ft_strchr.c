/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:16:51 by pgouasmi          #+#    #+#             */
/*   Updated: 2022/11/28 17:13:53 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		else
			i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (0);
}

/*
#include <stdio.h>
int main()
{
	printf("%s\n%c\n", ft_strchr("teste", 't' + 256), 't' + 256);
}
*/
