/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:53:18 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/02/09 13:22:03 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ******************************* LIBRARIES ******************************** */

# include "./libft/libft.h"
# include <stdarg.h>

/* ******************************* PROTOTIPES ******************************* */

int	ft_printf(const char *s, ...);
char	*ft_printf_str(char *s);
char	*ft_printf_char(char c);
char	*ft_itobase(unsigned int i, char *base);
char	*ft_itov(unsigned long int n);
char	**ft_args(const char *s, va_list list);
char	*ft_translate(va_list *list, char c);

#endif
