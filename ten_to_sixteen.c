/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_to_sixteen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:57:41 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 19:24:21 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zapolnim(char *str, unsigned int n, int size)
{
	char	*digits;
	char	*zapolnitel;

	digits = "0123456789abcdef";
	str[size] = '\0';
	zapolnitel = str + size - 1;
	while (size > 0)
	{
		*zapolnitel = *(digits + n % 16);
		n = n / 16;
		size--;
		zapolnitel--;
	}
	return (str);
}

static int	getsize_sixteen(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 16 != 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

char	*ten_to_sixteen(unsigned int n)
{
	char	*str;
	int		size;

	size = getsize_sixteen(n);
	str = malloc((size + 1) * sizeof (char));
	if (str == 0)
		return (0);
	str = zapolnim(str, n, size);
	return (str);
}
