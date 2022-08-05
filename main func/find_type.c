/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:15:48 by enoye             #+#    #+#             */
/*   Updated: 2021/10/26 14:16:51 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	find_type(char *correctstr)
{
	char	type;

	type = *(correctstr + ft_strlen(correctstr) - 1);
	return (type);
}
