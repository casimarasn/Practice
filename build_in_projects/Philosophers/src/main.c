/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:48:52 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/31 14:05:21 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*one_philo(t_philo *philo)
{
	print_status(philo, "has taken a fork", 0);
	ft_usleep(philo->data->time_to_die, philo);
	return (NULL);
}

void	philos_at_table(t_data *data, int ac, char **av)
{
	int			i;
	pthread_t	monitor;

	init_data(data, ac, av);
	init_philo(data);
	data->start_time = get_time();
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_mutex);
		data->philos[i].last_meal_time = data->start_time;
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
	create_threads(data);
	pthread_create(&monitor, NULL, big_sister, data);
	wait_threads(data);
	pthread_join(monitor, NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_args(ac, av))
	{
		printf(ERR_ARGS);
		return (1);
	}
	philos_at_table(&data, ac, av);
	free_the_chain(&data);
	return (0);
}
