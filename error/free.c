/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:01:04 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 11:57:19 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Defines each element of the map structure as NULL
void	set_map_to_null(t_map **map)
{
	(*map)->cells = NULL;
	(*map)->cloned_cells = NULL;
	(*map)->spawn = NULL;
	(*map)->exit = NULL;
	(*map)->line = NULL;
	(*map)->list = NULL;
}

// ? Frees map memory by calling free sub-functions
void	free_map(t_map **map)
{
	if (map && *map)
	{
		if ((*map)->cells)
			free_cells(&(*map)->cells);
		if ((*map)->cloned_cells)
			free_cells(&(*map)->cloned_cells);
		if ((*map)->spawn)
			free((*map)->spawn);
		if ((*map)->exit)
			free((*map)->exit);
		if ((*map)->list)
			free_list(&(*map)->list);
		if ((*map)->line)
			free((*map)->line);
		set_map_to_null(map);
		free(*map);
		*map = NULL;
	}
}

// ! Frees memory for a double character pointer
void	free_cells(char ***cells)
{
	size_t	index;

	if (cells && *cells)
	{
		index = 0;
		while ((*cells)[index])
			free((*cells)[index++]);
		free(*cells);
		*cells = NULL;
	}
}

// ! Frees memory for a linked list
void	free_list(t_list **head)
{
	t_list	*current;

	if (head)
	{
		while (*head)
		{
			current = *head;
			*head = (*head)->next;
			free(current->line);
			free(current);
		}
		*head = NULL;
	}
}
