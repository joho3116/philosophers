/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:34:13 by hojo              #+#    #+#             */
/*   Updated: 2020/10/14 21:28:53 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer_s;
	char	buffer_c;
	int		i;

	buffer_s = (char *)s;
	buffer_c = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (buffer_s[i] == buffer_c)
			return (buffer_s + i);
		i--;
	}
	if (buffer_s[i] == buffer_c)
		return (buffer_s);
	return (0);
}
