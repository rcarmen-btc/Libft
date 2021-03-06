/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <rcarmen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:04 by rcarmen           #+#    #+#             */
/*   Updated: 2021/02/06 14:55:26 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_printf(const char *f_str, ...)
{
	t_specs		*stuff;
	int			lenth;

	if (!(stuff = (t_specs *)malloc(sizeof(t_specs))))
		return (-1);
	ft_bzero(stuff, sizeof(t_specs));
	va_start(stuff->f_varg, f_str);
	stuff->f_str = f_str;
	while (*(stuff->f_str))
	{
		while (*(stuff->f_str) && *(stuff->f_str) != '%')
		{
			ft_putchar_fd(*(stuff->f_str), 1);
			stuff->full_lenth++;
			stuff->f_str++;
		}
		if (*(stuff->f_str) && *(stuff->f_str) == '%')
			ft_specifier_parser(stuff);
	}
	va_end(stuff->f_varg);
	lenth = stuff->full_lenth;
	free(stuff);
	return (lenth);
}
