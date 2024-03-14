/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/28 11:34:09 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Checks that the number of key elements returned equals those on the path
void	check_pathway_validity(t_game *game)
{
	clone_cells(game);
	if (scan_pathway(game, game->map->spawn->x, game->map->spawn->y)
		!= game->map->collectibles + 1)
		error_occurred(game, 22);
	free_cells(&game->map->cloned_cells);
}

// ? Clones map cells
void	clone_cells(t_game *game)
{
	size_t	x;
	size_t	y;

	game->map->cloned_cells = allocate(game, sizeof(char *)
			* (game->map->height + 1), 20);
	y = 0;
	while (game->map->cells[y])
	{
		x = 0;
		game->map->cloned_cells[y] = NULL;
		game->map->cloned_cells[y] = allocate(game, game->map->width + 1, 21);
		while (game->map->cells[y][x])
		{
			game->map->cloned_cells[y][x] = game->map->cells[y][x];
			++x;
		}
		game->map->cloned_cells[y][x] = 0;
		++y;
	}
	game->map->cloned_cells[y] = NULL;
}

// ? Returns the number of elements reachable from the spawn
int	scan_pathway(t_game *game, size_t x, size_t y)
{
	int	reachable_items;

	reachable_items = 0;
	if (game->map->cloned_cells[y][x] == 'C' ||
		game->map->cloned_cells[y][x] == 'E')
		++reachable_items;
	game->map->cloned_cells[y][x] = '1';
	if (!is_inside(game->map->cloned_cells[y + 1][x], "123X"))
		reachable_items += scan_pathway(game, x, y + 1);
	if (!is_inside(game->map->cloned_cells[y - 1][x], "123X"))
		reachable_items += scan_pathway(game, x, y - 1);
	if (!is_inside(game->map->cloned_cells[y][x + 1], "123X"))
		reachable_items += scan_pathway(game, x + 1, y);
	if (!is_inside(game->map->cloned_cells[y][x - 1], "123X"))
		reachable_items += scan_pathway(game, x - 1, y);
	return (reachable_items);
}

// ? Returns 1 if the character is found in the string. Otherwise 0.
int	is_inside(char c, char *string)
{
	size_t	scan;

	scan = 0;
	while (string[scan])
		if (c == string[scan++])
			return (1);
	return (0);
}
