/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:37:40 by enoye             #+#    #+#             */
/*   Updated: 2021/11/03 20:22:48 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct flags
{
	size_t	reshetka;
	size_t	plus;
	size_t	viravnivanie;
	size_t	probel;
	size_t	nuli;
	size_t	shirina;
	size_t	tochnost;
	int		pomoyka;

}	t_flags;

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);
t_flags		analyze(char *str, t_flags var);
t_flags		vzaimodeystvie(char *str, t_flags var);
t_flags		flags_init(t_flags var, char type);
char		*create_str(char *str);
char		find_type(char *correctstr);
char		*ft_itoa(int n);
size_t		len_output(char *str, va_list arg);
char		*len_if_int(va_list arg, t_flags var);
char		*zapolnenie_vir_int(char *nbr, char *end, size_t len, t_flags var);
char		*zapolnim_novir_int(char *nbr, char *end, size_t len, t_flags var);
int			ft_printf(const char *format, ...);
char		*len_if_un_int(va_list arg, t_flags var, char type);
char		*ft_strdup_len(const char *s1, size_t len);
char		*ten_to_sixteen(unsigned int n);
char		*up_symbols(char *str);
char		*modern_string(char *end, t_flags var);
char		*len_if_char(va_list arg, t_flags var, char type);
char		*reverse(char *str);
char		*len_if_str(va_list arg, t_flags var);
char		*ft_itoa_unsigned_l(unsigned long long n, char type);
char		*ft_itoa_uten(unsigned int n, char type);
char		*ten_to_sixteen_ll(unsigned long long int n);
char		*kak_vivodim_nbr(char *nbr, char *end, size_t len, t_flags var);

#endif
