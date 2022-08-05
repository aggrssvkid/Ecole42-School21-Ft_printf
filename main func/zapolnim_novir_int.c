/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zapolnim_novir_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:28:05 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:54:43 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*correct(char	*end)
{
	char	*tmp;

	tmp = end;
	while (*tmp == ' ')
	{
		*tmp = '0';
		tmp++;
	}
	if (*tmp == '-')
	{
		*tmp = '0';
		end[0] = '-';
	}
	return (end);
}

char	*zapolnim_novir_int(char *nbr, char *end, size_t len, t_flags var)
{
	char	*tmp;

	tmp = end;
	tmp = zapolnenie_vir_int(nbr, end, len, var);
	if (var.shirina == len)
	{
		tmp = reverse(tmp);
		while (*tmp == ' ')
			tmp++;
		tmp = reverse(tmp);
	}
	if (var.nuli > 0 && (var.tochnost == len || var.shirina == len))
	{
		if (var.pomoyka != 1)
			end = correct(end);
	}
	return (end);
}
