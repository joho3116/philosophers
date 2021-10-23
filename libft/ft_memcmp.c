/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:39:10 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 19:31:59 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buffer_s1;
	unsigned char	*buffer_s2;
	size_t			i;

	buffer_s1 = (unsigned char *)s1;
	buffer_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (buffer_s1[i] != buffer_s2[i])
			return (buffer_s1[i] - buffer_s2[i]);
		i++;
	}
	return (0);
}
