/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:21:31 by david             #+#    #+#             */
/*   Updated: 2021/10/18 16:24:10 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRERIAS ******************************** */

#include "libft.h"

/* ******************************* FUNCIONES ******************************** */

char	*ft_substr(const char *s, size_t i, size_t len)
{
	size_t	len2;
	char	*res;
	size_t	j;

	if (!s)
		return (0);
	len2 = ft_strlen(s + i);
	if (len2 > len)
		len2 = len;
	res = ft_calloc(len2 + 1, sizeof(char));
	if (!res)
		return (0);
	if (i > ft_strlen(s))
		return (res);
	j = 0;
	while (j < len2)
		res[j++] = s[i++];
	return (res);
}
