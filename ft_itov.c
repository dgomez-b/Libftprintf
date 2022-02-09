/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:07:37 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/09 17:56:34 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

char	*ft_itov(unsigned long int n)
{
	char	*str;
	char	*str2;
	char	*hex;

	if (n == 0)
		return (ft_strdup("0x0"));
	str2 = ft_strdup("");
	while (n > 0)
	{
		hex = ft_itobase(n % 16, "0123456789abcdef");
		n /= 16;
		str = ft_strjoin(hex, str2);
		free(str2);
		str2 = str;
		free(hex);
	}
	str = ft_strjoin("0x", str2);
	free(str2);
	return (str);
}
