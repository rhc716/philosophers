/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:59:40 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 22:53:35 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_put_msg(t_philo *philo, int event_t)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - philo->env->start;
	if (event_t == EVENT_FORK)
	{
		ft_putnbr_fd(time, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(philo->index + 1, 1);
		ft_putstr(" has taken a fork\n");
		ft_putnbr_fd(time, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(philo->index + 1, 1);
		ft_putstr(" has taken a fork\n");
	}
	else
	{
		ft_putnbr_fd(time, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(philo->index + 1, 1);
	}
	if (event_t == EVENT_EAT)
		ft_putstr(" is eating\n");
	else if (event_t == EVENT_SLEEP)
		ft_putstr(" is sleeping\n");
	else if (event_t == EVENT_THINK)
		ft_putstr(" is thinking\n");
	else if (event_t == EVENT_DIED)
		ft_putstr(" died\n");
}
