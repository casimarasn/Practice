/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:50:13 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/28 20:05:03 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

/* ************************************************************************** */
/*                               DEFINES                                      */
/* ************************************************************************** */

# define PHILO_MAX 200
# define ERR_ARGS "Error: Invalid arguments\n"
# define ERR_MALLOC "Error: Malloc failed\n"
# define ERR_MUTEX "Error: Mutex initialization failed\n"
# define ERR_THREAD "Error: Thread creation failed\n"

// Colors
# define USE_COLORS 1
# if USE_COLORS
#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define ORANGE "\033[38;5;208m"
#  define BLUE "\033[0;34m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"
# else
#  define RED ""
#  define GREEN ""
#  define YELLOW ""
#  define ORANGE ""
#  define BLUE ""
#  define CYAN ""
#  define RESET ""
# endif

/* ************************************************************************** */
/*                               STRUCTURES                                   */
/* ************************************************************************** */

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	int				is_eating;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				mutex_count;
	int				fork_mut_count;

	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				has_num_must_eat;
	int				simulation_stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
}	t_data;

typedef enum s_err
{
	FALSE,
	TRUE,
}			t_err;

/* ************************************************************************** */
/*                            FUNCTION PROTOTYPES                             */
/* ************************************************************************** */

// ./args_init.c
int			parse_args(int ac, char **av);
void		init_data(t_data *data, int ac, char **av);
void		init_philo(t_data *data);
int			init_mutex(t_data *data);

// ./args_utils.c
int			ft_isspace(int c);
int			ft_isdigit(int n);
int			ft_atoi_strict(const char *str);
int			ft_strstr(char *s, char *finder);
char		*get_color(char *status);

// ./big_sister.c
void		set_sim_stop(t_data *data, int value);
void		*big_sister(void *arg);
int			is_all_ate_enough(t_data *data);

// ./errors_free.c
void		error(void);
void		destroy_mutex(t_data *data);
void		free_the_chain(t_data *data);
void		msg_error(t_data *data);

// ./main.c
void		philos_at_table(t_data *data, int ac, char **av);
int			main(int ac, char **av);

// ./routine.c
void		create_threads(t_data *data);
void		wait_threads(t_data *data);
void		*one_philo(t_philo *philo);
void		*philo_routine(void *arg);
int			should_stop(t_philo *philo);
void		*routine(void *arg);

// ./routine_utils.c
long long	get_time(void);
int			print_status(t_philo *philo, char *status, int force_print);
int			check_death(t_philo *philo);
void		ft_usleep(long long t_ms, t_philo *philo);

// ./table.c
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
