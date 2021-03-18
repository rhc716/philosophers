/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:22:42 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 17:51:00 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void		ft_take_fork(t_philo *philo)
{
	if ((philo->index + 1) > (philo->env->n_philo / 2))
	{
		pthread_mutex_lock(&philo->env->forks[philo->l_fork]);
		pthread_mutex_lock(&philo->env->forks[philo->r_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->env->forks[philo->r_fork]);
		pthread_mutex_lock(&philo->env->forks[philo->l_fork]);
	}
	pthread_mutex_lock(&philo->env->print);
	ft_put_msg(philo, EVENT_FORK);
	ft_put_msg(philo, EVENT_FORK);
	pthread_mutex_unlock(&philo->env->print);
}

void		ft_eat(t_philo *philo)
{
	philo->t_last_eat = ft_get_time();
	philo->n_eaten++;
	pthread_mutex_lock(&philo->env->print);
	ft_put_msg(philo, EVENT_EAT);
	pthread_mutex_unlock(&philo->env->print);
	usleep(philo->env->t_to_eat * 1000);
	pthread_mutex_unlock(&philo->env->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->env->forks[philo->l_fork]);
}

void		ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print);
	ft_put_msg(philo, EVENT_SLEEP);
	pthread_mutex_unlock(&philo->env->print);
	usleep(philo->env->t_to_sleep * 1000);
}

void		ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print);
	ft_put_msg(philo, EVENT_THINK);
	pthread_mutex_unlock(&philo->env->print);
}

void		ft_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print);
	ft_put_msg(philo, EVENT_DIED);
	pthread_mutex_unlock(&philo->env->print);
}