/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertxup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:40:10 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:50:54 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_caseaexup(int *tab, unsigned int arg)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	nb = tab[1] - ft_nbrlen_base(arg);
	if (tab[0] == 2)
		i += ft_putnbr_base(arg, "0123456789ABCDEF");
	i += ft_writespace(nb, ' ');
	if (tab[0] == 0)
		i += ft_putnbr_base(arg, "0123456789ABCDEF");
	return (i);
}

int	ft_casebfxup(int *tab, unsigned int arg)
{
	int nb;
	int i;
	int y;

	i = 0;
	y = tab[3] - ft_nbrlen_base(arg);
	nb = 0;
	nb = ft_creatnbun(tab, ft_nbrlen_base(arg));
	if (tab[0] != 2)
		i += ft_writespace(nb, ' ');
	i += ft_writespace(y, '0');
	i += ft_putnbr_base(arg, "0123456789ABCDEF");
	if (tab[0] == 2)
		i += ft_writespace(nb, ' ');
	return (i);
}

int	ft_convertxup(int *tab, va_list ap)
{
	unsigned int	arg;
	int				count;
	int				nb;

	arg = va_arg(ap, unsigned int);
	count = 0;
	if (arg == 0 && tab[2] == 1 && tab[3] == 0)
		count += ft_writespace(tab[1], ' ');
	if (tab[0] == 0 && tab[2] != 1)
		count += ft_caseaexup(tab, arg);
	if (tab[0] != 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfxup(tab, arg);
	if (tab[0] == 1 && tab[2] != 1)
	{
		nb = tab[1] - ft_nbrlen_base(arg);
		count += ft_writespace(nb, '0');
		count += ft_putnbr_base(arg, "0123456789ABCDEF");
	}
	if (tab[0] == 2 && tab[2] != 1)
		count += ft_caseaexup(tab, arg);
	if (tab[0] == 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfxup(tab, arg);
	free(tab);
	return (count);
}
