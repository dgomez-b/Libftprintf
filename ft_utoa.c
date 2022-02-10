/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:07:03 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/10 17:26:30 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

char	*ft_utoa(unsigned int u)
{
	char	*str;
	char	*str2;
	char	*n;

	if (!u)
		return (ft_strdup("0"));
	n = ft_calloc(2, sizeof(char));
	str2 = ft_strdup("\0");
	while (u > 0)
	{
		*n = '0' + (u % 10);
		u /= 10;
		str = ft_strjoin(n, str2);
		free(str2);
		str2 = str;
	}
	free(n);
	return (str);
}
