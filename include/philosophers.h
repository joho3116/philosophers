/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:00:59 by johokyoun         #+#    #+#             */
/*   Updated: 2021/12/07 19:23:05 by hojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define ARG_ERR 1
# define DUP_ERR 2

# define TAKING 3
# define EATING 4
# define SLEEPING 5
# define THINKING 6
# define DEAD 7
# define END 8

typedef struct s_info{
	int				i_philo;
	time_t			die;
	time_t			eat;
	time_t			sleep;
	int				time_eat;
	int				finish;
	time_t			start_time;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	fork;
}				t_fork;

typedef struct s_philo
{
	pthread_t	philo;
	int			i;
	int			count_eat;
	time_t		eat_time;
	t_fork		*left;
	t_fork		*right;
}	t_philo;

t_info	g_info;

time_t	get_time(void);
int		print_error(int err_num);
void	*philos_life(void *arg);
int		print_msg(t_philo *p, int stat);
void	dead_or_alive(void *arg);
void	ft_msleep(time_t ms);
void	print_status(t_philo *p, int stat);
int		is_check(t_philo *p);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);

#endif
