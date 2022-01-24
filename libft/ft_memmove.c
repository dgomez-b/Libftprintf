/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:15 by dgomez-b          #+#    #+#             */
/*   Updated: 2021/10/18 16:17:23 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRERIAS ******************************** */

#include "libft.h"

/* ******************************* FUNCIONES ******************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*i;
	size_t	j;
	size_t	k;

	k = 0;
	while ((k < len) && (src + k != dst))
		k++;
	i = ((void *)src);
	j = 0;
	if (src != dst)
	{
		if (k < len)
			while (len-- > 0)
				((char *)dst)[len] = ((char *)i)[len];
		else
		{
			k = 0;
			while (k < len)
			{
				((char *)dst)[k] = ((char *)i)[k];
				k++;
			}
		}
	}
	return (dst);
}
