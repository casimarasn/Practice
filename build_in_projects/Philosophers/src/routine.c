/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:10:56 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/31 18:27:52 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine,
				&data->philos[i]) != 0)
		{
			msg_error(data);
			return ;
		}
		i++;
	}
}

void	wait_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->data->death_mutex);
	stop = philo->data->simulation_stop;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (stop);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat, philo);
	while (!should_stop(philo))
	{
		philo_think(philo);
		if (should_stop(philo))
			break ;
		philo_eat(philo);
		if (should_stop(philo))
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(1000);
	return (philo_routine(philo));
}
