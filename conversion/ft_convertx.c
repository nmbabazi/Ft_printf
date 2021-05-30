/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:40:00 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:51:03 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_nbrlen_base(unsigned long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_caseaex(int *tab, unsigned int arg)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	nb = tab[1] - ft_nbrlen_base(arg);
	if (tab[0] == 2)
		i += ft_putnbr_base(arg, "0123456789abcdef");
	i += ft_writespace(nb, ' ');
	if (tab[0] == 0)
		i += ft_putnbr_base(arg, "0123456789abcdef");
	return (i);
}

int	ft_casebfx(int *tab, unsigned int arg)
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
	i += ft_putnbr_base(arg, "0123456789abcdef");
	if (tab[0] == 2)
		i += ft_writespace(nb, ' ');
	return (i);
}

int	ft_convertx(int *tab, va_list ap)
{
	unsigned int	arg;
	int				count;
	int				nb;

	arg = va_arg(ap, unsigned int);
	count = 0;
	if (arg == 0 && tab[2] == 1 && tab[3] == 0)
		count += ft_writespace(tab[1], ' ');
	if (tab[0] == 0 && tab[2] != 1)
		count += ft_caseaex(tab, arg);
	if (tab[0] != 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfx(tab, arg);
	if (tab[0] == 1 && tab[2] != 1)
	{
		nb = tab[1] - ft_nbrlen_base(arg);
		count += ft_writespace(nb, '0');
		count += ft_putnbr_base(arg, "0123456789abcdef");
	}
	if (tab[0] == 2 && tab[2] != 1)
		count += ft_caseaex(tab, arg);
	if (tab[0] == 2 && tab[2] == 1 && !(tab[3] == 0 && arg == 0))
		count += ft_casebfx(tab, arg);
	free(tab);
	return (count);
}
