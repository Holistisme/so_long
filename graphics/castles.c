/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:50:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 10:20:23 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_castle_textures(t_game *game)
{
	game->graphics->castle = NULL;
	game->graphics->castle = allocate(game, sizeof(t_castle), 0); //TODO : NOUVEAU CODE
	set_texture(game, &game->graphics->castle->english,
		"./textures/castles/english.png");
	set_texture(game, &game->graphics->castle->french,
		"./textures/castles/french.png");
}

void	take_castle(t_game *game)
{
	game->graphics->castle->english->instances[get_castle_index(game)].enabled = false;
	game->graphics->castle->french->instances[get_castle_index(game)].enabled = true;
}

int	get_castle_index(t_game *game)
{
	int		index;
	size_t	y;
	size_t	x;

	index = -1;
	y = 1;
	while (game->map->cells[y])
	{
		x = 1;
		while (game->map->cells[y][x])
		{
			if (game->map->cells[y][x] == 'C')
				++index;
			if (y == game->character->position->y / 64 && x == game->character->position->x / 64)
				break ;
			++x;
		}
		if (y == game->character->position->y / 64 && x == game->character->position->x / 64)
			break ;
		++y;
	}
	return (index);
}
