/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:18:24 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/08 16:01:35 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_finish(t_philo *p, int *is_finish)
{
	int	i;

	i = 0;
	while (i < p->info->i_philo)
	{
		if (is_finish[i] == 0)
			return (0);
		i++;
	}
	print_msg(p, END);
	return (1);
}

int	is_dead(t_philo *p)
{
	if (p->info->die <= get_time() - p->eat_time)
	{
		print_msg(p, DEAD);
		return (1);
	}
	return (0);
}

void	check_philo_alive(t_philo *p, t_info *info)
{
	int		*finish;
	int		i;

	finish = ft_calloc(info->i_philo, sizeof(int));
	i = 0;
	while (1)
	{
		if (i == info->i_philo)
			i = 0;
		if (is_dead(&p[i]))
			break ;
		if (info->time_eat && p[i].count_eat >= info->time_eat)
			finish[i]++;
		if (is_finish(&p[i], finish))
			break ;
		i++;
	}
	free(finish);
}
