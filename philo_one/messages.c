/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:59:40 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 16:15:50 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_put_msg(t_philo *philo, int event_t)
{
	ft_putnbr_fd(ft_get_time() - philo->env->start, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->index + 1, 1);
	if (event_t == EVENT_FORK)
		ft_putstr(" has taken a fork\n");
	else if (event_t == EVENT_EAT)
		ft_putstr(" is eating\n");
	else if (event_t == EVENT_SLEEP)
		ft_putstr(" is sleeping\n");
	else if (event_t == EVENT_THINK)
		ft_putstr(" is thinking\n");
	else if (event_t == EVENT_DIED)
		ft_putstr(" died\n");
}
