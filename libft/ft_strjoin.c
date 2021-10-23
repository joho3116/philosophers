/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:44:48 by hojo              #+#    #+#             */
/*   Updated: 2020/10/16 17:13:58 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstring)
		return (0);
	ft_strlcpy(newstring, s1, s1_len + 1);
	ft_strlcat(newstring + s1_len, s2, s2_len + 1);
	return (newstring);
}
