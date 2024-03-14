/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:25:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/14 12:59:41 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Initializes the latest data for game launch
void	set_game(t_game *game)
{
	pthread_t	animation;

	open_window(game);
	game->map->mills = 0;
	game->map->grass_counter = allocate(game, sizeof(t_path_counter), GRASS_COUNTER); //TODO : Changer le code d'erreur!
	game->map->grass_counter->grass = 0;
	game->map->grass_counter->grass_left = 0;
	game->map->grass_counter->grass_right = 0;
	game->graphics = allocate(game, sizeof(t_graphics), GRAPHICS_ALLOCATION);
	game->graphics->field = allocate(game, sizeof(t_field), 0); // TODO CHANGER ERREUR
	game->graphics->month = allocate(game, sizeof(t_month), 0); // TODO CHANGER ERREUR
	game->graphics->mill = NULL; // ! Verifier si necessaire!
	game->graphics->grass = NULL; // ! Verifier si necessaire!
	set_graphics(game);
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
	game->window = mlx_init(game->map->width * 64,
			game->map->height * 64, "Journey of Joan Of Arc", true);
	if (!game->window)
		error_occurred(game, WINDOW_ALLOCATION);
}
