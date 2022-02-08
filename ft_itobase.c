/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:33:56 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/08 18:47:50 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

char	*ft_itobase(unsigned int i, char *base)
{
	char	*str;
	char	*str2;
	char	*str3;
	int		len;

	if (!base)
		return (0);
	if (i == 0)
		return (ft_strdup("0"));
	len = ft_strlen(base);
	str = ft_calloc(2, sizeof(char));
	str3 = ft_strdup("\0");
	while (i > 0)
	{
		*str = base[i % len];
		i /= len;
		str2 = ft_strjoin(str, str3);
		free(str3);
		str3 = str2;
	}
	free(str);
	return (str3);
}