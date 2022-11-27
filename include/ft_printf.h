/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:13:28 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/03 11:11:07 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <inttypes.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchr(int c);
int	ft_puthex(unsigned int n, int flag);
int	ft_putnbr(int n);
int	ft_put_ptr(uintptr_t ptr);
int	ft_putstr(char *p);
int	ft_putnbr_ui(unsigned int n);

#endif
