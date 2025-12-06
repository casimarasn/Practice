/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sister.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:08:04 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/30 16:50:53 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_sim_stop(t_data *data, int value)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_stop = value;
	pthread_mutex_unlock(&data->death_mutex);
}

void	*big_sister(void *arg)
{
	t_data		*data;
	int			i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (is_all_ate_enough(data))
		{
			set_sim_stop(data, 1);
			return (NULL);
		}
		usleep(1000);
	}
}

int	is_all_ate_enough(t_data *data)
{
	int	i;
	int	count_finished;

	if (data->num_must_eat == -1)
		return (0);
	i = 0;
	count_finished = 0;
	pthread_mutex_lock(&data->meal_mutex);
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten >= data->num_must_eat)
			count_finished++;
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (count_finished == data->num_philos);
}
