/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:13:41 by dgomez-b          #+#    #+#             */
/*   Updated: 2021/10/18 16:18:40 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRERIAS ******************************** */

#include "libft.h"

/* ******************************* FUNCIONES ******************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	if (s1 == s2)
		return (0);
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	while (i < len)
	{
		if (s3[i] > s4[i])
			return (1);
		else if (s4[i] > s3[i])
			return (-1);
		else if (s4[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
