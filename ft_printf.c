/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:21:59 by gandre-d          #+#    #+#             */
/*   Updated: 2023/10/12 18:32:45 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params(char c, va_list *ap)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_params_c(va_arg(*ap, int)));
	if (c == 's')
		return (ft_params_s(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_params_p(va_arg(*ap, unsigned long), 0));
	if (c == 'd' || c == 'i')
		return (ft_params_d_i(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_params_u(va_arg(*ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_params_x(va_arg(*ap, unsigned int), c));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else
			count += ft_params(str[++i], &ap);
		i++;
	}
	va_end(ap);
	return (count);
}
