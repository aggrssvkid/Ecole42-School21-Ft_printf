/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:58:40 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 17:03:06 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	analzero(char *str, t_flags var)
{
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '9')
		{
			var.nuli = 0;
			return (var);
		}
		if (*str == '0')
		{
			var.nuli = 1;
			return (var);
		}
		str++;
	}
	return (var);
}

static t_flags	analyze_param_t(char *str, t_flags var)
{
	char	*runman;

	runman = str;
	while ((*runman != '\0') && (*runman != '.'))
		runman++;
	if (*runman == '\0')
		return (var);
	else
	{
		runman++;
		while (*runman == '0')
			runman++;
		if (*runman < '0' || *runman > '9')
			var.pomoyka = 1;
	}
	var.tochnost = ft_atoi(runman);
	return (var);
}

static t_flags	analyze_param_s(char *str, t_flags var)
{
	char	*runman;
	char	*find;

	runman = str;
	find = str;
	while (*runman != '\0' && *runman != '.')
		runman++;
	while (find != runman)
	{
		if (*find > '0' && *find <= '9')
		{
			var.shirina = ft_atoi(find);
			return (var);
		}
		find++;
	}
	var.shirina = 0;
	return (var);
}

static t_flags	analyze_flags(char *str, t_flags var)
{
	char	*tmp;

	tmp = str;
	tmp = ft_strchr(tmp, '#');
	if (tmp != 0)
		var.reshetka = 1;
	tmp = str;
	tmp = ft_strchr(tmp, '+');
	if (tmp != 0)
		var.plus = 1;
	tmp = str;
	tmp = ft_strchr(tmp, '-');
	if (tmp != 0)
		var.viravnivanie = 1;
	tmp = str;
	tmp = ft_strchr(tmp, ' ');
	if (tmp != 0)
		var.probel = 1;
	tmp = str;
	var = analzero(tmp, var);
	return (var);
}

t_flags	analyze(char *str, t_flags var)
{
	var = analyze_flags(str, var);
	var = analyze_param_s(str, var);
	var = analyze_param_t(str, var);
	var = vzaimodeystvie(str, var);
	return (var);
}
