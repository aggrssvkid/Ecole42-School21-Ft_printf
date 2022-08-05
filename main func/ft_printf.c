/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:21:20 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 17:46:52 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lishnyaya_stroka(const char *format)
{
	if (*format != '%')
		write(1, format, 1);
}

int	ft_printf(const char *format, ...)
{
	size_t	num;
	va_list	arg;
	char	*find;

	num = 0;
	va_start(arg, format);
	while (*format != '\0')
	{
		lishnyaya_stroka(format);
		if (*format == '%')
		{
			format++;
			find = create_str((char *) format);
			if (find != 0)
			{
				num = num + len_output(find, arg) - 1;
				format = format + ft_strlen(find) - 1;
			}
			free(find);
		}
		num++;
		format++;
	}
	va_end(arg);
	return ((int) num);
}
