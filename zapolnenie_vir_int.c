/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zapolnenie_vir_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:48:33 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:43:27 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zapolnenie_p_int(char *end, size_t len)
{
	while (len > 0)
	{
		*end = ' ';
		end++;
		len--;
	}
	return (end);
}

static char	*zapolnenie_t_int(char *end, size_t len)
{
	while (len > 0)
	{
		*end = '0';
		end++;
		len--;
	}
	return (end);
}

char	*esli_minus(char *nbr, char *end)
{
	if (*nbr == '-')
	{
		*end = *nbr;
		nbr++;
	}
	return (nbr);
}

char	*zapolnenie_vir_int(char *nbr, char *end, size_t len, t_flags var)
{
	char	*tmp;

	tmp = end;
	end[len] = '\0';
	nbr = esli_minus(nbr, end);
	if (var.plus > 0 && *end != '-')
		*end = '+';
	else if (var.probel > 0 && *end != '-')
		*end = ' ';
	if (*end == '-' || *end == '+' || *end == ' ')
	{
		end++;
		len--;
	}
	if (var.tochnost > ft_strlen(nbr))
	{
		end = zapolnenie_t_int(end, var.tochnost - ft_strlen(nbr));
		len = len - (var.tochnost - ft_strlen(nbr));
	}
	len = len - ft_strlcpy(end, nbr, ft_strlen(nbr) + 1);
	while (*end != '\0')
		end++;
	end = zapolnenie_p_int(end, len);
	return (tmp);
}
