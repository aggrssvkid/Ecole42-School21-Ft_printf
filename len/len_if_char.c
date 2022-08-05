/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_if_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:22:23 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 18:15:50 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*probeli(char *str, size_t len)
{
	char	*runman;

	runman = str;
	str[len] = '\0';
	while (len > 0)
	{
		*runman = ' ';
		runman++;
		len--;
	}
	return (str);
}

char	*len_if_char(va_list arg, t_flags var, char type)
{
	char	*end;
	size_t	len;

	len = 1;
	if (var.shirina > 1)
		len = var.shirina;
	end = malloc ((len + 1) * sizeof (char));
	if (end == 0)
		return (0);
	end = probeli(end, len);
	if (type == 'c')
	{
		if (var.viravnivanie == 0)
			end[len - 1] = va_arg(arg, int);
		else
			end[0] = va_arg(arg, int);
	}
	if (type == '%')
	{
		if (var.viravnivanie == 0)
			end[len - 1] = '%';
		else
			end[0] = '%';
	}
	return (end);
}
