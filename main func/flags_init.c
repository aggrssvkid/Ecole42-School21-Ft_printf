/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_param_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:04:24 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 17:18:46 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	flags_init(t_flags var, char type)
{
	var.reshetka = 0;
	var.plus = 0;
	var.viravnivanie = 0;
	var.probel = 0;
	var.nuli = 0;
	var.shirina = 0;
	var.tochnost = 0;
	var.pomoyka = 0;
	if (type == 's')
		var.tochnost = 2147483647;
	return (var);
}
