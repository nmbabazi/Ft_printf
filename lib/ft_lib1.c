/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:32:57 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:47:26 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
					|| str[i] == '\f' || str[i] == 32) && str[i])
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	free(str);
	return (nb * sign);
}

int		ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_cnt('-');
		nbr = nb * (-1);
	}
	else
		nbr = nb;
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar_cnt(nbr % 10 + 48);
	return (count);
}

int		ft_putnbrunsigned(unsigned int nb)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	nbr = nb;
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar_cnt(nbr % 10 + 48);
	return (count);
}

int		ft_putnbr_base(unsigned long long nbr, char *base)
{
	unsigned int	length;
	unsigned int	j;
	int				count;

	length = 0;
	count = 0;
	while (base[length])
	{
		if (base[length] < 32)
			return (count);
		if (base[length] == '+' || base[length] == '-')
			return (count);
		j = length;
		while (base[++j])
			if (base[length] == base[j])
				return (count);
		length++;
	}
	if (length <= 1)
		return (count);
	if (nbr >= length)
		count += ft_putnbr_base(nbr / length, base);
	count += write(1, &base[nbr % length], 1);
	return (count);
}

int		*ft_createtab(int *tab)
{
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 4)
		tab[i++] = 0;
	return (tab);
}
