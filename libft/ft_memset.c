/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:24:36 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 19:31:01 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*buffer;
	unsigned char	src;
	size_t			i;

	buffer = dest;
	src = c;
	i = 0;
	while (i < n)
	{
		buffer[i] = src;
		i++;
	}
	return (buffer);
}
