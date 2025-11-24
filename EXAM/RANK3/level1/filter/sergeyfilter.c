/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nombre_archivo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.fr>     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2025/08/04 12:00:00 by msedeno-           #+#    #+#            */
/*   Updated: 2025/08/04 12:00:00 by msedeno-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *str1, char *str2, int size)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i], i < size)
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	char	c;
	char str[9999];
	int	fd;
	int	size;

	if (argc != 2)
		return (1);
	i = 0;
	while ((fd = read(1, &c, 1)) > 0)
	{
		if (fd < 0)
		{
			fprintf(stderr, "Error: ");
			return (1);
		}
		str[i] = c;
		i++;
	}
	i = 0;
	size = strlen(str);
	while (i < size)
	{
		if (ft_strncmp(argv[i], &c, size) == 1)
			printf("*");
		else
			for (int j; j < i; j++)
				printf(c[j]);
		i++;
	}
}
