/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:04:45 by hojo              #+#    #+#             */
/*   Updated: 2021/06/30 18:17:47 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*buffer_dest;
	unsigned char	*buffer_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	buffer_dest = dest;
	buffer_src = (unsigned char *) src;
	i = 0;
	while (i++ < n)
		*buffer_dest++ = *buffer_src++;
	return (dest);
}
