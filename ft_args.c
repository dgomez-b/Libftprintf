/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:52:14 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/09 13:33:04 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

static int	ft_cantchar(const char *s, char c)
{
	int		pos;
	int		cant;

	if (!s)
		return (0);
	pos = 0;
	cant = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			cant++;
		pos++;
	}
	return (cant);
}

char	**ft_args(const char *s, va_list list)
{
	char	**args;
	int		pos;
	int		cant;

	cant = ft_cantchar(s, '%');
	if (cant == 0)
		return (0);
	args = ft_calloc(cant, sizeof(char*));
	pos = 0;
	cant = 0;
	while (s[pos])
		if (s[pos++] == '%')
			args[cant++] = ft_translate(&list, s[pos++]);
	return (args);
}