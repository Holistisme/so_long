/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:25:22 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/26 11:40:34 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Allocates memory with malloc and handles error if it fails
void	*allocation(t_game *game, size_t size, t_error error)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(size);
	if (!ptr)
		error_occurred(game, error);
	return (ptr);
}
