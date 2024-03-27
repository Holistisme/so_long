/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:46:39 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:15:05 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Checks that the number of key elements returned equals those on the path
void	check_pathway_validity(t_game *game)
{
	clone_cells(game);
	if (scan_pathway(game, game->map->spawn->y, game->map->spawn->x)
		!= game->map->collectibles + 1)
		error_occurred(game, INVALID_PATHWAY);
	free_cells(&game->map->cloned_cells);
}

// ? Clones map cells
void	clone_cells(t_game *game)
{
	game->map->cloned_cells = allocation(game, sizeof(char *)
			* (game->map->height + 1), UNALLOCATED_CLONED_CELLS);
	game->map->current_position->y = 0;
	while (game->map->cells[game->map->current_position->y])
	{
		game->map->current_position->x = 0;
		game->map->cloned_cells[game->map->current_position->y] = NULL;
		game->map->cloned_cells[game->map->current_position->y]
			= allocation(game, game->map->width + 1, UNALLOCATED_CLONED_LINE);
		while (game->map->cells[game->map->current_position->y]
			[game->map->current_position->x])
		{
			game->map->cloned_cells[game->map->current_position->y]
			[game->map->current_position->x] = game->map->cells
			[game->map->current_position->y]
			[game->map->current_position->x];
			++game->map->current_position->x;
		}
		game->map->cloned_cells[game->map->current_position->y]
		[game->map->current_position->x] = '\0';
		++game->map->current_position->y;
	}
	game->map->cloned_cells[game->map->current_position->y] = NULL;
}

// ? Returns the number of elements reachable from the spawn
int	scan_pathway(t_game *game, size_t y, size_t x)
{
	int	reachable_items;

	reachable_items = 0;
	if (is_inside(game->map->cloned_cells[y][x], "CE"))
		++reachable_items;
	game->map->cloned_cells[y][x] = '1';
	if (!is_inside(game->map->cloned_cells[y + 1][x], "1"))
		reachable_items += scan_pathway(game, y + 1, x);
	if (!is_inside(game->map->cloned_cells[y - 1][x], "1"))
		reachable_items += scan_pathway(game, y - 1, x);
	if (!is_inside(game->map->cloned_cells[y][x + 1], "1"))
		reachable_items += scan_pathway(game, y, x + 1);
	if (!is_inside(game->map->cloned_cells[y][x - 1], "1"))
		reachable_items += scan_pathway(game, y, x - 1);
	return (reachable_items);
}
