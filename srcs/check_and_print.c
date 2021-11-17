/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:59:34 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/12 18:38:24 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"

int	is_finish(t_philo *p, int *is_finish)
{
	int	i;
	i = 0;
	while (i < p)
	{
		/* code */
	}

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

void	dead_or_alive(void *arg)
{
	t_philo *p;
	int	*finish;
	int	i;

	p = arg;
	finish = ft_calloc(p->info->i_philo, sizeof(int));
	i = 0;
	while (1)
	{
		if (i == p->info->i_philo)
			i = 0;
		if (is_dead(&p[i]))
			break;
		if (p->info->time_eat &&
		p[i].count_eat >= p->info->time_eat)
			finish[i] = 1;
		if (is_finish(p, finish))
		{
			print_msg(NULL, END);
			break;
		}
		usleep(100);
		i++;
	}
	free(finish);
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
	else
		ft_putendl_fd(" is died.", 1);
}

int	print_msg(t_philo *p, int stat)
{
	pthread_mutex_lock(&(p->info->print));
	if (stat == DEAD)
	{
		pthread_mutex_unlock(&(p->info->print));
		return (DEAD);
	}
	ft_putnbr_fd(get_time() - p->info->start_time, 1);
	if (stat == END)
		ft_putendl_fd("All philosophers take the meals", 1);
	else
		print_status(p, stat);
	pthread_mutex_unlock(&(p->info->print));
	return (stat);
}
