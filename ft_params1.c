/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:54:59 by gandre-d          #+#    #+#             */
/*   Updated: 2023/10/12 18:36:28 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_params_s(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (str[i])
		count += write(1, &str[i++], 1);
	return (count);
}

int	ft_params_d_i(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2", 2);
		count += write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		count += write(1, "-", 1);
		count += ft_params_d_i(-n);
	}
	else if (n > 9)
	{
		count += ft_params_d_i(n / 10);
		count += ft_params_d_i(n % 10);
	}
	else
	{
		c = n + 48;
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_params_u(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
	{
		count += ft_params_u(n / 10);
		count += ft_params_u(n % 10);
	}
	else
	{
		c = n + 48;
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_params_x(unsigned int n, char c)
{
	char	*str;
	int		count;

	count = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_params_x(n / 16, c);
		count += ft_params_x(n % 16, c);
	}
	else
		count += write(1, &str[n], 1);
	return (count);
}
