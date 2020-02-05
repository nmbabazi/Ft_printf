/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:39:45 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:50:40 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlenunsigned(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_caseaeun(int *tab, unsigned int arg)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	nb = tab[1] - ft_nbrlenunsigned(arg);
	if (tab[0] == 2)
		i += ft_putnbrunsigned(arg);
	i += ft_writespace(nb, ' ');
	if (tab[0] == 0)
		i += ft_putnbrunsigned(arg);
	return (i);
}

int	ft_creatnbun(int *tab, int len)
{
	int nb;

	nb = 0;
	if (tab[3] <= len)
		nb = tab[1] - len;
	if (tab[3] > len)
		nb = tab[1] - tab[3];
	return (nb);
}

int	ft_casebfun(int *tab, unsigned int arg)
{
	int nb;
	int i;
	int y;

	i = 0;
	y = tab[3] - ft_nbrlenunsigned(arg);
	nb = 0;
	nb = ft_creatnbun(tab, ft_nbrlenunsigned(arg));
	if (tab[0] != 2)
		i += ft_writespace(nb, ' ');
	i += ft_writespace(y, '0');
	i += ft_putnbrunsigned(arg);
	if (tab[0] == 2)
		i += ft_writespace(nb, ' ');
	return (i);
}

int	ft_convertu(int *tab, va_list ap)
{
	unsigned int	arg;
	int				count;
	int				nb;

	arg = va_arg(ap, unsigned int);
	count = 0;
	if (arg == 0 && tab[2] == 1 && tab[3] == 0)
		count += ft_writespace(tab[1], ' ');
	if (tab[0] == 0 && tab[2] != 1)
		count += ft_caseaeun(tab, arg);
	if (tab[0] != 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfun(tab, arg);
	if (tab[0] == 1 && tab[2] != 1)
	{
		nb = tab[1] - ft_nbrlenunsigned(arg);
		count += ft_writespace(nb, '0');
		count += ft_putnbrunsigned(arg);
	}
	if (tab[0] == 2 && tab[2] != 1)
		count += ft_caseaeun(tab, arg);
	if (tab[0] == 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfun(tab, arg);
	free(tab);
	return (count);
}
