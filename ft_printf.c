/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:58:17 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/10 17:23:51 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

static int	ft_printf_writer(const char *s, va_list *list)
{
	char	**args;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	args = ft_args(s, list);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i++] == '%')
		{
			if (s[i++] == 'c' && *args[j] == 0)
				k += write(1, args[j], 1);
			k += write(1, args[j], ft_strlen(args[j]));
			free(args[j++]);
		}
		else
			k += write(1, s + i - 1, 1);
	}
	free(args);
	return (k);
}

int	ft_printf(const char *s, ...)
{
	va_list	*list;
	int		i;

	list = ft_calloc(2, sizeof(va_list));
	va_start(*list, s);
	i = ft_printf_writer(s, list);
	va_end(*list);
	free(list);
	return (i);
}
