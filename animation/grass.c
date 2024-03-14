/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grass.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:49:48 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/14 13:08:41 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_grass_texture(t_game *game)
{
	game->graphics->grass = allocate(game, sizeof(t_grass_path), GRASS_TEXTURE); //TODO : Changer le code d'erreur!
	set_texture(game, &game->graphics->grass->simple,
		"./textures/grass_simple.png");
	set_texture(game, &game->graphics->snow,
		"./textures/snow.png");
}

void	add_grass(t_game *game, size_t y, size_t x, char c)
{
	if (!game->graphics->grass)
		load_grass_texture(game);
	if (c == '')
	++game->map->mills;
	{
		display_texture(game, &game->graphics->mill->first, y, x);
		display_texture(game, &game->graphics->mill->second, y, x);
		game->graphics->mill->second->instances
		[game->map->mills - 1].enabled = false;
	}
}

void	grass_generation(t_game *game)
{
	int	index;

	index = 0;
	while (index <= game->map->grass)
	{
		game->graphics->grass->spring->instances[index].enabled = false;
		game->graphics->grass->summer->instances[index].enabled = false;
		++index;
	}
}

void	grass_animation(t_game *game)
{
	int	index;

	index = 0;
	while (index <= game->map->grass)
	{
		if (game->day < 60 || game->day > 300)
		{
			game->graphics->grass->spring->instances[index].enabled = false;
			game->graphics->grass->winter->instances[index].enabled = true;
		}
		else if (game->day > 240 || (game->day < 120 && game->day > 60))
		{
			game->graphics->grass->summer->instances[index].enabled = false;
			game->graphics->grass->winter->instances[index].enabled = false;
			game->graphics->grass->spring->instances[index].enabled = true;
		}
		else if (game->day > 120)
		{
			game->graphics->grass->winter->instances[index].enabled = false;
			game->graphics->grass->summer->instances[index].enabled = true;
		}
		++index;
	}
}
