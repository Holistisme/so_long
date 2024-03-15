/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:14:09 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 15:26:20 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Allocates and loads textures for the mill
void	load_mills_textures(t_game *game)
{
	game->graphics->mill = allocate(game, sizeof(t_mill), MILL_TEXTURE); //TODO : Changer le code d'erreur!
	set_texture(game, &game->graphics->mill->first,
		"./textures/mill_first.png");
	set_texture(game, &game->graphics->mill->second,
		"./textures/mill_second.png");
}

// ? Load the textures if they don't exist, add a mill to the counter,
// ? and end up displaying every texture while disabling the second
void	add_mill(t_game *game, t_position *position)
{
	if (!game->graphics->mill)
		load_mills_textures(game);
	++game->map->mills;
	display_texture(game, &game->graphics->mill->first, position);
	display_and_disable(game, &game->graphics->mill->second,
		position, game->map->mills - 1);
}

// ? For each pair of days, change the mill image to display the animation
void	mill_animation(t_game *game)
{
	if (game->day % 4 == 0)
		exchange_textures(game->graphics->mill->first,
			game->graphics->mill->second, game->map->mills);
	else if (game->day % 2 == 0)
		exchange_textures(game->graphics->mill->second,
			game->graphics->mill->first, game->map->mills);
}
