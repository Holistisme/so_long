/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:36 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 10:50:00 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include <stdio.h>

void	start_game(t_game *game)
{
	set_game(game);
}

void	move_request(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
		mlx_close_window(game->window);
	if (mlx_is_key_down(game->window, MLX_KEY_W) && !is_inside(game->map->cells[(game->character->position->y - 1) / 64][game->character->position->x / 64], "X1234"))
	{
		game->character->position->y -= 64;
		game->character->skin->instances[0].y -= 64;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S) && !is_inside(game->map->cells[(game->character->position->y + 1) / 64][game->character->position->x / 64], "X1234"))
	{
		game->character->position->y += 64;
		game->character->skin->instances[0].y += 64;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x - 1) / 64], "X1234"))
	{
		game->character->position->x -= 64;
		game->character->skin->instances[0].x -= 64;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x + 1) / 64], "X1234"))
	{
		game->character->position->x += 64;
		game->character->skin->instances[0].x += 64;
	}
	if (game->map->cells[(game->character->position->y / 64)][(game->character->position->x / 64)] == 'C' && game->graphics->castle->english->instances[get_castle_index(game)].enabled)
	{
		take_castle(game);
		--game->map->collectibles;
	}
	if (game->map->cells[(game->character->position->y / 64)][(game->character->position->x / 64)] == 'E' && game->map->collectibles == 0)
		take_paris(game);
	(void)key_data.action; // ! SHEIZ! ERIKA
}

void	set_character(t_game *game)
{
	t_position *position = allocate(game, sizeof(t_position), 0); // ! A FREE
	game->character = NULL;
	game->character = allocate(game, sizeof(t_character), CHARACTER_ALLOCATION);
	game->character->position = NULL;
	game->character->position = allocate(game, sizeof(t_position), POSITION_ALLOCATION);
	set_texture(game, &game->character->skin, "./textures/joan_down1.png"); //! CODE A CHANGER
	position->x = game->map->spawn->x;
	position->y = game->map->spawn->y;
	display_texture(game, &game->character->skin, position);
	game->character->position->x = game->map->spawn->x * 64;
	game->character->position->y = game->map->spawn->y * 64;
}
