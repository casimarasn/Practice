/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:21:28 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/28 19:33:35 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parse_args(int ac, char **av)
{
	int	i;
	int	control;

	i = 1;
	control = ft_atoi_strict(av[1]);
	if (ac < 5 || ac > 6)
	{
		error();
		return (TRUE);
	}
	while (i < ac)
	{
		if (ft_atoi_strict(av[i]) <= 0)
			return (TRUE);
		if (control > PHILO_MAX)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	init_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi_strict(av[1]);
	data->time_to_die = ft_atoi_strict(av[2]);
	data->time_to_eat = ft_atoi_strict(av[3]);
	data->time_to_sleep = ft_atoi_strict(av[4]);
	if (ac == 6)
	{
		data->num_must_eat = ft_atoi_strict(av[5]);
		data->has_num_must_eat = TRUE;
	}
	else
	{
		data->num_must_eat = -1;
		data->has_num_must_eat = FALSE;
	}
	data->simulation_stop = 0;
	data->start_time = 0;
	data->mutex_count = 0;
	data->fork_mut_count = 0;
}

void	init_philo(t_data *data)
{
	int	i;

	if (init_mutex(data) != 0)
	{
		msg_error(data);
		return ;
	}
	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		msg_error(data);
		return ;
	}
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].is_eating = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		i++;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		data->fork_mut_count++;
		i++;
	}
	data->mutex_count = 1;
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (1);
	data->mutex_count = 2;
	if (pthread_mutex_init(&data->death_mutex, NULL))
		return (1);
	data->mutex_count = 3;
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (1);
	data->mutex_count = 4;
	return (0);
}
