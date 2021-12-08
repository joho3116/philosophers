/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:38 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/08 15:53:28 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	end(t_philo *p, t_fork *f)
{
	int	i;

	i = 0;
	if (p != NULL)
	{
		while (i < p->info->i_philo)
		{
			pthread_join(p[i].philo, NULL);
			i++;
		}
		free(p);
	}
	i = 0;
	if (f != NULL)
	{
		while (i < p->info->i_philo)
		{
			pthread_mutex_destroy(&f[i].fork);
			i++;
		}
		free(f);
	}
	return (0);
}

t_fork	*init_fork(t_info *info)
{
	t_fork	*f;
	int		i;

	i = 0;
	f = ft_calloc(info->i_philo, sizeof(t_fork));
	if (f == NULL)
		return (NULL);
	while (i < info->i_philo)
	{
		pthread_mutex_init(&(f[i].fork), NULL);
		i++;
	}
	return (f);
}

t_philo	*init_philo(t_fork *f, t_info *info)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = ft_calloc(info->i_philo, sizeof(t_philo));
	if (p == NULL)
		return (NULL);
	while (i < info->i_philo)
	{
		p[i].i = i;
		p[i].eat_time = info->start_time;
		p[i].left = &f[i];
		p[i].info = info;
		if (i != (i + 1) % info->i_philo)
			p[i].right = &f[(i + 1) % info->i_philo];
		i++;
	}
	return (p);
}

int	init_info(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	info->i_philo = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (info->i_philo < 2 || info->die <= 0
		|| info->eat <= 0 || info->sleep <= 0)
		return (0);
	if (argv[5])
	{
		info->time_eat = ft_atoi(argv[5]);
		if (info->time_eat <= 0)
			return (0);
	}
	info->start_time = get_time();
	info->finish = 0;
	pthread_mutex_init(&(info->print), NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*p;
	t_fork	*f;
	int		i;

	i = 0;
	if (!init_info(argc, argv, &info))
		return (print_error(ARG_ERR));
	f = init_fork(&info);
	p = init_philo(f, &info);
	if (f == NULL || p == NULL)
		return (end(p, f));
	while (i < info.i_philo)
	{
		pthread_create(&(p[i].philo), NULL, philos_life, &p[i]);
		i++;
	}
	check_philo_alive(p, &info);
	return (end(p, f));
}
