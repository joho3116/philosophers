/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:16:45 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 19:32:13 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	buffer_c;
	int		i;

	buffer_c = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == buffer_c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == buffer_c)
		return ((char *)s + i);
	return (0);
}
