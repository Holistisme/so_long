/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mountains.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:43:13 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 16:08:13 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_moutains_textures(t_game *game)
{
	game->graphics->mountain = NULL;
	game->graphics->mountain = allocate(game, sizeof(t_mountain), 0); //TODO : NOUVEAU CODE
	set_texture(game, &game->graphics->mountain->left,
		"./textures/mountains/left.png");
	set_texture(game, &game->graphics->mountain->middle,
		"./textures/mountains/middle.png");
	set_texture(game, &game->graphics->mountain->right,
		"./textures/mountains/right.png");
	set_texture(game, &game->graphics->mountain->peak,
		"./textures/mountains/peak.png");
}

void	display_mountain(t_game *game, char c, t_position *position)
{
	new_grass(game, position, '0');
	if (c == '/')
		display_texture(game, &game->graphics->mountain->left, position);
	else if (c == '~')
		display_texture(game, &game->graphics->mountain->middle, position);
	else if (c == '\\')
		display_texture(game, &game->graphics->mountain->right, position);
	else if (c == '^')
		display_texture(game, &game->graphics->mountain->peak, position);
}
