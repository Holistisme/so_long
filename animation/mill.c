/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:14:09 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/14 12:36:42 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Allocates and loads textures for the mill
void	load_mill_texture(t_game *game)
{
	game->graphics->mill = allocate(game, sizeof(t_mill), MILL_TEXTURE); //TODO : Changer le code d'erreur!
	set_texture(game, &game->graphics->mill->first,
		"./textures/mill_first.png");
	set_texture(game, &game->graphics->mill->second,
		"./textures/mill_second.png");
}

// ? Load the textures if they don't exist, add a mill to the counter,
// ? and end up displaying every texture while disabling the second
void	add_mill(t_game *game, size_t y, size_t x)
{
	if (!game->graphics->mill)
		load_mill_texture(game);
	++game->map->mills;
	{
		display_texture(game, &game->graphics->mill->first, y, x);
		display_texture(game, &game->graphics->mill->second, y, x);
		game->graphics->mill->second->instances
		[game->map->mills - 1].enabled = false;
	}
}

// ? For each pair of days, change the mill image to display the animation
void	mill_animation(t_game *game)
{
	int	index;

	index = 0;
	while (index <= game->map->mills)
	{
		if (game->day % 4 == 0)
		{
			game->graphics->mill->first->instances[index].enabled = false;
			game->graphics->mill->second->instances[index].enabled = true;
		}
		else if (game->day % 2 == 0)
		{
			game->graphics->mill->second->instances[index].enabled = false;
			game->graphics->mill->first->instances[index].enabled = true;
		}
		++index;
	}
}
