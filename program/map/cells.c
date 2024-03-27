/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:10:20 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:38:32 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Generates the cells of the map
void	set_cells(t_game *game)
{
	t_list	*current;
	size_t	index;

	index = 0;
	game->map->cells = allocation(game, sizeof(char *)
			* (game->map->height + 1), UNALLOCATED_CELLS);
	current = game->map->gnl_map;
	while (current)
	{
		copy_line_into_cell(game, index++, current->line);
		current = current->next;
	}
	game->map->cells[index] = NULL;
	free_list(&game->map->gnl_map);
}

// ? Saves the map positions up to the newline character
void	copy_line_into_cell(t_game *game, size_t y, char *current_line)
{
	size_t	index;

	index = 0;
	game->map->cells[y] = NULL;
	game->map->cells[y] = allocation(game, game->map->width + 1,
			UNALLOCATED_CELL);
	while (current_line[index] && current_line[index] != '\n')
	{
		game->map->cells[y][index] = current_line[index];
		++index;
	}
	game->map->cells[y][index] = '\0';
}
