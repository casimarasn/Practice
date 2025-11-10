/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:40:44 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/14 13:28:12 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t sizem)
{
	void	*ptr;

	ptr = malloc(nmeb * sizem);
	if (ptr == NULL)
		return (ptr);
	ft_bzero (ptr, nmeb * sizem);
	return (ptr);
}
