/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:31:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 15:14:48 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_borders_textures(t_game *game)
{
	game->graphics->border = NULL;
	game->graphics->border = allocate(game, sizeof(t_border), 0); //TODO : NOUVEAU CODE
	set_texture(game, &game->graphics->border->first,
		"./textures/borders/first.png");
	set_texture(game, &game->graphics->border->second,
		"./textures/borders/second.png");
	set_texture(game, &game->graphics->border->third,
		"./textures/borders/third.png");
	set_texture(game, &game->graphics->border->fourth,
		"./textures/borders/fourth.png");
	set_texture(game, &game->graphics->border->fifth,
		"./textures/borders/fifth.png");
}

mlx_image_t	**get_random_border_texture(t_border *border)
{
	int	probability;

	probability = rand() % 4;
	if (probability == 0)
		return (&border->first);
	else if (probability == 1)
		return (&border->second);
	else if (probability == 2)
		return (&border->third);
	else if (probability == 3)
		return (&border->fourth);
	else
		return (&border->fifth);
}
