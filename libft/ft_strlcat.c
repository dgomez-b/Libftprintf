/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:08:12 by david             #+#    #+#             */
/*   Updated: 2021/10/21 16:32:39 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRERIAS ******************************** */

#include "libft.h"

/* ******************************* FUNCIONES ******************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!dstsize)
		return (ft_strlen(src));
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (len1 > dstsize)
		len1 = dstsize;
	i = 0;
	while (src[i] && (i + len1 + 1 < dstsize))
	{
		dst[i + len1] = src[i];
		i++;
	}
	if (i != 0)
		dst[i + len1] = 0;
	return (len1 + len2);
}
