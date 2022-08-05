/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:52:39 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 17:35:40 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../ft_printf.h"

static char	*zapolnyaem(char *string, int len, unsigned int n)
{
	string = string + len - 1;
	while (n != 0)
	{
		*string = '0' + (n % 10);
		string--;
		n = n / 10;
	}
	if (string[0] != '-')
		string++;
	return (string);
}

static int	getlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*getmemoryxd(char *str, unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{	
		size++;
		n = n / 10;
	}
	str = malloc ((size + 1) * 1);
	if (str == 0)
		return (0);
	str[size] = '\0';
	return (str);
}

char	*ft_itoa_uten(unsigned int n, char type)
{
	char	*string;
	char	a;
	int		len;

	if (type == 'u')
	{
		string = &a;
		string = getmemoryxd(string, n);
		if (string == 0)
			return (0);
		if (n == 0)
		{	
			*string = '0';
			return (string);
		}
		len = getlen(n);
		string = zapolnyaem(string, len, n);
	}
	if (type == 'x' || type == 'X')
		string = ten_to_sixteen(n);
	return (string);
}
