/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:20:52 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/23 22:19:48 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	selection_percent(va_list *ap, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_putchr((int)va_arg(*ap, int));
	else if (*format == 's')
		len = ft_putstr((char *)va_arg(*ap, char *));
	else if (*format == 'p')
		len += ft_put_ptr((uintptr_t)va_arg(*ap, uintptr_t));
	else if (*format == 'd')
		len += ft_putnbr((int)va_arg(*ap, int));
	else if (*format == 'i')
		len += ft_putnbr((int)va_arg(*ap, int));
	else if (*format == 'u')
		len += ft_putnbr_ui((unsigned int)va_arg(*ap, unsigned int));
	else if (*format == 'x')
		len += ft_puthex(((unsigned long)va_arg(*ap, unsigned long)), 0);
	else if (*format == 'X')
		len += ft_puthex(((unsigned long)va_arg(*ap, unsigned long)), 1);
	else if (*format == '%')
		len += ft_putchr('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		re_ans;
	int		check;
	va_list	ap;

	re_ans = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			check = selection_percent(&ap, ++format);
			if (check == -1)
				return (0);
			else
				re_ans += check;
			format++;
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			re_ans += 1;
		}
	}
	va_end(ap);
	return (re_ans);
}
