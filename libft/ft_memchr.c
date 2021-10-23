/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:21:13 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 20:48:18 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*buffer_b;
	unsigned char	buffer_c;
	size_t			i;

	buffer_b = (unsigned char *)b;
	buffer_c = c;
	i = 0;
	while (i < n)
	{
		if (buffer_b[i] == buffer_c)
			return (buffer_b + i);
		i++;
	}
	return (0);
}
