/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:09:14 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 22:41:46 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_my_sleep(long t_sleep)
{
	struct timeval	tv;
	long			end;
	long			now;

	gettimeofday(&tv, NULL);
	end = tv.tv_sec * 1000000 + tv.tv_usec + t_sleep * 1000;
	while (1)
	{
		gettimeofday(&tv, NULL);
		now = tv.tv_sec * 1000000 + tv.tv_usec;
		if (now < end)
			usleep(800);
		else
			return ;
	}
}

long	ft_get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r');
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}


int		ft_putstr(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (0);
}


long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	re;

	i = 0;
	sign = 1;
	re = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		sign = -1;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		re = re * 10 + str[i] - '0';
		i++;
	}
	return (re * sign);
}

void	ft_putnbr_fd(long n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}