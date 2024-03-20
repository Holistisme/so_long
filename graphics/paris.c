/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:33:20 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 16:33:43 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_paris_textures(t_game *game)
{
	game->graphics->paris = NULL; // ? PARIS = CASTLE ??
	game->graphics->paris = allocate(game, sizeof(t_paris), 0); //TODO : NOUVEAU CODE
	set_texture(game, &game->graphics->paris->english,
		"./textures/paris/english.png");
	set_texture(game, &game->graphics->paris->french,
		"./textures/paris/french.png");
}

void	take_paris(t_game *game)
{
	game->graphics->paris->english->instances->enabled = false;
	game->graphics->paris->french->instances->enabled = true;
	//? POSSIBLE AUCUNE BOUCLE ?
}
