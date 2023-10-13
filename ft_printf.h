/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:09:32 by gandre-d          #+#    #+#             */
/*   Updated: 2023/10/12 18:32:57 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_params_c(char c);
int	ft_params_s(char *str);
int	ft_params_d_i(int n);
int	ft_params_u(unsigned int n);
int	ft_params_x(unsigned int n, char c);
int	ft_params_p(unsigned long n, int i);

#endif
