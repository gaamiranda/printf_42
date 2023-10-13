/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:58:01 by gandre-d          #+#    #+#             */
/*   Updated: 2023/10/12 18:34:51 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params_p(unsigned long n, int i)
{
	int		count;
	char	*str;

	count = 0;
	if (n == 0 && i == 0)
		return (write(1, "(nil)", 5));
	str = "0123456789abcdef";
	if (i == 0)
		count += write(1, "0x", 2);
	if (n > 15)
	{
		count += ft_params_p(n / 16, 1);
		count += ft_params_p(n % 16, 1);
	}
	else
		count += write(1, &str[n], 1);
	return (count);
}
