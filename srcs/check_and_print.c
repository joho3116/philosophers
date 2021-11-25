/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:59:34 by johokyoun         #+#    #+#             */
/*   Updated: 2021/11/20 23:03:33 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosophers.h"

int	is_finish(t_philo *p, int *is_finish)
{
	int	i;
	
	i = 0;
	while (i < g_info.i_philo)
	{
		if (is_finish[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_dead(t_philo *p)
{
	if (g_info.die <= get_time() - p->eat_time)
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
	finish = ft_calloc(g_info.i_philo, sizeof(int));
	i = 0;
	while (1)
	{
		if (i == g_info.i_philo)
			i = 0;
		if (is_dead(&p[i]))
			break ;
		if (g_info.time_eat &&
		p[i].count_eat >= g_info.time_eat)
			finish[i] = 1;
		if (is_finish(p, finish))
		{
			print_msg(NULL, END);
			break ;
		}
		usleep(100);
		i++;
	}
	free(finish);
}

int	end_status(void)
{
	g_info.finish = 1;
	pthread_mutex_unlock(&g_info.print);
	return (END);
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
	{
		g_info.finish = 1;
		ft_putendl_fd(" is died.", 1);
	}
}

int	print_msg(t_philo *p, int stat)
{
	pthread_mutex_lock(&g_info.print);
	printf("%d\n", stat);
	if (g_info.finish == 1)
	{
		pthread_mutex_unlock(&g_info.print);
		return (DEAD);
	}
	else if (stat == END)
	{	
		ft_putendl_fd("All philosophers take the meals", 1);
		return (end_status());
	}
	ft_putnbr_fd(get_time() - g_info.start_time, 1);
	print_status(p, stat);
	pthread_mutex_unlock(&g_info.print);
	return (stat);
}
