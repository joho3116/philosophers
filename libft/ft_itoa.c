/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:08:55 by hojo              #+#    #+#             */
/*   Updated: 2021/06/30 18:07:50 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	ft_int_len(int i)
{
	int	len;

	if (i <= 0)
		len = 1;
	else
		len = 0;
	while (i != 0)
	{
		i = (i / 10);
		len++;
	}
	return (len);
}

char	*ft_itoa(int i)
{
	int		sign;
	int		len;
	char	*a;

	if (i < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_int_len(i);
	a = (char *)malloc(sizeof(char) * len + 1);
	if (a == 0)
		return (NULL);
	a[len] = '\0';
	while (--len >= 0)
	{
		a[len] = '0' + ft_abs(i % 10);
		i = ft_abs(i / 10);
	}
	if (sign == -1)
		a[0] = '-';
	return (a);
}
