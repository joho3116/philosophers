/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:57:01 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 20:44:34 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*buffer_dest;
	unsigned char	*buffer_src;

	if (dest == src || len == 0)
		return (dest);
	if (dest < src)
	{
		buffer_dest = (unsigned char *)dest;
		buffer_src = (unsigned char *)src;
		while (len--)
			*buffer_dest++ = *buffer_src++;
	}
	else
	{
		buffer_dest = dest + (len - 1);
		buffer_src = (unsigned char *)src + (len - 1);
		while (len--)
			*buffer_dest-- = *buffer_src--;
	}
	return (dest);
}
