/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:43:54 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 17:14:51 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check(char *str)
{
	char	*r;
	char	*spec;

	spec = "cspdiuxX%";
	r = str;
	while (*r == '+' || *r == '-' || *r == '0' || *r == '#' || *r == ' ')
		r++;
	while (*r >= '0' && *r <= '9')
		r++;
	if (*r == '.')
		r++;
	while (*r >= '0' && *r <= '9')
		r++;
	while (*spec != '\0')
	{
		if (*r == *spec)
			return (r);
		spec++;
	}
	return (0);
}

char	*create_str(char *str)
{
	char	*end;
	char	*newstring;
	size_t	len;

	end = check(str);
	if (end == 0)
		return (0);
	len = end - str + 1;
	newstring = ft_strdup_len(str, len);
	if (newstring == 0)
		return (0);
	return (newstring);
}
