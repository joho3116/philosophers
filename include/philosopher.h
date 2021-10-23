/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johokyoun <johokyoun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:00:59 by johokyoun         #+#    #+#             */
/*   Updated: 2021/10/22 17:12:35 by johokyoun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define ARG_ERR 1
# define DUP_ERR 2

typedef struct s_info {
    int i_philo;
    time_t die;
    time_t eat;
    time_t sleep;
    int time_eat;
    time_t start_time;

    
}       t_info;

typedef struct s_fork
{
    pthread_mutex_t fork;
    int stat;
}               t_fork;

typedef struct s_philo{
    pthread_t   philo;
    int i;
    int count_eat;
    t_fork  *left;
    t_fork  *right;
    
}               t_philo;


time_t  get_time(void);
int print_error(int err_num);

#endif