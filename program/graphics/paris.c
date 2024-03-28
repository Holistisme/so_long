/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:33:20 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 16:56:14 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Defines Paris textures
void	set_paris(t_game *game)
{
	game->graphics->paris = allocation(game, sizeof(t_paris),
			UNALLOCATED_PARIS);
	set_all_textures(game, 2, &game->graphics->paris->english,
		"./textures/paris/english.png", &game->graphics->paris->french,
		"./textures/paris/french.png");
}

// * Builds Paris in the current position
void	build_paris(t_game *game)
{
	set_animation(game, 0, 1, game->graphics->paris->english,
		game->graphics->paris->french);
}

// * Changes Paris color and exits the game
void	take_paris(t_game *game)
{
	switch_instances(game->graphics->castle->english,
		game->graphics->castle->french, 0);
	// TODO : CODER SORTIE
}
