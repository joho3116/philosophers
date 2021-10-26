/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:39:13 by johokyoun         #+#    #+#             */
/*   Updated: 2021/10/26 13:39:57 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosopher.h"

void	*philos_life(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->i % 2)
		usleep(100);
	while (!p->finish)
	{
		if (p->finish)
			break ;
		eating_philo(p);
		if (p->count_eat > 0)
			break ;
		if (p->finish)
			break;
		sleeping_philo(p);
		if  (p->finish)
			break ;
		thinking_philo(p);
		if (p->finish)
			break ;
	}
	return (NULL);
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&(p->left->fork));
	p->left->stat = 0;
	pthread_mutex_unlock(&(p->right->fork));
	p->right->stat = 0;
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->left->fork));
	p->left->stat = 1;
	pthread_mutex_lock(&(p->right->fork));
	p->left->stat = 1;
}

void	eating_philo(t_philo *p)
{
	take_forks(p);
	print_status(p, TAKING);	
	p->eat_time = get_time();
	print_status(p, EATING);
	while(get_time() - p->eat_time <= p->info->eat)
		usleep(100);
	p->count_eat++;
	drop_forks(p);
}

void	sleeping_philo(t_philo *p)
{
	time_t	start;
	
	print_status(p, SLEEPING);
	start = get_time();
	while(get_time() - start <= p->info->sleep)
		usleep(100);
}

void	thinking_philo(t_philo *p)
{
	print_status(p, THINKING);
}