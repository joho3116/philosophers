/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:52:24 by hojo              #+#    #+#             */
/*   Updated: 2021/06/30 18:17:24 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*buffer_s1;
	unsigned char	*buffer_s2;

	buffer_s1 = (unsigned char *)s1;
	buffer_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if ((buffer_s1[i] != buffer_s2[i])
			|| (buffer_s1[i] == 0) || (buffer_s2[i] == 0))
			return (buffer_s1[i] - buffer_s2[i]);
		i++;
	}
	return (0);
}
