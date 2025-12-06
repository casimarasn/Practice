/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:19:27 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/31 14:03:08 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	print_status(t_philo *philo, char *status, int force_print)
{
	long long	time;
	int			lock_res;

	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->simulation_stop == 1 && !force_print)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	lock_res = pthread_mutex_lock(&philo->data->write_mutex);
	if (lock_res)
		return (1);
	time = get_time() - philo->data->start_time;
	if (USE_COLORS == 1)
		printf("%s%lld %d %s%s\n",
			get_color(status), time, philo->id, status, RESET);
	else
		printf("%lld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (0);
}

int	check_death(t_philo *philo)
{
	long long	t_since_meal;
	int			is_eating;

	pthread_mutex_lock(&philo->data->meal_mutex);
	t_since_meal = get_time() - philo->last_meal_time;
	is_eating = philo->is_eating;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (t_since_meal >= philo->data->time_to_die && !is_eating)
	{
		set_sim_stop(philo->data, 1);
		print_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

void	ft_usleep(long long t_ms, t_philo *philo)
{
	long long	start;

	start = get_time();
	while (get_time() - start < t_ms)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->simulation_stop)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		usleep(100);
	}
}
