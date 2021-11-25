/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:39:13 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/22 17:44:57 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"


int	drop_forks(t_philo *p, int stat)
{
	pthread_mutex_unlock(&(p->left->fork));
	pthread_mutex_unlock(&(p->right->fork));
	if (stat == DEAD)
		return (DEAD);
	else
		return (0);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->left->fork));
	pthread_mutex_lock(&(p->right->fork));
}

int	eating_philo(t_philo *p)
{
	take_forks(p);
	if (print_msg(p, TAKING) == DEAD)
		return (drop_forks(p, DEAD));
	p->eat_time = get_time();
	if (print_msg(p, EATING) == DEAD)
		return(drop_forks(p, DEAD));
	while((get_time() - p->eat_time) <= g_info.eat)
		usleep(100);
	p->count_eat++;
	return (drop_forks(p, TAKING));
}

int	sleeping_philo(t_philo *p)
{
	time_t	start;

	if (print_msg(p, SLEEPING) == DEAD)
		return (DEAD);
	start = get_time();
	while ((get_time() - start) <= g_info.sleep)
		usleep(100);
	return (0);
}

int	thinking_philo(t_philo *p)
{
	if (print_msg(p, THINKING) == DEAD)
		return (DEAD);
	return (0);
}

void	*philos_life(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->i % 2)
		usleep(1000);
	while (1)
	{
		if (g_info.finish)
			return(0);
		if (eating_philo(p) == DEAD)
			return (0);
		if (sleeping_philo(p) == DEAD)
			return (0);
		if (thinking_philo(p) == DEAD)
			return (0);
	}
	return (0);
}
