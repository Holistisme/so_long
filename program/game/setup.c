/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:54:43 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 18:04:48 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Initializes the latest data for game launch
void	set_game(t_game *game)
{
	pthread_t	animation;

	open_window(game);
	//game->map->mills = 0;
	game->graphics = allocate(game, sizeof(t_graphics), UNALLOCATED_GRAPHICS);
	//game->graphics->ground = allocate(game, sizeof(t_ground), 0); // TODO CHANGER ERREUR
	//game->graphics->ground->count = 0;
	//game->graphics->month = allocate(game, sizeof(t_month), 0); // TODO CHANGER ERREUR
	//game->graphics->month->position = allocate(game, sizeof(t_position), MILL_TEXTURE); //TODO : Changer le code d'erreur!
	//game->graphics->month->position->y = 0;
	//game->graphics->month->position->x = game->map->width / 2 - 1;
	//game->graphics->mill = NULL;
	//game->graphics->field = NULL;
	//game->graphics->ground->simple_grass = NULL;
	//game->graphics->ground->left_grass = NULL;
	//game->graphics->ground->right_grass = NULL;
	//game->graphics->guards = NULL;
	//grass_initilization(game, &game->graphics->ground->simple_grass, "./textures/grass/simple_dark.png", "./textures/grass/simple_light.png");
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

// ? Allocates game window opening according to map size
void	open_window(t_game *game)
{
	game->window = mlx_init(game->map->width * 64, game->map->height * 64,
			"pucelle.exe", true);
	if (!game->window)
		error_occurred(game, UNALLOCATED_WINDOW);
}
