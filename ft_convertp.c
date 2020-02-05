/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:39:17 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:50:11 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_cast(void *p)
{
	unsigned long long ptr;

	ptr = (unsigned long long)p;
	return (ptr);
}

int					ft_convertp(int *tab, va_list ap)
{
	void				*ptr;
	unsigned long long	arg;
	int					count;
	int					nb;

	ptr = va_arg(ap, void *);
	count = 0;
	arg = ft_cast(ptr);
	nb = tab[1] - ft_nbrlen_base(arg) - 2;
	if (tab[0] == 0 && tab[2] == 0)
	{
		count += ft_writespace(nb, ' ');
		count += ft_putchar_cnt('0');
		count += ft_putchar_cnt('x');
		count += ft_putnbr_base(arg, "0123456789abcdef");
	}
	if (tab[0] == 2 && tab[2] == 0)
	{
		count += ft_putchar_cnt('0');
		count += ft_putchar_cnt('x');
		count += ft_putnbr_base(arg, "0123456789abcdef");
		count += ft_writespace(nb, ' ');
	}
	free(tab);
	return (count);
}
