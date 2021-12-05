/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:18:24 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/30 21:19:26 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"

int	is_check(t_philo *p)
{
	int	i;

	i = 0;
	while (i < g_info.i_philo)
	{
		if (p[i].count_eat > g_info.time_eat)
		{
			print_msg(p, END);
			return (END);
		}
		i++;
	}
	return (0);
}

int	is_finish(int *is_finish)
{
	int	i;
	
	i = 0;
	while (i < g_info.i_philo)
	{
		if (is_finish[i++] == 0)
			return (0);
	}
	return (1);
}

int	is_dead(t_philo *p)
{
	if (g_info.die <= get_time() - p->eat_time)
	{
		print_msg(p, DEAD);
		return (1);
	}
	return (0);
}

void	dead_or_alive(void *arg)
{
	t_philo *p;
	int	*finish;
	int	i;

	p = arg;
	finish = ft_calloc(g_info.i_philo, sizeof(int));
	i = 0;
	while (1)
	{
		if (i == g_info.i_philo)
			i = 0;
		if (is_dead(&p[i]))
			break ;
		if (g_info.time_eat && p[i].count_eat >= g_info.time_eat)
			finish[i]++;
		if (is_finish(finish))
		{
			print_msg(p, END);
			break ;
		}
		usleep(100);
		i++;
	}
	free(finish);
}

