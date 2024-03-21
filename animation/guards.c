/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/21 16:52:27 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_guards_textures(t_game *game)
{
	game->graphics->guards = allocate(game, sizeof(t_guard), 0); // TODO CHANGER ERREUR
	game->graphics->guards->wait = allocate(game, sizeof(t_wait), 0); // TODO CHANGER ERREUR
	set_texture(game, &game->graphics->guards->wait->back, "./textures/guards/wait/back.png");
	set_texture(game, &game->graphics->guards->wait->front, "./textures/guards/wait/front.png");
	set_texture(game, &game->graphics->guards->wait->left, "./textures/guards/wait/left.png");
	set_texture(game, &game->graphics->guards->wait->right, "./textures/guards/wait/right.png");
	game->graphics->guards->block_left = allocate(game, sizeof(t_block), 0); // TODO CHANGER ERREUR
	set_texture(game, &game->graphics->guards->block_left->short_range, "./textures/guards/block/left/short.png");
	set_texture(game, &game->graphics->guards->block_left->medium_range, "./textures/guards/block/left/medium.png");
	set_texture(game, &game->graphics->guards->block_left->long_range, "./textures/guards/block/left/long.png");
	game->graphics->guards->count = 0;
	game->graphics->guards->image = 0;
}

void	add_guard(t_game *game)
{
	display_character_texture(game, &game->graphics->guards->wait->front, game->map->position_scan);
	display_and_disable_character(game, &game->graphics->guards->wait->left, game->map->position_scan, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->wait->right, game->map->position_scan, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->wait->back, game->map->position_scan, game->graphics->guards->count);
	display_and_disable_blocking(game, &game->graphics->guards->block_left->short_range, game->map->position_scan, game->graphics->guards->count);
	display_and_disable_blocking(game, &game->graphics->guards->block_left->medium_range, game->map->position_scan, game->graphics->guards->count);
	display_and_disable_blocking(game, &game->graphics->guards->block_left->long_range, game->map->position_scan, game->graphics->guards->count);
	++game->graphics->guards->count;
}

void	guard_waiting(t_game *game, t_guard *guard, size_t index)
{
	int		probability;

	stop_left_blocking(guard);
	stop_left_waiting(guard);
	probability = rand() % 100;
	if (probability < 25)
		game->graphics->guards->wait->back->instances[index].enabled = true;
	else if (probability < 50)
		game->graphics->guards->wait->front->instances[index].enabled = true;
	else if (probability < 75)
		game->graphics->guards->wait->left->instances[index].enabled = true;
	else
		game->graphics->guards->wait->right->instances[index].enabled = true;
}

void	display_character_texture(t_game *game, mlx_image_t **texture, t_position *position)
{
	mlx_image_to_window(game->window, *texture, position->x * 64 + 8, position->y * 64 + 8);
}

void	display_and_disable_character(t_game *game, mlx_image_t **image,
	t_position *position, size_t index)
{
	display_character_texture(game, image, position);
	(*image)->instances[index].enabled = false;
}

void	display_and_disable_blocking(t_game *game, mlx_image_t **image, t_position *position, size_t index)
{
	mlx_image_to_window(game->window, *image, position->x * 64 - 32, position->y * 64);
	(*image)->instances[index].enabled = false;
}

void	guard_left_blocking(t_guard *guard)
{
	if (guard->block_left->long_range->instances[guard->index].enabled)
		return ;
	else if (guard->block_left->medium_range->instances[guard->index].enabled)
		exchange_an_instance(guard->block_left->medium_range, guard->block_left->long_range, guard->index);
	else if (guard->block_left->short_range->instances[guard->index].enabled)
		exchange_an_instance(guard->block_left->short_range, guard->block_left->medium_range, guard->index);
	else
	{
		stop_left_waiting(guard);
		display_an_instance(guard->block_left->short_range, guard->index, true);
	}
}

void	stop_left_blocking(t_guard *guard)
{
	display_an_instance(guard->block_left->short_range, guard->index, false);
	display_an_instance(guard->block_left->medium_range, guard->index, false);
	display_an_instance(guard->block_left->long_range, guard->index, false);
}

void	exchange_an_instance(mlx_image_t *old, mlx_image_t *new, size_t index)
{
	display_an_instance(old, index, false);
	display_an_instance(new, index, true);
}

void	display_an_instance(mlx_image_t *target, size_t index, bool is_displayed)
{
	target->instances[index].enabled = is_displayed;
}

void	stop_left_waiting(t_guard *guard)
{
	if (guard->wait->back->instances[guard->index].enabled)
		display_an_instance(guard->wait->back, guard->index, false);
	else if (guard->wait->front->instances[guard->index].enabled)
		display_an_instance(guard->wait->front, guard->index, false);
	else if (guard->wait->left->instances[guard->index].enabled)
		display_an_instance(guard->wait->left, guard->index, false);
	else if (guard->wait->right->instances[guard->index].enabled)
		display_an_instance(guard->wait->right, guard->index, false);
}

int	is_player_near(t_game *game)
{
	int	distance_y;
	int	distance_x;

	distance_y = game->map->position_scan->y
		- game->character->position->y / 64;
	distance_x = game->map->position_scan->x
		- game->character->position->x / 64;
	if (distance_y < 3 && distance_y > -3 && distance_x < 3 && distance_x > -3)
		return (1);
	return (0);
}

void	guards_animation(t_game *game)
{
	++game->graphics->guards->image;
	if (game->graphics->guards->image != 5)
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
			if (game->graphics->guards->index == game->graphics->guards->count - 1)
			{
				game->graphics->guards->image = 0;
				return ;
			}
			++game->map->position_scan->x;
		}
		++game->map->position_scan->y;
	}
	game->graphics->guards->image = 0;
}

void	guard_order(t_game *game)
{
	if (is_player_near(game))
	{
		if (game->map->cells[game->map->position_scan->y][game->map->position_scan->x] == '{')
			guard_left_blocking(game->graphics->guards);
	}
	else
		guard_waiting(game, game->graphics->guards, game->graphics->guards->index);
	++game->graphics->guards->index;
}
