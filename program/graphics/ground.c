/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:49:48 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 17:03:13 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Prepare the ground and define the most rudimentary textures
void	set_ground(t_game *game)
{
	game->graphics->ground = allocation(game, sizeof(t_ground),
			UNALLOCATED_GROUND);
	game->graphics->ground->left_grass = NULL;
	game->graphics->ground->right_grass = NULL;
	game->graphics->ground->simple_grass = NULL;
	game->graphics->ground->count = 0;
	set_texture(game, &game->graphics->ground->snow,
		"./textures/ground/snow.png");
	set_grass(game, &game->graphics->ground->simple_grass,
		"./textures/ground/grass/simple/dark.png",
		"./textures/ground/grass/simple/light.png");
}

// * Add the three basic ground textures to the map,
// * playing with chance to improve rendering.
void	build_random_grass(t_game *game)
{
	int	probability;

	probability = rand() % 100;
	if (probability < 5)
		set_grass_animation(game, &game->graphics->ground->left_grass,
			"./textures/ground/grass/left/dark.png",
			"./textures/ground/grass/left/light.png");
	else if (probability < 10)
		set_grass_animation(game, &game->graphics->ground->right_grass,
			"./textures/ground/grass/right/dark.png",
			"./textures/ground/grass/right/light.png");
	else
		set_animation(game, game->graphics->ground->simple_grass->count++, 3,
			game->graphics->ground->snow,
			game->graphics->ground->simple_grass->dark,
			game->graphics->ground->simple_grass->light);
	++game->graphics->ground->count;
}

// ? Defines a grass textures
void	set_grass(t_game *game, t_grass **grass, const char *dark,
	const char *light)
{
	(*grass) = allocation(game, sizeof(t_grass), UNALLOCATED_GRASS);
	(*grass)->count = 0;
	set_all_textures(game, 2, &(*grass)->dark, dark, &(*grass)->light, light);
}

// ? If nonexistent, allocate memory and textures for grass,
// ? before pre-displaying it.
void	set_grass_animation(t_game *game, t_grass **grass, const char *dark,
	const char *light)
{
	if (!grass || !*grass)
		set_grass(game, grass, dark, light);
	set_animation(game, (*grass)->count++, 3, game->graphics->ground->snow,
		(*grass)->dark, (*grass)->light);
}
