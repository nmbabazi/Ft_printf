/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:42:00 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/02/03 10:16:11 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_flagcheck(const char *str, int *z);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_arglen(char *str);
size_t	ft_strlen(const char *str);
int		ft_putchar_cnt(const char c);
int		ft_atoi(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long long nbr, char *base);
int		ft_putnbrunsigned(unsigned int nb);
int		ft_putstr(char *str);
int		ft_nbrlen(long int nb);
int		ft_nbrlenunsigned(unsigned int nb);
int		ft_nbrlen_base(unsigned long long nb);
int		ft_convertint(int *tab, va_list ap);
int		ft_convertu(int *tab, va_list ap);
int		ft_convertmod(int *tab);
int		ft_convertchar(int *tab, va_list ap);
int		ft_convertstr(int *tab, va_list ap);
int		ft_convertx(int *tab, va_list ap);
int		ft_convertxup(int *tab, va_list ap);
int		ft_convertp(int *tab, va_list ap);
int		ft_longueur(int *tab, va_list ap, char *str, int n);
int		ft_isflag(const char *fmt, va_list ap, int *count);
int		*ft_createtab(int *tab);
int		ft_writespace(int nb, char c);
int		ft_creatnbun(int *tab, int len);

#endif
