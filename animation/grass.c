/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:49:48 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 16:44:30 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Manages new grass entries
void	new_grass(t_game *game, t_position *position, char c)
{
	if (c == 'L')
	{
		if (!game->graphics->ground->left_grass)
			grass_initilization(game, &game->graphics->ground->left_grass,
				"./textures/grass/left_dark", "./textures/grass/left_light");
		add_grass(game, &game->graphics->ground->left_grass, position);
	}
	if (c == 'R')
	{
		if (!game->graphics->ground->right_grass)
			grass_initilization(game, &game->graphics->ground->right_grass,
				"./textures/grass/right_dark", "./textures/grass/right_light");
		add_grass(game, &game->graphics->ground->right_grass, position);
	}
	else
		add_grass(game, &game->graphics->ground->simple_grass, position);
	++game->graphics->ground->count;
	display_texture(game, &game->graphics->ground->snow, position);
}

// ? Initialize graphics for a grass
void	grass_initilization(t_game *game, t_grass **grass,
	const char *dark, const char *light)
{
	(*grass) = NULL;
	(*grass) = allocate(game, sizeof(t_grass), GRASS_TEXTURE); //TODO : Changer le code d'erreur!
	(*grass)->count = 0;
	set_texture(game, &(*grass)->dark, dark);
	set_texture(game, &(*grass)->light, light);
}

// ? Adds the two colored grass graphics to the map
void	add_grass(t_game *game, t_grass **grass,
						t_position *position)
{
	++(*grass)->count;
	display_and_disable(game, &(*grass)->dark, position, (*grass)->count - 1);
	display_and_disable(game, &(*grass)->light, position, (*grass)->count - 1);
}
