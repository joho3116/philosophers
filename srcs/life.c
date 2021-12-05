/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:39:13 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/30 21:21:30 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"


int	drop_forks(t_philo *p, int stat)
{
	pthread_mutex_unlock(&(p->left->fork));
	pthread_mutex_unlock(&(p->right->fork));
	return (stat);
}

int	take_forks(t_philo *p)
{
	pthread_mutex_lock(&(p->left->fork));
	if (print_msg(p, TAKING) == DEAD)
		return (drop_forks(p, DEAD));
	pthread_mutex_lock(&(p->right->fork));
	if (print_msg(p, TAKING) == DEAD)
		return (drop_forks(p, DEAD));
	return (1);
}
int	eating_philo(t_philo *p)
{
	if (take_forks(p) == DEAD)
		return (DEAD);
	p->eat_time = get_time();
	if (print_msg(p, EATING) == DEAD)
		return(drop_forks(p, DEAD));
	p->count_eat++;
	ft_msleep(g_info.eat);
	return (drop_forks(p, TAKING));
}

int	sleeping_philo(t_philo *p)
{
	time_t	start;

	if (print_msg(p, SLEEPING) == DEAD)
		return (DEAD);
	ft_msleep(g_info.sleep);
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
		ft_msleep(100);
	while (1)
	{
		if (g_info.finish)
			return(0);
		if (eating_philo(p) == DEAD)
			return (0);
		if (sleeping_philo(p) == DEAD || is_check(p))
			return (0);
		if (thinking_philo(p) == DEAD || is_check(p))
			return (0);
	}
	return (0);
}
