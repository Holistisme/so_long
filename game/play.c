/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:36 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/11 13:41:31 by aheitz           ###   ########.fr       */
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
		game->character->position->y -= 4;
		game->character->current_skin->instances[0].y -= 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S) && !is_inside(game->map->cells[(game->character->position->y + 1) / 64][game->character->position->x / 64], "X1234"))
	{
		game->character->position->y += 4;
		game->character->current_skin->instances[0].y += 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x - 1) / 64], "X1234"))
	{
		game->character->position->x -= 4;
		game->character->current_skin->instances[0].x -= 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x + 1) / 64], "X1234"))
	{
		game->character->position->x += 4;
		game->character->current_skin->instances[0].x += 4;
	}
	//check_case(game);
	//game->character->current_skin = game->character->skin_tab[game->character->skin_index++];
	//if (game->character->skin_index == 4)
	//	game->character->skin_index = 0;
	//display_texture(game, &game->character->current_skin, game->map->spawn->y, game->map->spawn->x);
	//usleep(1000);
	(void)key_data.action; // ! SHEIZ! ERIKA
}

void	set_character(t_game *game)
{
	game->character = allocate(game, sizeof(t_character), CHARACTER_ALLOCATION);
	game->character->position = allocate(game, sizeof(t_position), POSITION_ALLOCATION);
	game->character->skin_tab = allocate(game, sizeof(mlx_image_t) * 4, 0); //! CODE A CHANGER
	game->character->position->x = game->map->spawn->x * 64;
	game->character->position->y = game->map->spawn->y * 64;
	set_texture(game, &game->character->skin_tab[0], "./textures/joan_down1.png");
	set_texture(game, &game->character->skin_tab[1], "./textures/joan_down2.png");
	set_texture(game, &game->character->skin_tab[2], "./textures/joan_down3.png");
	set_texture(game, &game->character->skin_tab[3], "./textures/joan_down4.png");
	game->character->skin_index = 0;
	game->character->current_skin = game->character->skin_tab[game->character->skin_index];
	display_texture(game, &game->character->current_skin, game->map->spawn->y, game->map->spawn->x);
}

