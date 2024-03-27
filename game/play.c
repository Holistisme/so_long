/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:26:36 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 18:00:28 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include <stdio.h>

void	move_request(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
		mlx_close_window(game->window);
	if (mlx_is_key_down(game->window, MLX_KEY_W) && !is_inside(game->map->cells[(game->character->position->y - 1) / 64][game->character->position->x / 64], "X1234"))
	{
		game->character->position->y -= 4;
		game->character->skin->instances[0].y -= 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S) && !is_inside(game->map->cells[(game->character->position->y + 1) / 64][game->character->position->x / 64], "X1234"))
	{
		game->character->position->y += 4;
		game->character->skin->instances[0].y += 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x - 1) / 64], "X1234"))
	{
		game->character->position->x -= 4;
		game->character->skin->instances[0].x -= 4;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D) && !is_inside(game->map->cells[game->character->position->y / 64][(game->character->position->x + 1) / 64], "X1234"))
	{
		game->character->position->x += 4;
		game->character->skin->instances[0].x += 4;
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

// * Initializes the latest data for game launch
void	set_game(t_game *game)
{
	pthread_t	animation;

	open_window(game);
	game->map->mills = 0;
	game->graphics = allocate(game, sizeof(t_graphics), 0); // TODO CHANGER ERREUR
	game->graphics->ground = allocate(game, sizeof(t_ground), 0); // TODO CHANGER ERREUR
	game->graphics->ground->count = 0;
	//game->graphics->month = allocate(game, sizeof(t_month), 0); // TODO CHANGER ERREUR
	//game->graphics->month->position = allocate(game, sizeof(t_position), MILL_TEXTURE); //TODO : Changer le code d'erreur!
	//game->graphics->month->position->y = 0;
	//game->graphics->month->position->x = game->map->width / 2 - 1;
	game->graphics->mill = NULL;
	game->graphics->field = NULL;
	game->graphics->ground->simple_grass = NULL;
	game->graphics->ground->left_grass = NULL;
	game->graphics->ground->right_grass = NULL;
	game->graphics->guards = NULL;
	grass_initilization(game, &game->graphics->ground->simple_grass, "./textures/grass/simple_dark.png", "./textures/grass/simple_light.png");
	set_graphics(game);
	set_castle_textures(game);
	set_paris_textures(game);
	set_borders_textures(game);
	set_moutains_textures(game);
	game->day = 0;
	load_graphics(game);
	set_character(game);
	pthread_create(&animation, NULL, start_animation, game);
	mlx_key_hook(game->window, move_request, game);
	mlx_loop(game->window);
}
