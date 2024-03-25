/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:26 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 17:05:14 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// * Allocates memory with malloc and handles error if it fails
void	allocate(t_game **game, size_t size, void **ptr, t_error error)
{
	(*ptr) = malloc(size);
	if (!*ptr)
		error_occurred(game, error);
}

// * Frees game memory by calling free sub-functions
void	free_game(t_game **game)
{
	if (game && *game)
	{
		free_list(&(*game)->map->list, NULL);
		free((*game)->map);
		(*game)->map = NULL;
		free(*game);
		*game = NULL;
	}
}

// ! Frees memory for a linked list
void	free_list(t_list **head, t_list *current)
{
	if (head)
	{
		while (*head)
		{
			current = *head;
			*head = (*head)->next;
			free(current->line);
			current->line = NULL;
			free(current);
			current = NULL;
		}
	}
}
