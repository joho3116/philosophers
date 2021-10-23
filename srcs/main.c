/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:38 by johokyoun         #+#    #+#             */
/*   Updated: 2021/10/23 20:46:11 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	sleep_philo(t_philo *p)
{
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->left);
	pthread_mutex_lock(p->right);
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
		p[i].count_eat = info->time_eat;
		p[i].left = &f[i];
		p[i].right = &f[(i + 1) % 5];
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
	return (1);
}

int main(int argc, char **argv)
{
	t_info	*info;
	t_philo *p;
	t_fork	*f;
	
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (print_error(DUP_ERR));
	if (!(init_info(argc, argv, info)))
		return (print_error(ARG_ERR));
	f = init_fork(info);
	p = init_philo(info, f);
	return (end(info, p, f));
}