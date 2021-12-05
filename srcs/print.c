/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:59:34 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/30 20:21:25 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"

static	int	end_status(void)
{
	g_info.finish = 1;
	ft_putendl_fd("All philosophers take the meals", 1);
	pthread_mutex_unlock(&g_info.print);
	return (END);
}

static	int	dead_status(t_philo *p)
{
	g_info.finish = 1;
	ft_putnbr_fd(get_time() - g_info.start_time, 1);
	print_status(p, DEAD);
	pthread_mutex_unlock((&g_info.print));
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
	pthread_mutex_lock((&g_info.print));
	if (g_info.finish)
	{
		pthread_mutex_unlock(&g_info.print);
		return (DEAD);
	}
	else if (stat == END)
		return (end_status());
	else if (stat == DEAD)
		return (dead_status(p));
	ft_putnbr_fd(get_time() - g_info.start_time, 1);
	print_status(p, stat);
	pthread_mutex_unlock((&g_info.print));
	return (stat);
}
