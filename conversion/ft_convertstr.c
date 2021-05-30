/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:39:29 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:50:28 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_arglen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_stateae(int *tab, char *arg)
{
	int nb;
	int i;

	i = 0;
	nb = tab[1] - ft_arglen(arg);
	if (tab[0] == 2)
		i += ft_putstr(arg);
	i += ft_writespace(nb, ' ');
	if (tab[0] == 0)
		i += ft_putstr(arg);
	return (i);
}

int	ft_statebf(int *tab, char *arg)
{
	int nb;
	int i;
	int b;

	i = 0;
	nb = 0;
	b = 0;
	if (tab[3] >= ft_arglen(arg))
		nb = tab[1] - ft_arglen(arg);
	if (tab[3] < ft_arglen(arg))
		nb = tab[1] - tab[3];
	if (tab[0] == 0)
		i += ft_writespace(nb, ' ');
	while (tab[3] > 0 && arg[b])
	{
		i += ft_putchar_cnt(arg[b]);
		tab[3]--;
		b++;
	}
	if (tab[0] == 2)
		i += ft_writespace(nb, ' ');
	return (i);
}

int	ft_convertstr(int *tab, va_list ap)
{
	char	*arg;
	int		count;

	count = 0;
	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = ft_substr("(null)", 0, 7);
	if (tab[0] == 0 && tab[2] != 1)
		count += ft_stateae(tab, arg);
	if (tab[0] == 0 && tab[2] == 1)
		count += ft_statebf(tab, arg);
	if (tab[0] == 2 && tab[2] != 1)
		count += ft_stateae(tab, arg);
	if (tab[0] == 2 && tab[2] == 1)
		count += ft_statebf(tab, arg);
	free(tab);
	return (count);
}
