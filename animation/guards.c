/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/20 16:18:04 by aheitz           ###   ########.fr       */
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
	display_character_texture(game, &game->graphics->guards->wait->front, game->map->last_position);
	display_and_disable_character(game, &game->graphics->guards->wait->left, game->map->last_position, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->wait->right, game->map->last_position, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->wait->back, game->map->last_position, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->block_left->short_range, game->map->last_position, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->block_left->medium_range, game->map->last_position, game->graphics->guards->count);
	display_and_disable_character(game, &game->graphics->guards->block_left->long_range, game->map->last_position, game->graphics->guards->count);
	++game->graphics->guards->count;
}

void	guard_waiting(t_game *game)
{
	int		probability;
	size_t	index;

	index = 0;
	if (game->graphics->guards->image == 5)
	{
		display_instances(game->graphics->guards->wait->back, game->graphics->guards->count, false);
		display_instances(game->graphics->guards->wait->front, game->graphics->guards->count, false);
		display_instances(game->graphics->guards->wait->left, game->graphics->guards->count, false);
		display_instances(game->graphics->guards->wait->right, game->graphics->guards->count, false);
		while (index < game->graphics->guards->count)
		{
			probability = rand() % 100;
			if (probability < 25)
			{
				//game->graphics->guards->wait->current->instances[index].enabled = false;
				game->graphics->guards->wait->back->instances[index++].enabled = true;
				//game->graphics->guards->wait->current = game->graphics->guards->wait->back;
			}
			else if (probability < 50)
			{
				//game->graphics->guards->wait->current->instances[index].enabled = false;
				game->graphics->guards->wait->front->instances[index++].enabled = true;
				//game->graphics->guards->wait->current = game->graphics->guards->wait->front;
			}
			else if (probability < 75)
			{
				//game->graphics->guards->wait->current->instances[index].enabled = false;
				game->graphics->guards->wait->left->instances[index++].enabled = true;
				//game->graphics->guards->wait->current = game->graphics->guards->wait->left;
			}
			else
			{
				//game->graphics->guards->wait->current->instances[index].enabled = false;
				game->graphics->guards->wait->right->instances[index++].enabled = true;
				//game->graphics->guards->wait->current = game->graphics->guards->wait->right;
			}
		}
		game->graphics->guards->image = 0;
	}
	else
		++game->graphics->guards->image;
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

void	block(t_game *game)
{
	
}

// void	spanish_stops_player(t_game *game)
// {
// 	stop_waiting(game);
// 	if (game->day % 6 == 0)
// 	{
// 		display_instances(game->graphics->left_spanish->block->first, 1, true);
// 		display_instances(game->graphics->left_spanish->block->second, 1, false);
// 		display_instances(game->graphics->left_spanish->block->third, 1, false);
// 	}
// 	else if (game->day % 4 == 0)
// 	{
// 		display_instances(game->graphics->left_spanish->block->first, 1, false);
// 		display_instances(game->graphics->left_spanish->block->second, 1, true);
// 		display_instances(game->graphics->left_spanish->block->third, 1, false);
// 	}
// 	else if (game->day % 2 == 0)
// 	{
// 		display_instances(game->graphics->left_spanish->block->first, 1, false);
// 		display_instances(game->graphics->left_spanish->block->second, 1, false);
// 		display_instances(game->graphics->left_spanish->block->third, 1, true);
// 	}
// }

// void	stop_blocking(t_game *game)
// {
// 	display_instances(game->graphics->left_spanish->block->first, 1, false);
// 	display_instances(game->graphics->left_spanish->block->second, 1, false);
// 	display_instances(game->graphics->left_spanish->block->third, 1, false);
// }

// void	stop_waiting(t_game *game)
// {
// 	display_instances(game->graphics->left_spanish->first, 1, false);
// 	display_instances(game->graphics->left_spanish->second, 1, false);
// 	display_instances(game->graphics->left_spanish->third, 1, false);
// 	display_instances(game->graphics->left_spanish->fourth, 1, false);
// 	display_instances(game->graphics->left_spanish->fifth, 1, false);
// }

int	is_player_near(t_game *game)
{
	int	y;
	int	x;

	position = allocate(game, sizeof(t_position), 0); // TODO CHANGER ERREUR
	y = -3;
	x = -3;
	while (y < 4)
	{
		while (x < 4)
		if (game->character->position->y / 64 == game-> - 1)
			return (1);
	}
		
	return (0);
}

int	is_guards_near(t_game *game)
{
	game->map->last_position->y = 0;
	while (game->map->last_position->y)
	{
		game->map->last_position->x = 0;
		while (game->map->cells[game->map->last_position->y][game->map->last_position->x])
		{
			if (is_inside(game->map->cells[game->map->last_position->y][game->map->last_position->x], "{}.|"))
			{
				
			}
			++game->map->last_position->x;
		}
		++game->map->last_position->y;
	}
	return (0);
}

int	is_near(t_game *game)
{
	int	distance_y;
	int	distance_x;

	distance_y = game->map->last_position->y - game->character->position->y;
	distance_x = game->map->last_position->x - game->character->position->x;
	if (distance_y < 3 && distance_x < 3)
		return (1);
}
