/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:11:00 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/07 15:12:54 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	print_error(int err_num)
{
	if (err_num == ARG_ERR)
		printf("Argment Error.");
	else if (err_num == DUP_ERR)
		printf("Malloc Error.");
	return (0);
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_msleep(time_t ms)
{
	const time_t	base = get_time();

	while (1)
	{
		if (ms < get_time() - base)
			return ;
		usleep(100);
	}
}
