/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:50:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 16:50:03 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Defines castle textures
void	set_castle(t_game *game)
{
	game->graphics->castle = allocation(game, sizeof(t_castle),
			UNALLOCATED_CASTLE);
	game->graphics->castle->count = 0;
	set_all_textures(game, 2, &game->graphics->castle->english,
		"./textures/castle/english.png", &game->graphics->castle->french,
		"./textures/castle/french.png");
}

// * Builds a castle in the current position
void	build_castle(t_game *game)
{
	set_animation(game, game->graphics->castle->count++, 1,
		game->graphics->castle->english, game->graphics->castle->french);
}

// * Changes castle color and reduces collectibles by 1
void	take_castle(t_game *game)
{
	switch_instances(game->graphics->castle->english,
		game->graphics->castle->french, get_image_index(game, 'C', NULL)); // TODO : POSITION DU JOUEUR A COINCIDER
	--game->map->collectibles;
}
