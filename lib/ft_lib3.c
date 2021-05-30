/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:44:06 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/02/03 10:15:37 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_cnt(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_writespace(int nb, char c)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		i += ft_putchar_cnt(c);
		nb--;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putchar_cnt(str[i]);
		i++;
	}
	return (count);
}

int	ft_nbrlen(long int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i = 1;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
