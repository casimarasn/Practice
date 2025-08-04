/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:27 by msedeno-          #+#    #+#             */
/*   Updated: 2025/07/24 13:53:39 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

/*t_list	*create_node(void *data)
{
	t_list	*node = malloc(sizeof(t_list));

	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*n1 = create_node("Hola");
	t_list	*n2 = create_node("Mundo");
	t_list	*n3 = create_node("42");


	n1->next = n2;
	n2->next = n3;

	printf("Tamaño de lista: %d\n", ft_list_size(n1));
	printf("Tamaño de lista (solo uno): %d\n", ft_list_size(n3));
	printf("Tamaño de lista vacía: %d\n", ft_list_size(NULL));

	free(n1);
	free(n2);
	free(n3);

	return (0);
}*/
