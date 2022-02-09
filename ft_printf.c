/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:58:17 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/09 09:38:33 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************** LIBRARIES ******************************* */

#include "ft_printf.h"

/* ******************************** FUNCTIONS ******************************* */

static char	*ft_translate(va_list *list, char c)
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
		return (ft_itoa(va_arg(*list, unsigned int)));
	if (c == 'x')
		return (ft_itobase(va_arg(*list, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_itobase(va_arg(*list, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_itov(va_arg(*list, unsigned long int)));
	return (ft_strdup("\0"));
}

static char	*ft_substrc(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	if (!c)
		return (ft_strdup(s));
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_substr(s, 0, i));
}

static char	*ft_joinargs(const char *s, va_list list)
{
	char	*str;
	char	*str2;
	char	*args;
	int		i;

	if (!s)
		return (0);
	str = ft_substrc(s, '%');
	i = ft_strlen(str);
	if (s[i] != '%')
		return (str);
	args = ft_translate(&list, s[i + 1]);
	str2 = ft_strjoin(str, args);
	free(args);
	free(str);
	if (!s[i + 2])
		return (str2);
	str = str2;
	args = ft_joinargs(s + i + 2, list);
	str2 = ft_strjoin(str, args);
	free(args);
	free(str);
	return (str2);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	va_list	list;
	int		i;

	va_start(list, s);
	str = ft_joinargs(s, list);
	va_end(list);
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}
