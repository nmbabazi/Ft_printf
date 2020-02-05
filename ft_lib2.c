/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:33:53 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/01/31 17:47:35 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '%')
		return (1);
	return (0);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_flagcheck(const char *str, int *z)
{
	int i;

	i = 1;
	while (str[i] && ft_isalpha(str[i]) == 0)
		i++;
	*z = i;
	if (str[i] && (str[i] == 'd' || str[i] == 'c' || str[i] == 's'
		|| str[i] == 'p' || str[i] == 'i' || str[i] == 'u'
		|| str[i] == 'x' || str[i] == 'X' || str[i] == '%'))
	{
		return (1);
	}
	else
		return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	char	*call;

	i = 0;
	call = "\0";
	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (call);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
