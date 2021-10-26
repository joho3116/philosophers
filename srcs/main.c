/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:38 by johokyoun         #+#    #+#             */
/*   Updated: 2021/10/26 14:22:38 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	is_dead(t_philo *p)
{
	if (p->info->die <= get_time() - p->eat_time)
		return (DEAD);
	return (0);
}

int	check_status(t_philo *p)
{
	if (p->finish)
	{
		pthread_mutex_unlock(&(p->info->print));
		return (END);
	}
	else if (is_dead(p) == DEAD)
	{
		time_t	dead_time;
		p->finish = 1;
		dead_time = get_time();
		ft_putnbr_fd(get_time() - (p->info->start_time), 1);
		ft_putstr_fd("ms ", 1);
		ft_putstr_fd("Philosopher ", 1);
		ft_putnbr_fd(p->i + 1, 1);
		ft_putstr_fd("DIED.", 1);
		pthread_mutex_unlock(&(p->info->print));
		return (DEAD);
	}
	return (0);
}

void	print_status(t_philo *p, int stat)
{
	pthread_mutex_lock(&(p->info->print));
	if (check_status(p))
		return ;
	ft_putnbr_fd(get_time() - (p->info->start_time), 1);
	ft_putstr_fd("ms ", 1);
	ft_putstr_fd("Philosopher ", 1);
	ft_putnbr_fd(p->i + 1, 1);
	if (stat == TAKING)
		ft_putstr_fd(" has taken a fork.\n", 1);
	if (stat == EATING)
		ft_putstr_fd(" is eating.\n", 1);
	if (stat == SLEEPING)
		ft_putstr_fd(" is sleeping.\n", 1);
	if (stat == THINKING)
		ft_putstr_fd(" is thinking.\n", 1);
	pthread_mutex_unlock(&(p->info->print));
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
	if (p->count_eat >= p->info->time_eat)
		p->finish = 1;
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

// free

int	end(t_info *info, t_philo *p, t_fork *f)
{
	int	i;

	i = 0;
	while (i < p->i)
	{
		pthread_join(p[i].philo, NULL);
		i++;
	}
	free(p);
	i = 0;
	while (i < p->i)
	{
		pthread_mutex_destroy(&f[i].fork);
		i++;
	}
	free(f);
	free(info);
	return (0);
}

// 구조체들 초기화 단계

t_fork	*init_fork(t_info *info)
{
	t_fork *fork;
	int	i;

	i = 0;
	fork = ft_calloc(info->i_philo, sizeof(t_fork));
	while (i< info->i_philo)
	{
		pthread_mutex_init(&(fork[i].fork), NULL);
		i++;
	}
	return (fork);
}

t_philo	*init_philo(t_info *info, t_fork *f)
{
	t_philo *p;
	int i;

	i = 0;
	p = ft_calloc(info->i_philo, sizeof(p));
	while (i < info->i_philo)
	{
		p[i].i = i;
		if (info->time_eat)
			p[i].count_eat = info->time_eat;
		else
			p[i].count_eat = 0;
		p[i].left = &f[i];
		p[i].right = &f[(i + 1) % 5];
		p->info = info;
		i++;
	}
	return (p);
}

int	init_info(int argc, char **argv, t_info *info)
{
	t_info	*i;
	
	if (!(argc == 5 || argc == 6))
		return (0);
	if ((info->i_philo = ft_atoi(argv[1])) < 2 ||
	(info->die = ft_atoi(argv[2])) <= 0 ||
	(info->eat = ft_atoi(argv[3])) <= 0 ||
	(info->sleep = ft_atoi(argv[4])) <= 0)
		return (0);
	if (argv[5])
	{
		if ((info->time_eat = ft_atoi(argv[5])) <= 0)
			return (0);
	}
	info->start_time = get_time();
	pthread_mutex_init(&(info->print), NULL);
	return (1);
}

int main(int argc, char **argv)
{
	t_info	*info;
	t_philo *p;
	t_fork	*f;
	int	i;
	
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (print_error(DUP_ERR));
	if (!(init_info(argc, argv, info)))
		return (print_error(ARG_ERR));
	f = init_fork(info);
	p = init_philo(info, f);
	i = 0;
	while (i < info->i_philo)
	{
		pthread_create(&(p[i].philo), NULL, philos_life, &(p[i]));
		i++;
	}
	return (end(info, p, f));
}