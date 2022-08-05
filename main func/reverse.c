/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:34:47 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:21:55 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse(char *str)
{
	char	*end;
	char	*start;
	char	tmp;

	start = str;
	end = str + ft_strlen(str) - 1;
	while ((start != end) && (start != (end + 1)))
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
	return (str);
}
