/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:36:48 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/01/24 16:23:55 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "libftprintf.h"

/* ******************************** LIBRARIES ******************************* */

static int	ft_freemat(void **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	if (mat)
		free(mat);
	return (0);
}

static int	ft_amountchar(const char *s, char c)
{
	int	i;
	int	amount;

	if (!s)
		return (-1);
	i = 0;
	amount = 0;
	while (s[i])
		if (s[i++] == c)
			amount++;
	return (amount);
}

static char	**ft_args(const char *s, va_list list)
{
	char	**mat;
	int		i;
	int		j;

	if (!s)
		return (0);
	mat = ft_calloc(ft_amountchar(s, '%') + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] == '%')
		{
			mat[j] = ft_strdup(va_arg(list, char *));
			if (!mat[j++])
			{
				ft_freemat((void *)mat);
				return (0);
			}
		}
	}
	return (mat);
}

static int	ft_printf_write(const char *s, char **mat)
{
	int	i;
	int	j;
	int	amount;

	i = 0;
	j = 0;
	amount = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			amount += write(1, mat[j], ft_strlen(mat[j]));
			j++;
			i += 2;
		}
		else
			amount += write(1, s + i++, 1);
	}
	return (amount - 1);
}

int	ft_printf(const char *s, ...)
{
	char	**mat;
	int		amount;
	va_list	list;

	if (!s)
		return (0);
	va_start(list, s);
	mat = ft_args(s, list);
	va_end(list);
	if (!mat)
		return (ft_freemat((void *)mat));
	amount = ft_printf_write(s, mat);
	ft_freemat((void *)mat);
	return (amount);
}
