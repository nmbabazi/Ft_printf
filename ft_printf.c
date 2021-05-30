/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:04:21 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/02/04 13:22:41 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

void	ft_converter(int *tab, char *str, va_list ap, int *count)
{
	int i;

	i = 0;
	while (str[i + 1])
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		*count += ft_convertint(tab, ap);
	if (str[i] == 's')
		*count += ft_convertstr(tab, ap);
	if (str[i] == 'c')
		*count += ft_convertchar(tab, ap);
	if (str[i] == '%')
		*count += ft_convertmod(tab);
	if (str[i] == 'u')
		*count += ft_convertu(tab, ap);
	if (str[i] == 'x')
		*count += ft_convertx(tab, ap);
	if (str[i] == 'X')
		*count += ft_convertxup(tab, ap);
	if (str[i] == 'p')
		*count += ft_convertp(tab, ap);
}

int		ft_longueur(int *tab, va_list ap, char *str, int n)
{
	int z;
	int i;

	z = 0;
	i = 0;
	if (str[i] == '*')
	{
		tab[n] = va_arg(ap, int);
		i++;
		if (tab[n] < 0)
		{
			tab[n] *= -1;
			tab[n - 1] = 2;
		}
	}
	else if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i++]) == 1)
			z++;
		tab[n] = ft_atoi(ft_substr(&str[--i - z], 0, z));
	}
	return (i);
}

void	ft_codeflag(char *str, va_list ap, int *count)
{
	int i;
	int *tab;

	i = 0;
	tab = NULL;
	tab = ft_createtab(tab);
	if (str[i] == '0')
		tab[0] = 1;
	if (str[i] == '-')
		tab[0] = 2;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			tab[0] = 2;
		i++;
	}
	if (ft_isdigit(str[i]) == 1 || str[i] == '*')
		i += ft_longueur(tab, ap, &str[i], 1);
	if (str[i++] == '.')
		tab[2] = 1;
	if (ft_isdigit(str[i]) == 1 || str[i] == '*')
		i += ft_longueur(tab, ap, &str[i], 3);
	ft_converter(tab, str, ap, count);
	return ;
}

int		ft_isflag(const char *fmt, va_list ap, int *count)
{
	char	*str;
	int		z;

	z = 0;
	if (ft_flagcheck(fmt, &z) == 1)
	{
		str = ft_substr(fmt, 1, z);
		ft_codeflag(str, ap, count);
	}
	else
	{
		z = 0;
		str = NULL;
	}
	free(str);
	return (z);
}

int		ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			count += ft_putchar_cnt(fmt[i]);
		if (fmt[i] == '%' && fmt[i + 1])
			i += ft_isflag(&fmt[i], ap, &count);
		i++;
	}
	return (count);
}
