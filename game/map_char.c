/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:36:36 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 16:31:52 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_is_digit(t_game *game, t_position *position)
{
	if (game->map->cells[position->y][position->x] == '0')
		new_grass(game, position, game->map->cells[position->y][position->x]);
	else if (game->map->cells[position->y][position->x] == '1')
		display_texture(game, &game->graphics->limit, position);
	else if (game->map->cells[position->y][position->x] == '2')
		display_texture(game, &game->graphics->water, position);
	else if (game->map->cells[position->y][position->x] == '3')
		display_texture(game, &game->graphics->deep_water, position);
	else if (game->map->cells[position->y][position->x] == '4')
		display_texture(game, &game->graphics->sandy_water, position);
}

void	char_is_lowercase(t_game *game, t_position *position)
{
	if (game->map->cells[position->y][position->x] == 'f')
		display_texture(game, &game->graphics->sand, position);
}

void	char_is_uppercase(t_game *game, t_position *position)
{
	new_grass(game, position, game->map->cells[position->y][position->x]);
	if (game->map->cells[position->y][position->x] == 'X')
		display_texture(game, &game->graphics->wall, position);
	else if (game->map->cells[position->y][position->x] == 'P')
		display_texture(game, &game->graphics->house, position);
	else if (game->map->cells[position->y][position->x] == 'C')
		display_texture(game, &game->graphics->battle, position);
	else if (game->map->cells[position->y][position->x] == 'E')
		display_texture(game, &game->graphics->tower, position);
	else if (game->map->cells[position->y][position->x] == 'U')
		display_texture(game, &game->graphics->pine, position);
	else if (game->map->cells[position->y][position->x] == 'I')
		display_texture(game, &game->graphics->snowy_pine, position);
	else if (game->map->cells[position->y][position->x] == 'O')
		display_texture(game, &game->graphics->pine_stump, position);
	else if (game->map->cells[position->y][position->x] == 'H')
		display_texture(game, &game->graphics->tree, position);
	else if (game->map->cells[position->y][position->x] == 'J')
		display_texture(game, &game->graphics->pine_tree, position);
	else if (game->map->cells[position->y][position->x] == 'K')
		display_texture(game, &game->graphics->apple_tree, position);
	else if (game->map->cells[position->y][position->x] == 'Q')
		display_texture(game, &game->graphics->rock, position);
	else if (game->map->cells[position->y][position->x] == 'W')
		display_texture(game, &game->graphics->two_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'T')
		display_texture(game, &game->graphics->plain_rock, position);
	else if (game->map->cells[position->y][position->x] == 'Y')
		display_texture(game, &game->graphics->two_plain_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'A')
		display_texture(game, &game->graphics->three_plain_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'S')
		display_texture(game, &game->graphics->hill_rock, position);
	else if (game->map->cells[position->y][position->x] == 'D')
		display_texture(game, &game->graphics->two_hill_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'G')
		display_texture(game, &game->graphics->snowy_rock, position);
	else if (game->map->cells[position->y][position->x] == 'Z')
		display_texture(game, &game->graphics->two_snowy_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'V')
		display_texture(game, &game->graphics->three_snowy_rocks, position);
	else if (game->map->cells[position->y][position->x] == 'F')
	{
		display_texture(game, &game->graphics->field->spring, position);
		display_texture(game, &game->graphics->field->summer, position);
		display_texture(game, &game->graphics->field->fall, position);
		display_texture(game, &game->graphics->field->winter, position);
	}
	else if (game->map->cells[position->y][position->x] == 'M')
		add_mill(game, position);
}
