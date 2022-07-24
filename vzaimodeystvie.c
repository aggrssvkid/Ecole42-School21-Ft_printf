/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vzaimodeystvie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:31:03 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:31:51 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	if_str(t_flags var)
{
	var.plus = 0;
	var.reshetka = 0;
	var.probel = 0;
	var.nuli = 0;
	return (var);
}

static t_flags	if_c_proc(t_flags var)
{
	var.plus = 0;
	var.reshetka = 0;
	var.tochnost = 0;
	var.probel = 0;
	var.nuli = 0;
	return (var);
}

static t_flags	if_nbr(char type, t_flags var)
{
	if (var.plus == 1 && var.probel == 1)
		var.probel = 0;
	if (type != 'x' && type != 'X')
		var.reshetka = 0;
	if (var.tochnost > 0)
		var.nuli = 0;
	if (var.viravnivanie > 0)
		var.nuli = 0;
	if (type == 'x' || type == 'X' || type == 'p')
		var.plus = 0;
	if (type == 'x' || type == 'X' || type == 'p')
		var.probel = 0;
	return (var);
}

t_flags	vzaimodeystvie(char *str, t_flags var)
{
	char	t;

	t = find_type(str);
	if (t == 'x' || t == 'X' || t == 'i' || t == 'd' || t == 'u')
		var = if_nbr(t, var);
	if (t == 'c' || t == '%')
		var = if_c_proc(var);
	if (t == 's')
		var = if_str(var);
	return (var);
}
