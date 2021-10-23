/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:54:11 by hojo              #+#    #+#             */
/*   Updated: 2020/10/15 02:51:54 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	s1_len;
	char	*buffer_s1;

	i = 0;
	s1_len = ft_strlen(s1);
	buffer_s1 = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!(buffer_s1))
		return (0);
	while (s1[i] != '\0')
	{
		buffer_s1[i] = s1[i];
		i++;
	}
	buffer_s1[i] = '\0';
	return (buffer_s1);
}
