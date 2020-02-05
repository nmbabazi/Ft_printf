/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:38:32 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:48:40 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convertchar(int *tab, va_list ap)
{
	int arg;
	int count;
	int nb;

	count = 0;
	nb = 0;
	arg = va_arg(ap, int);
	if (tab[0] == 0 && tab[2] != 1)
	{
		nb = tab[1] - 1;
		count += ft_writespace(nb, ' ');
		count += ft_putchar_cnt(arg);
	}
	if (tab[0] == 2 && tab[2] != 1)
	{
		nb = tab[1] - 1;
		count += ft_putchar_cnt(arg);
		count += ft_writespace(nb, ' ');
	}
	free(tab);
	return (count);
}
