/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:19:24 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/25 07:49:15 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error(void)
{
	printf(RED "Usage: " RESET);
	printf("./philo  n_philos t_die t_eat t_sleep [n_t_philos_must_eat]\n");
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks && data->mutex_count >= 1)
	{
		while (i < data->fork_mut_count)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	if (data->mutex_count >= 2)
		pthread_mutex_destroy(&data->write_mutex);
	if (data->mutex_count >= 3)
		pthread_mutex_destroy(&data->meal_mutex);
	if (data->mutex_count >= 4)
		pthread_mutex_destroy(&data->death_mutex);
}

void	free_the_chain(t_data *data)
{
	destroy_mutex(data);
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

void	msg_error(t_data *data)
{
	free_the_chain(data);
	printf("error\n");
}
