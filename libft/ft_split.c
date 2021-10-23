/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:08:04 by hojo              #+#    #+#             */
/*   Updated: 2021/08/21 18:59:44 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(char **strs)
{
	size_t			i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static	size_t	get_delimeter(char *s, char c)
{
	size_t			i;
	size_t			c_count;

	i = 0;
	c_count = 0;
	while (s[i])
	{
		if (s[i] != c)
			++c_count;
		while (s[i] != c && s[i + 1] != 0)
			++i;
		++i;
	}
	return (c_count);
}

static	int	get_str_len(char *s, char c)
{
	size_t			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*temp;
	size_t	delimeter;
	size_t	strs_i;
	int		next;

	temp = (char *)s;
	delimeter = get_delimeter(temp, c);
	strs = (char **)malloc(sizeof(char *) * (delimeter + 1));
	if (!strs)
		return (NULL);
	strs_i = -1;
	while (++strs_i < delimeter)
	{
		while (temp && *temp == c)
			temp++;
		next = get_str_len(temp, c);
		strs[strs_i] = (char *)malloc(sizeof(char) * (next + 1));
		if (!strs[strs_i])
			return (ft_free(strs));
		ft_strlcpy(strs[strs_i], temp, next + 1);
		temp = temp + next;
	}
	strs[strs_i] = 0;
	return (strs);
}
