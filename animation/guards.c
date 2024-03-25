/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:27:48 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	guards_animation(t_game *game)
{
	++game->graphics->guards->current_frame;
	if (game->graphics->guards->current_frame != 5)
		return ;
	game->map->position_scan->y = 1;
	game->graphics->guards->index = 0;
	while (game->map->position_scan->y < game->map->height - 1)
	{
		game->map->position_scan->x = 1;
		while (game->map->position_scan->x < game->map->width)
		{
			if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], "{}.|"))
				guard_order(game);
			if (game->graphics->guards->index == game->graphics->guards->count)
			{
				game->graphics->guards->current_frame = 0;
				return ;
			}
			++game->map->position_scan->x;
		}
		++game->map->position_scan->y;
	}
	game->graphics->guards->current_frame = 0;
}

void	guard_order(t_game *game)
{
	if (is_player_near(game))
	{
		if (game->map->cells[game->map->position_scan->y][game->map->position_scan->x] == '{')
			guard_blocking(game->graphics->guards, game->graphics->guards->left);
		//else
		//	guard_blocking(game->graphics->guards, game->graphics->guards->back);
	}
	else
		guard_waiting(game, game->graphics->guards, game->graphics->guards->index);
	++game->graphics->guards->index;
}
