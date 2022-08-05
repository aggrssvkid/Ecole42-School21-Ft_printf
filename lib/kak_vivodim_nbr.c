/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kak_zapolnim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:42:21 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 18:13:00 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*kak_vivodim_nbr(char *nbr, char *end, size_t len, t_flags var)
{
	if (var.pomoyka == 1 && *nbr == '0')
	{
		*nbr = '\0';
		len = var.shirina;
	}
	if (var.viravnivanie > 0)
		end = zapolnenie_vir_int(nbr, end, len, var);
	if (var.viravnivanie == 0)
		end = zapolnim_novir_int(nbr, end, len, var);
	if (var.reshetka > 0 && *nbr != '0')
		end = modern_string(end, var);
	free(nbr);
	return (end);
}
