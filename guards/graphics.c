/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:22:57 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:24:28 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Allocates and defines the textures of waiting guards.
// ? Initializes the rest to null.
void	set_guards_textures(t_game *game)
{
	game->graphics->guards = allocate(game, sizeof(t_guard), GUARDS_ALLOCATION);
	game->graphics->guards->waiting = NULL;
	game->graphics->guards->waiting = allocate(game, sizeof(t_waiting),
			GUARDS_WAITING_ALLOCATION);
	set_texture(game, &game->graphics->guards->waiting->back,
		"./textures/guards/waiting/back.png");
	set_texture(game, &game->graphics->guards->waiting->front,
		"./textures/guards/waiting/front.png");
	set_texture(game, &game->graphics->guards->waiting->left,
		"./textures/guards/waiting/left.png");
	set_texture(game, &game->graphics->guards->waiting->right,
		"./textures/guards/waiting/right.png");
	game->graphics->guards->back = NULL;
	game->graphics->guards->front = NULL;
	game->graphics->guards->left = NULL;
	game->graphics->guards->right = NULL;
	game->graphics->guards->count = 0;
	game->graphics->guards->current_frame = 0;
	game->graphics->guards->index = 0;
}

// ? Allocates and defines lateral blocking textures according to direction
void	set_lateral_side_blocking_textures(t_game *game,
	t_blocking **blocking, t_direction direction)
{
	*blocking = allocate(game, sizeof(t_blocking), BLOCKING_ALLOCATION);
	if (direction == LEFT)
	{
		set_texture(game, &(*blocking)->short_range,
			"./textures/guards/blocking/left/short.png");
		set_texture(game, &(*blocking)->medium_range,
			"./textures/guards/blocking/left/medium.png");
		set_texture(game, &(*blocking)->long_range,
			"./textures/guards/blocking/left/long.png");
	}
	else if (direction == RIGHT)
	{
		set_texture(game, &(*blocking)->short_range,
			"./textures/guards/blocking/right/short.png");
		set_texture(game, &(*blocking)->medium_range,
			"./textures/guards/blocking/right/medium.png");
		set_texture(game, &(*blocking)->long_range,
			"./textures/guards/blocking/right/long.png");
	}
}

// ? Allocates and defines vertical blocking textures according to direction
void	set_vertical_side_blocking_textures(t_game *game,
	t_blocking **blocking, t_direction direction)
{
	*blocking = allocate(game, sizeof(t_blocking), BLOCKING_ALLOCATION);
	if (direction == BACK)
	{
		set_texture(game, &(*blocking)->short_range,
			"./textures/guards/blocking/back/short.png");
		set_texture(game, &(*blocking)->medium_range,
			"./textures/guards/blocking/back/medium.png");
		set_texture(game, &(*blocking)->long_range,
			"./textures/guards/blocking/back/long.png");
	}
	else if (direction == FRONT)
	{
		set_texture(game, &(*blocking)->short_range,
			"./textures/guards/blocking/front/short.png");
		set_texture(game, &(*blocking)->medium_range,
			"./textures/guards/blocking/front/medium.png");
		set_texture(game, &(*blocking)->long_range,
			"./textures/guards/blocking/front/long.png");
	}
}

// ! Adds all disabled images from a guard while keeping one on the map.
void	add_guard(t_game **game, t_blocking **blocking)
{
	intitialize_but_disable(game, &(*game)->graphics->guards->waiting->front, CHARACTER, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*game)->graphics->guards->waiting->left, CHARACTER, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*game)->graphics->guards->waiting->right, CHARACTER, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*game)->graphics->guards->waiting->back, CHARACTER, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*blocking)->short_range, BLOCKING, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*blocking)->medium_range, BLOCKING, (*game)->graphics->guards->count);
	intitialize_but_disable(game, &(*blocking)->long_range, BLOCKING, (*game)->graphics->guards->count);
	++(*game)->graphics->guards->count;
}
