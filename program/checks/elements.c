/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:15:40 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:13:50 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Goes through the cells to check the authenticity of each position, 
// * then calls to save them.
void	scan_cells_elements(t_game *game)
{
	game->map->current_position = allocation(game, sizeof(t_position),
			UNALLOCATED_POSITION);
	game->map->collectibles = 0;
	game->map->current_position->y = 1;
	while (game->map->cells[game->map->current_position->y + 1])
	{
		game->map->current_position->x = 1;
		while (game->map->cells[game->map->current_position->y]
			[game->map->current_position->x + 1])
		{
			if (!is_inside(game->map->cells[game->map->current_position->y]
					[game->map->current_position->x], "01CPE"))
				error_occurred(game, UNRECOGNISED_ELEMENT);
			save_element(game);
			game->map->current_position->x++;
		}
		++game->map->current_position->y;
	}
}

// ? Checks that there is a position for each key position,
// ? and at least one collectible.
void	check_if_game_is_complet(t_game *game)
{
	if (!game->map->collectibles)
		error_occurred(game, NO_COLLECTIBLE);
	else if (!game->map->spawn)
		error_occurred(game, NO_SPAWN);
	else if (!game->map->exit)
		error_occurred(game, NO_EXIT);
}

// ? Registers elements or calls to register key positions
void	save_element(t_game *game)
{
	if (game->map->cells[game->map->current_position->y]
		[game->map->current_position->x] == 'C')
		++game->map->collectibles;
	else if (game->map->cells[game->map->current_position->y]
		[game->map->current_position->x] == 'P')
		define_key_position(game, &game->map->spawn);
	else if (game->map->cells[game->map->current_position->y]
		[game->map->current_position->x] == 'E')
		define_key_position(game, &game->map->exit);
}

// ? Saves the position of a key element. If it already exists, returns an error
void	define_key_position(t_game *game, t_position **pos)
{
	if (pos && *pos)
	{
		if (*pos == game->map->spawn)
			error_occurred(game, MULTIPLE_SPAWN);
		else if (*pos == game->map->exit)
			error_occurred(game, MULTIPLE_EXIT);
	}
	(*pos) = allocation(game, sizeof(t_position), UNALLOCATED_POSITION);
	(*pos)->y = game->map->current_position->y;
	(*pos)->x = game->map->current_position->x;
}
