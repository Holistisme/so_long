/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:42:35 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/20 15:48:13 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Goes through the cells to check the authenticity of each position, 
// * then calls to save them.
void	scan_cells_elements(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (game->map->cells[y + 1])
	{
		x = 1;
		while (game->map->cells[y][x + 1])
		{
			if (!is_inside(game->map->cells[y][x], "01234abcdefCPEXUIOHJKLQWRTYASDFGZVMB^.|{}"))
				error_occurred(game, 13);
			save_element(game, x++, y);
		}
		++y;
	}
}

// ? Registers collectable elements or calls to register key positions
void	save_element(t_game *game, size_t x, size_t y)
{
	if (game->map->cells[y][x] == 'C')
		++game->map->collectibles;
	else if (game->map->cells[y][x] == 'P')
		define_key_position(game, &game->map->spawn, x, y);
	else if (game->map->cells[y][x] == 'E')
		define_key_position(game, &game->map->exit, x, y);
}

// ? Saves the position of a key element. If it already exists, returns an error
void	define_key_position(t_game *game, t_position **pos, size_t x, size_t y)
{
	if (*pos)
	{
		if (*pos == game->map->spawn)
			error_occurred(game, 15);
		else if (*pos == game->map->exit)
			error_occurred(game, 16);
	}
	(*pos) = NULL;
	(*pos) = allocate(game, sizeof(t_position), 14);
	(*pos)->x = x;
	(*pos)->y = y;
}

// ? Check that there is a position for each key position,
// ? and at least one collectible.
void	check_if_game_is_complet(t_game *game)
{
	if (!game->map->collectibles)
		error_occurred(game, 17);
	else if (!game->map->spawn)
		error_occurred(game, 18);
	else if (!game->map->exit)
		error_occurred(game, 19);
}
