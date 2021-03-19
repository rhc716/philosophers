/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:39:45 by hroh              #+#    #+#             */
/*   Updated: 2021/03/19 22:05:11 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		g_monitor_end;

int		ft_clear(t_env *env)
{
	int i;

	g_monitor_end = 1;
	usleep(1000);
	i = -1;
	while (++i < env->n_philo)
	{
		kill(env->p[i]->pid, SIGKILL);
		free(env->p[i]);
	}
	free(env->p);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_END);
	sem_unlink(SEM_FORKS);
	sem_close(env->print_sem);
	sem_close(env->end_sem);
	sem_close(env->forks_sem);
	free(env);
	return (0);
}
