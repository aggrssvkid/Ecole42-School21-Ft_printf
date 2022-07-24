/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_if_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:41:17 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 18:18:36 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*len_if_int(va_list arg, t_flags var)
{
	char	*nbr;
	size_t	len;
	char	*end;

	nbr = ft_itoa(va_arg(arg, int));
	if (nbr == 0)
		return (0);
	len = ft_strlen(nbr);
	if (var.shirina > len && var.shirina > var.tochnost)
		len = var.shirina;
	if (var.tochnost > len)
		len = var.tochnost;
	if (len == var.tochnost && (*nbr == '-' || var.probel > 0 || var.plus > 0))
		len++;
	else if (len != var.shirina && len != var.tochnost)
		if (*nbr != '-' && (var.probel > 0 || var.plus > 0))
			len++;
	end = malloc((len + 1) * sizeof (char));
	if (end == 0)
	{
		free(nbr);
		return (0);
	}
	end = kak_vivodim_nbr(nbr, end, len, var);
	return (end);
}
