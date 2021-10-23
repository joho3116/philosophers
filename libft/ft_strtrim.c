/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:23:45 by hojo              #+#    #+#             */
/*   Updated: 2021/06/30 18:15:40 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prefix(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_suffix(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		prefix;
	int		suffix;
	char	*new_s1;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	prefix = ft_prefix(s1, set);
	suffix = ft_suffix(s1, set);
	if (prefix >= suffix)
		return (ft_strdup(""));
	new_s1 = (char *)malloc(sizeof(char) * (suffix - prefix + 1));
	if (new_s1 == 0)
		return (0);
	ft_strlcpy(new_s1, s1 + prefix, suffix - prefix + 1);
	return (new_s1);
}
