/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:17:59 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 20:03:53 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_detach(philo->th_id);
	if (philo->index % 2 == 1)
		ft_my_sleep(1);
	while (philo->dead == 0 && philo->full == 0)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		if (philo->env->n_must_eat > 0 && philo->n_eaten == philo->env->n_must_eat)
		{
			philo->full = 1;
			break ;
		}
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->full == 1 && ++(philo->env->n_finished) == philo->env->n_philo)
		pthread_mutex_unlock(&philo->env->end);
	free(philo);
	return (0);
}

void	*ft_dead_monitor(void *p)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo*)p;
	while (philo && philo->dead == 0 && philo->full == 0)
	{
		now = ft_get_time();
		if (now - philo->t_last_eat > philo->env->t_to_die)
		{
			ft_die(philo);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->env->end);
			return (0);
		}
		ft_my_sleep(1);
	}
	return (0);
}

int		ft_make_thread(t_env *env)
{
	int			i;
	pthread_t	th_id;

	i = -1;
	env->start = ft_get_time();
	while (++i < env->n_philo)
	{
		if (ft_init_philo(env, i))
			return (ft_putstr("Error : malloc\n"));
		if (pthread_create(&th_id, NULL, &ft_dead_monitor, (void *)env->p[i]) != 0)
			return (ft_putstr("Error : pthread_create error\n"));
		pthread_detach(th_id);
		env->i = i;
		if (pthread_create(&(env->p[i]->th_id), NULL, ft_routine, (void *)env->p[i]) != 0)
			return (ft_putstr("Error : pthread_create error\n"));
		//usleep(100);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 5 || argc > 6)
		return (ft_putstr("Error : only 4 or 5 arguments\n"));
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (ft_putstr("Error : malloc\n"));
	if (ft_parse_env(argc, argv, env))
		return (ft_putstr("Error : Invalid arguments\n"));
	if (!(env->p = (t_philo **)malloc(sizeof(t_philo *) * env->n_philo)))
		return (ft_putstr("Error : malloc\n"));
	if (ft_init_mutex(env))
		return (ft_clear(env, 1) && ft_putstr("Error : malloc\n"));
	ft_make_thread(env);
	pthread_mutex_lock(&env->end);
	pthread_mutex_lock(&env->print);
	return (ft_clear(env, 0));
}
