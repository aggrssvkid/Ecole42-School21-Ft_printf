/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dosth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:01:23 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 18:49:21 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../ft_printf.h"

static size_t	end_output(va_list arg, char type, t_flags var)
{
	char	*end_str;
	size_t	len;

	if (type == 'd' || type == 'i')
		end_str = len_if_int(arg, var);
	if (type == 'u' || type == 'x' || type == 'X' || type == 'p')
		end_str = len_if_un_int(arg, var, type);
	if (type == 'c' || type == '%')
		end_str = len_if_char(arg, var, type);
	if (type == 's')
		end_str = len_if_str(arg, var);
	if (end_str == 0)
		return (0);
	len = ft_strlen(end_str);
	if (type == 'c' && var.shirina > len)
		len = var.shirina;
	else if (type == 'c' && end_str[0] == '\0')
		len++;
	write(1, end_str, len);
	free(end_str);
	return (len);
}

size_t	len_output(char *str, va_list arg)
{
	size_t	a;
	char	type;
	t_flags	var;

	var.reshetka = 0;
	a = 0;
	type = find_type(str);
	var = flags_init(var, type);
	var = analyze(str, var);
	a = end_output(arg, type, var);
	return (a);
}
