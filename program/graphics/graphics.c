/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:07:17 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 16:36:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

void	set_focus(t_game *game, t_focus **focus, int x, int y)
{
	// TODO VERIFIER SANS ADRESSE
	(*focus) = allocation(game, sizeof(t_focus), UNALLOCATED_FOCUS);
	(*focus)->x = x;
	(*focus)->y = y;
}

void	set_graphics_to_null(t_graphics	*graphics)
{
	graphics->castle = NULL;
	graphics->ground = NULL;
	graphics->paris = NULL;
	graphics->background_focus = NULL;
}

// ? Initializes the map's mandatory textures
void	basic_textures_initialization(t_game *game)
{
	set_texture(game, &game->graphics->limit, "./textures/limit.png");
	set_castle(game);
	set_paris(game);
	set_ground(game);
	set_focus(game, &game->graphics->background_focus, 64, 64);
	// TODO : AJOUTER LE SPAWN QUI EST ACT>GRASS
}

// ? Traverses cells and calls subfunctions to load graphics
void	load_graphics(t_game *game)
{
	game->map->current_position->y = 0;
	while (game->map->cells[game->map->current_position->y])
	{
		game->map->current_position->x = 0;
		while (game->map->cells[game->map->current_position->y]
			[game->map->current_position->x])
		{
			if (is_inside(game->map->cells[game->map->current_position->y]
					[game->map->current_position->x], "0PCE"))
			{
				set_animation(game,
					game->graphics->ground->simple_grass->count++, 2,
					game->graphics->ground->snow,
					game->graphics->ground->simple_grass->dark,
					game->graphics->ground->simple_grass->light);
				load_element(game);
			}
			else
				display_texture(game, game->graphics->limit,
					game->map->current_position,
					game->graphics->background_focus);
			++game->map->current_position->x;
		}
		++game->map->current_position->y;
	}
}

void	load_element(t_game *game)
{
	if (game->map->cells[game->map->current_position->y]
		[game->map->current_position->x] == 'C')
		build_castle(game);
	else if (game->map->cells[game->map->current_position->y]
		[game->map->current_position->x] == 'E')
		build_paris(game);
}

// ? Simplifies the display of a graphic
void	display_texture(t_game *game, mlx_image_t *image, t_position *position,
	t_focus *focus)
{
	mlx_image_to_window(game->window, image, position->x * focus->x, position->y
		* focus->y);
}
