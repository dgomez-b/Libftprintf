/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:58:14 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/10 17:17:28 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

char	*ft_translate(va_list *list, char c)
{
	if (c == '%')
		return (ft_strdup("%"));
	if (c == 'c')
		return (ft_printf_char(va_arg(*list, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(*list, char *)));
	if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(*list, int)));
	if (c == 'u')
		return (ft_utoa(va_arg(*list, unsigned int)));
	if (c == 'x')
		return (ft_itobase(va_arg(*list, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_itobase(va_arg(*list, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_itov(va_arg(*list, unsigned long int)));
	return (ft_strdup("\0"));
}
