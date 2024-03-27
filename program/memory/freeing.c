/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:26 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 10:38:41 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Frees game memory by calling free sub-functions
void	free_game(t_game **game)
{
	if (game && *game)
	{
		free_map(&(*game)->map);
		free(*game);
		*game = NULL;
	}
}

// ! Frees map memory by calling free sub-functions
void	free_map(t_map **map)
{
	if (map && *map)
	{
		if ((*map)->cells)
			free_cells(&(*map)->cells);
		if ((*map)->cloned_cells)
			free_cells(&(*map)->cloned_cells);
		if ((*map)->gnl_map)
			free_list(&(*map)->gnl_map);
		if ((*map)->gnl_line)
			free((*map)->gnl_line);
		if ((*map)->current_position)
			free((*map)->current_position);
		if ((*map)->spawn)
			free((*map)->spawn);
		if ((*map)->exit)
			free((*map)->exit);
		free(*map);
		*map = NULL;
	}
}

// ! Frees memory for a linked list
void	free_list(t_list **head)
{
	t_list	*current;

	current = NULL;
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

// ! Frees memory for a double character pointer
void	free_cells(char ***cells)
{
	size_t	index;

	index = 0;
	if (cells && *cells)
	{
		while ((*cells)[index])
		{
			free((*cells)[index]);
			(*cells)[index++] = NULL;
		}
		free(*cells);
		*cells = NULL;
	}
}
