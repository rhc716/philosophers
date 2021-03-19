/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:39:45 by hroh              #+#    #+#             */
/*   Updated: 2021/03/19 15:35:19 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		ft_clear(t_env *env)
{
	int i;

	free(env->p);
	pthread_mutex_destroy(&env->print);
	pthread_mutex_destroy(&env->end);
	i = 0;
	while (i < env->n_philo)
		pthread_mutex_destroy(&env->forks[i++]);
	free(env->forks);
	return (0);
}
