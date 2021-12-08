/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:59:34 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/08 16:39:45 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	end_status(t_philo *p)
{
	p->info->finish = 1;
	ft_putendl_fd("All philosophers take the meals", 1);
	pthread_mutex_unlock(&(p->info->print));
	return (END);
}

int	dead_status(t_philo *p)
{
	p->info->finish = 1;
	ft_putnbr_fd(get_time() - p->info->start_time, 1);
	print_status(p, DEAD);
	pthread_mutex_unlock(&(p->info->print));
	return (DEAD);
}

void	print_status(t_philo *p, int stat)
{
	ft_putstr_fd("ms Philosopher ", 1);
	ft_putnbr_fd(p->i + 1, 1);
	if (stat == TAKING)
		ft_putendl_fd(" has taken a fork.", 1);
	else if (stat == EATING)
		ft_putendl_fd(" is eating.", 1);
	else if (stat == SLEEPING)
		ft_putendl_fd(" is sleeping.", 1);
	else if (stat == THINKING)
		ft_putendl_fd(" is thinking.", 1);
	else if (stat == DEAD)
		ft_putendl_fd(" is died.", 1);
}

int	print_msg(t_philo *p, int stat)
{
	pthread_mutex_lock(&(p->info->print));
	if (p->info->finish)
	{
		pthread_mutex_unlock(&(p->info->print));
		return (DEAD);
	}
	if (stat == END)
		return (end_status(p));
	else if (stat == DEAD)
		return (dead_status(p));
	ft_putnbr_fd(get_time() - p->info->start_time, 1);
	print_status(p, stat);
	pthread_mutex_unlock(&(p->info->print));
	return (stat);
}
