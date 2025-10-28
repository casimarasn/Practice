/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:33:31 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/08 00:39:09 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	tlen;

	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	tlen = len1 + 1 + len2 + 1;
	s = (char *)malloc(tlen);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len1 + 1);
	s[len1] = ' ';
	s[len1 + 1] = '\0';
	ft_strlcat(s, s2, tlen);
	return (s);
}

int	ft_atoi_strict(const char *str, long *num)
{
	int		sign;
	long	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	result = 0;
	while (ft_isdigit (*str))
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result < INT_MIN)))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*num = result * sign;
	return (1);
}

char	*create_big_av(int ac, char **av)
{
	int		i;
	char	*big_av;
	char	*tmp;

	is_valid_args (ac, av);
	big_av = ft_strdup(av[1]);
	if (!big_av)
		error();
	i = 2;
	while (i < ac)
	{
		is_valid_char(av[i]);
		tmp = big_av;
		big_av = ft_strjoin_space (big_av, av[i]);
		if (!big_av)
			error();
		free (tmp);
		i++;
	}
	return (big_av);
}

char	**join_arguments(int ac, char **av)
{
	char	**numbers;
	char	*big_av;
	int		i;
	long	num;

	if (ac < 2)
		return (NULL);
	big_av = create_big_av(ac, av);
	numbers = ft_split (big_av, ' ');
	free (big_av);
	if (!numbers)
		error ();
	check_empty_str(numbers);
	i = 0;
	while (numbers[i])
	{
		if (!ft_atoi_strict(numbers[i], &num))
			error();
		i++;
	}
	return (numbers);
}
