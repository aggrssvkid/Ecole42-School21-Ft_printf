/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_if_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:44:55 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 18:26:51 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*if_null_str(void)
{
	char	*str;
	char	*nu;

	nu = "(null)";
	str = malloc (7 * 1);
	ft_strlcpy(str, nu, 7);
	return (str);
}

static char	*probeli(char *end, size_t len)
{
	char	*runman;

	runman = end + ft_strlen(end);
	while (len > 0)
	{
		*runman = ' ';
		runman++;
		len--;
	}
	return (end);
}

static char	*zapolnenie(char *duplicate, size_t len, t_flags var)
{
	char	*end;
	char	*runman;
	size_t	tmp;

	end = malloc((len + 1) * sizeof(char));
	if (end == 0)
		return (0);
	end[len] = '\0';
	tmp = ft_strlcpy(end, duplicate, var.tochnost + 1);
	tmp = len;
	len = len - ft_strlen(end);
	if (len > 0)
		end = probeli(end, len);
	if (var.viravnivanie == 0 && tmp == var.shirina)
	{
		end = reverse(end);
		runman = end;
		while (*runman == ' ')
			runman++;
		runman = reverse(runman);
	}
	return (end);
}

static size_t	end_len(size_t len, t_flags var)
{
	if (var.tochnost < len)
	{
		if (var.tochnost > var.shirina)
			len = var.tochnost;
		else
			len = var.shirina;
	}
	return (len);
}

char	*len_if_str(va_list arg, t_flags var)
{
	char	*end;
	char	*duplicate;
	char	*argstr;
	size_t	len;

	argstr = va_arg(arg, char *);
	if (argstr == 0)
		duplicate = if_null_str();
	else
		duplicate = ft_strdup(argstr);
	if (duplicate == 0)
		return (0);
	len = ft_strlen(duplicate);
	if (var.tochnost > len)
	{
		var.tochnost = len;
		if (var.shirina > len)
			len = var.shirina;
	}
	len = end_len(len, var);
	end = zapolnenie(duplicate, len, var);
	free(duplicate);
	if (end == 0)
		return (0);
	return (end);
}
