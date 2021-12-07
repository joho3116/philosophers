/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:38 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/07 16:24:24 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	end(t_philo *p, t_fork *f)
{
	int	i;

	i = 0;
	if (p != NULL)
	{
		while (i < p->i)
		{
			pthread_join(p[i].philo, NULL);
			i++;
		}
		free(p);
	}
	i = 0;
	if (f != NULL)
	{
		while (i < p->i)
		{
			pthread_mutex_destroy(&f[i].fork);
			i++;
		}
		free(f);
	}
	return (0);
}

t_fork	*init_fork(void)
{
	t_fork	*f;
	int		i;

	i = 0;
	f = ft_calloc(g_info.i_philo, sizeof(t_fork));
	if (f == NULL)
		return (NULL);
	while (i < g_info.i_philo)
	{
		pthread_mutex_init(&(f[i].fork), NULL);
		i++;
	}
	return (f);
}

t_philo	*init_philo(t_fork *f)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = ft_calloc(g_info.i_philo, sizeof(t_philo));
	if (p == NULL)
		return (NULL);
	while (i < g_info.i_philo)
	{
		p[i].i = i;
		p[i].eat_time = g_info.start_time;
		p[i].left = &f[i];
		if (i != (i + 1) % g_info.i_philo)
			p[i].right = &f[(i + 1) % g_info.i_philo];
		i++;
	}
	return (p);
}

int	init_info(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	g_info.i_philo = ft_atoi(argv[1]);
	g_info.die = ft_atoi(argv[2]);
	g_info.eat = ft_atoi(argv[3]);
	g_info.sleep = ft_atoi(argv[4]);
	if (g_info.i_philo < 2 || g_info.die <= 0
		|| g_info.eat <= 0 || g_info.sleep <= 0)
		return (0);
	if (argv[5])
	{
		g_info.time_eat = ft_atoi(argv[5]);
		if (g_info.time_eat <= 0)
			return (0);
	}
	g_info.start_time = get_time();
	g_info.finish = 0;
	pthread_mutex_init(&(g_info.print), NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	t_fork	*f;
	int		i;

	if (!(init_info(argc, argv)))
		return (print_error(ARG_ERR));
	f = init_fork();
	p = init_philo(f);
	if (f == NULL || p == NULL)
		return (end(p, f));
	i = 0;
	while (i < g_info.i_philo)
	{
		pthread_create(&(p[i].philo), NULL, philos_life, &p[i]);
		i++;
	}
	dead_or_alive(p);
	return (end(p, f));
}
