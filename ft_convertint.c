/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:10:43 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/02/04 13:26:49 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_creatnb(int *tab, int len, int arg)
{
	int nb;

	nb = 0;
	if (tab[3] < len && tab[1] != 0)
		nb = tab[1] - len;
	if (tab[3] >= len && tab[1] != 0)
	{
		nb = tab[1] - tab[3];
		if (arg < 0)
			nb = nb - 1;
	}
	return (nb);
}

int	ft_casebf(int *tab, int arg)
{
	int nb;
	int i;
	int y;

	i = 0;
	y = 0;
	nb = 0;
	nb = ft_creatnb(tab, ft_nbrlen(arg), arg);
	if (tab[0] != 2)
		i += ft_writespace(nb, ' ');
	if (arg < 0 && tab[3] >= ft_nbrlen(arg))
	{
		arg = arg * -1;
		i += ft_putchar_cnt('-');
	}
	y = tab[3] - ft_nbrlen(arg);
	i += ft_writespace(y, '0');
	i += ft_putnbr(arg);
	if (tab[0] == 2)
		i += ft_writespace(nb, ' ');
	return (i);
}

int	ft_caseae(int *tab, int arg)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	nb = tab[1] - ft_nbrlen(arg);
	if (tab[0] == 2)
		i += ft_putnbr(arg);
	i += ft_writespace(nb, ' ');
	if (tab[0] == 0)
		i += ft_putnbr(arg);
	return (i);
}

int	ft_casec(int *tab, int arg)
{
	int nb;
	int i;

	i = 0;
	nb = tab[1] - ft_nbrlen(arg);
	if (arg < 0 && nb > 0)
	{
		arg = arg * -1;
		i += ft_putchar_cnt('-');
	}
	i += ft_writespace(nb, '0');
	i += ft_putnbr(arg);
	return (i);
}

int	ft_convertint(int *tab, va_list ap)
{
	int arg;
	int count;

	arg = va_arg(ap, int);
	count = 0;
	if (arg == 0 && tab[2] == 1 && tab[3] == 0)
		count += ft_writespace(tab[1], ' ');
	if (tab[0] == 0 && tab[2] != 1)
		count += ft_caseae(tab, arg);
	if (tab[0] != 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebf(tab, arg);
	if (tab[0] == 1 && tab[2] != 1)
		count += ft_casec(tab, arg);
	if (tab[0] == 2 && tab[2] != 1)
		count += ft_caseae(tab, arg);
	if (tab[0] == 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebf(tab, arg);
	free(tab);
	return (count);
}
