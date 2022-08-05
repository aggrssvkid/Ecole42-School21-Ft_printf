/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:46:20 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:20:58 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	find_probels(char *str, t_flags var)
{
	size_t	nofp;
	char	*tmp;

	nofp = 0;
	if (var.viravnivanie > 0)
	{
		tmp = str + ft_strlen(str) - 1;
		while (*tmp == ' ' && nofp < 2)
		{
			nofp++;
			tmp--;
		}
	}
	else if (var.viravnivanie == 0)
	{
		tmp = str;
		while (*tmp == ' ' && nofp < 2)
		{
			nofp++;
			tmp++;
		}
	}
	return (nofp);
}

static char	*dva(char *str, t_flags var)
{
	char	*tmp;

	tmp = str;
	if (var.viravnivanie == 0)
	{
		while (*tmp == ' ')
			tmp++;
		*(tmp - 1) = 'x';
		*(tmp - 2) = '0';
	}
	else if (var.viravnivanie > 0)
	{
		while (*tmp != ' ')
			tmp++;
		while (tmp != str)
		{
			*(tmp + 1) = *(tmp - 1);
			tmp--;
		}
		*tmp = '0';
		*(tmp + 1) = 'x';
	}
	return (str);
}

static char	*new(char *str, int nofp)
{
	char	*newstr;
	char	*runman;
	char	*tmp;

	newstr = malloc((ft_strlen(str) + 3 - nofp) * sizeof (char));
	if (newstr == 0)
		return (0);
	*newstr = '0';
	*(newstr + 1) = 'x';
	runman = newstr + 2;
	tmp = str;
	while (*tmp == ' ')
		tmp++;
	while (*tmp != '\0')
	{
		*runman = *tmp;
		runman++;
		tmp++;
	}
	*runman = '\0';
	free(str);
	return (newstr);
}

char	*modern_string(char *end, t_flags var)
{
	size_t		nofp;
	char		*tmp;

	nofp = find_probels(end, var);
	if (nofp == 2)
		end = dva(end, var);
	else
	{
		tmp = new(end, nofp);
		if (tmp == 0)
		{
			free(end);
			return (0);
		}
		return (tmp);
	}
	return (end);
}
