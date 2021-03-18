/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:09:14 by hroh              #+#    #+#             */
/*   Updated: 2021/03/18 23:17:45 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int		ft_strlen(const char *str)
{
	int s;

	s = 0;
	while (str[s] != 0)
		s++;
	return (s);
}

int		ft_strlcpy(char *dest, const char *src, int size)
{
	int s;
	int src_len;

	s = 0;
	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[s] && s < size - 1)
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = 0;
	return (src_len);
}

char	*ft_strdup(const char *str)
{
	char	*re;
	int		len;

	len = ft_strlen(str);
	if (!(re = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(re, str, len + 1);
	return (re);
}

char	*ft_strjoin(char *s1, char *s2, int free_case)
{
	char	*re;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(re = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(re, s1, s1_len + 1);
	if (free_case == 1 || free_case == 3)
		free(s1);
	ft_strlcpy(re + s1_len, s2, s2_len + 1);
	if (free_case == 2 || free_case == 3)
		free(s2);
	return (re);
}

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

int		ft_num_len(long n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	char			*re;
	long			us_n;
	int				len;

	len = ft_num_len(n);
	if (!(re = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	us_n = n;
	re[len] = 0;
	len--;
	while (len >= 0)
	{
		re[len] = '0' + (us_n % 10);
		us_n = us_n / 10;
		len--;
	}
	return (re);
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
