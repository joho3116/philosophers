/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:51:41 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 22:13:58 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*buffer_dest;
	unsigned char	*buffer_src;
	unsigned char	search;
	size_t			i;

	buffer_dest = dest;
	buffer_src = (unsigned char *)src;
	search = c;
	i = 0;
	while (i < n)
	{
		buffer_dest[i] = buffer_src[i];
		if (buffer_src[i] == search)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
