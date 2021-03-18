/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:40:46 by hroh              #+#    #+#             */
/*   Updated: 2021/03/19 00:20:50 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		ft_parse_env(int argc, char **argv, t_env *env)
{
	env->n_philo = ft_atoi(argv[1]);
	env->t_to_die = ft_atoi(argv[2]);
	env->t_to_eat = ft_atoi(argv[3]);
	env->t_to_sleep = ft_atoi(argv[4]);
	env->i = 0;
	env->n_finished = 0;
	if (argc == 6)
		env->n_must_eat = ft_atoi(argv[5]);
	else
		env->n_must_eat = 0;
	if (env->n_philo < 2 || env->n_philo > 200 || env->t_to_die <= 0
		|| env->t_to_eat <= 0 || env->t_to_sleep <= 0 || env->n_must_eat < 0)
		return (1);
	return (0);
}

int		ft_init_philo(t_env *env, int i)
{
	if (!(env->p[i] = (t_philo *)malloc(sizeof(t_philo))))
		return (1);
	env->p[i]->index = i;
	env->p[i]->n_eaten = 0;
	env->p[i]->t_last_eat = env->start;
	env->p[i]->env = env;
	env->p[i]->l_fork = i;
	env->p[i]->r_fork = (i + 1) % env->n_philo;
	env->p[i]->full = 0;
	env->p[i]->dead = 0;
	return (0);
}

int		ft_init_mutex(t_env *env)
{
	int	i;

	pthread_mutex_init(&env->print, NULL);
	pthread_mutex_init(&env->end, NULL);
	pthread_mutex_lock(&env->end);
	if (!(env->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * env->n_philo)))
		return (1);
	i = 0;
	while (i < env->n_philo)
		pthread_mutex_init(&env->forks[i++], NULL);
	return (0);
}
