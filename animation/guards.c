/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 15:08:57 by aheitz           ###   ########.fr       */
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
	if (direction == RIGHT)
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
	if (direction == FRONT)
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
void	add_guard(t_game *game, t_blocking *blocking)
{
	intitialize_but_disable(game, game->graphics->guards->waiting->front, CHARACTER, game->graphics->guards->count);
	intitialize_but_disable(game, game->graphics->guards->waiting->left, CHARACTER, game->graphics->guards->count);
	intitialize_but_disable(game, game->graphics->guards->waiting->right, CHARACTER, game->graphics->guards->count);
	intitialize_but_disable(game, game->graphics->guards->waiting->back, CHARACTER, game->graphics->guards->count);
	intitialize_but_disable(game, blocking->short_range, BLOCKING, game->graphics->guards->count);
	intitialize_but_disable(game, blocking->medium_range, BLOCKING, game->graphics->guards->count);
	intitialize_but_disable(game, blocking->long_range, BLOCKING, game->graphics->guards->count);
	guard_waiting(game, game->graphics->guards, game->graphics->guards->count);
	++game->graphics->guards->count;
}

void	guard_waiting(t_game *game, t_guard *guard, size_t index)
{
	int		probability;

	if (is_stopping_blocking(guard, guard->left))
		return ;
	stop_waiting(guard); // !
	probability = rand() % 100;
	if (probability < 25)
		game->graphics->guards->waiting->back->instances[index].enabled = true;
	else if (probability < 50)
		game->graphics->guards->waiting->front->instances[index].enabled = true;
	else if (probability < 75)
		game->graphics->guards->waiting->left->instances[index].enabled = true;
	else
		game->graphics->guards->waiting->right->instances[index].enabled = true;
}

// ? Initializes an instance according to its type,
// ? then immediately disables it
void	intitialize_but_disable(t_game *game, mlx_image_t *image,
	t_texture texture, size_t index)
{
	if (texture == CHARACTER)
		mlx_image_to_window(game->window, image, game->map->position_scan->x
			* 64 + 8, game->map->position_scan->y * 64 + 8);
	else if (texture == BLOCKING)
		mlx_image_to_window(game->window, image, game->map->position_scan->x
			* 64 - 32, game->map->position_scan->y * 64 + 8);
	image->instances[index].enabled = false;
}

// ? Disables waiting instances to gradually stretch a guard's spear
void	guard_blocking(t_guard *guard, t_blocking *direction)
{
	if (direction->long_range->instances[guard->index].enabled)
		return ;
	else if (direction->medium_range->instances[guard->index].enabled)
		switch_an_instance(direction->medium_range,
			direction->long_range, guard->index);
	else if (direction->short_range->instances[guard->index].enabled)
		switch_an_instance(direction->short_range,
			direction->medium_range, guard->index);
	else
	{
		stop_waiting(guard);
		direction->short_range->instances[guard->index].enabled = true;
	}
}

// ? If a blocking image is enable, disables it.
int	is_stopping_blocking(t_guard *guard, t_blocking *direction)
{
	if (direction->long_range->instances[guard->index].enabled)
	{
		switch_an_instance(direction->long_range, direction->medium_range, guard->index);
		return (1);
	}
	else if (direction->medium_range->instances[guard->index].enabled)
	{
		switch_an_instance(direction->medium_range, direction->short_range, guard->index);
		return (1);
	}
	else if (direction->short_range->instances[guard->index].enabled)
	{
		direction->short_range->instances[guard->index].enabled = false;
		return (1);
	}
	return (0);
}

// ? Disables the previous instance to enables the next one
void	switch_an_instance(mlx_image_t *previous,
	mlx_image_t *next, size_t index)
{
	previous->instances[index].enabled = false;
	next->instances[index].enabled = true;
}

// ? If a waiting image is enable, disables it.
void	stop_waiting(t_guard *guard)
{
	if (guard->waiting->back->instances[guard->index].enabled)
		guard->waiting->back->instances[guard->index].enabled = false;
	else if (guard->waiting->front->instances[guard->index].enabled)
		guard->waiting->front->instances[guard->index].enabled = false;
	else if (guard->waiting->left->instances[guard->index].enabled)
		guard->waiting->left->instances[guard->index].enabled = false;
	else if (guard->waiting->right->instances[guard->index].enabled)
		guard->waiting->right->instances[guard->index].enabled = false;
}

// ? Checks whether the last distance is within the player's reach
int	is_player_near(t_game *game)
{
	int	distance_y;
	int	distance_x;

	distance_y = game->map->position_scan->y
		- game->character->position->y / 64;
	distance_x = game->map->position_scan->x
		- game->character->position->x / 64;
	if (distance_y < 4 && distance_y > -4 && distance_x < 4 && distance_x > -4)
		return (1);
	return (0);
}

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
	}
	else
		guard_waiting(game, game->graphics->guards, game->graphics->guards->index);
	++game->graphics->guards->index;
}
