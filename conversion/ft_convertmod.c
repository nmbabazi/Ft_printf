/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertmod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:39:01 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:49:05 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_convertmod(int *tab)
{
	int count;
	int nb;

	count = 0;
	if (tab[0] == 0)
	{
		nb = tab[1] - 1;
		count += ft_writespace(nb, ' ');
		count += ft_putchar_cnt('%');
	}
	if (tab[0] == 1)
	{
		nb = tab[1] - 1;
		count += ft_writespace(nb, '0');
		count += ft_putchar_cnt('%');
	}
	if (tab[0] == 2)
	{
		nb = tab[1] - 1;
		count += ft_putchar_cnt('%');
		count += ft_writespace(nb, ' ');
	}
	free(tab);
	return (count);
}
