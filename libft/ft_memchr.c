/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:47:04 by dgomez-b          #+#    #+#             */
/*   Updated: 2021/10/18 16:17:07 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRERIAS ******************************** */

#include "libft.h"

/* ******************************* FUNCIONES ******************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	k;

	i = 0;
	j = (unsigned char *)s;
	k = (unsigned char)c;
	while ((i < n) && (j[i] != k))
		i++;
	if (i == n)
		return (0x0);
	return (j += i);
}
