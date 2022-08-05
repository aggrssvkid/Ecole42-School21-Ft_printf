/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_if_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:41:17 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 20:41:43 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	end_len(char *nbr, t_flags var)
{
	size_t	len;

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
	return (len);
}

char	*len_if_un_int(va_list arg, t_flags var, char type)
{
	char	*nbr;
	size_t	len;
	char	*end;

	if (type == 'p')
		nbr = ten_to_sixteen_ll(va_arg(arg, unsigned long long));
	if (type != 'p')
		nbr = ft_itoa_uten(va_arg(arg, unsigned long int), type);
	if (nbr == 0)
		return (0);
	len = end_len(nbr, var);
	end = malloc((len + 1) * sizeof (char));
	if (end == 0)
	{
		free(nbr);
		return (0);
	}
	end = kak_vivodim_nbr(nbr, end, len, var);
	if (type == 'p')
		end = modern_string(end, var);
	if (type == 'X')
		end = up_symbols(end);
	return (end);
}
