/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:29:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/17 08:50:34 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(long start)
{
	struct timeval	time;
	long			t;
	
	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t - start);
}

void	ft_usleep(long time, long start)
{
	while (get_time(start) < time)
		usleep(100);
}

int	init_philo(t_philo *philo, char **av)
{
	int	i;
	
	philo->nb_philo = ft_atoi(av[1]);
	i = philo->nb_philo;
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->nb_eat = -1;
	if (av[5])
		philo->nb_eat = ft_atoi(av[5]);
	philo->start = get_time(0);
	philo->is_over = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * (philo->nb_philo));
	if (!philo->forks)
		ft_error(4);
	philo->philo = malloc(sizeof(pthread_t) * (philo->nb_philo));
	if (!philo->philo)
		ft_error(3);
	return (1);
}

void	free_philo(t_philo *philo)
{
	while (philo->nb_philo)
	{
		pthread_detach(philo->philo[philo->nb_philo]);
		pthread_mutex_destroy(&philo->forks[philo->nb_philo]);
		philo->nb_philo--;
	}
}