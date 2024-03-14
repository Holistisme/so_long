/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:36:36 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/14 13:04:47 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_is_digit(t_game *game, size_t line, size_t column)
{
	
	else if (game->map->cells[line][column] == '1')
		display_texture(game, &game->graphics->limit, line, column);
	else if (game->map->cells[line][column] == '2')
		display_texture(game, &game->graphics->water, line, column);
	else if (game->map->cells[line][column] == '3')
		display_texture(game, &game->graphics->deep_water, line, column);
	else if (game->map->cells[line][column] == '4')
		display_texture(game, &game->graphics->sandy_water, line, column);
}

void	char_is_lowercase(t_game *game, size_t line, size_t column)
{
	if (game->map->cells[line][column] == 'f')
		display_texture(game, &game->graphics->sand, line, column);
}

void	char_is_uppercase(t_game *game, size_t y, size_t x)
{
	if (game->map->cells[y][x] == 'X')
		display_texture(game, &game->graphics->wall, y, x);
	else if (game->map->cells[y][x] == 'P')
		display_texture(game, &game->graphics->house, y, x);
	else if (game->map->cells[y][x] == 'C')
		display_texture(game, &game->graphics->battle, y, x);
	else if (game->map->cells[y][x] == 'E')
		display_texture(game, &game->graphics->tower, y, x);
	else if (game->map->cells[y][x] == 'U')
		display_texture(game, &game->graphics->pine, y, x);
	else if (game->map->cells[y][x] == 'I')
		display_texture(game, &game->graphics->snowy_pine, y, x);
	else if (game->map->cells[y][x] == 'O')
		display_texture(game, &game->graphics->pine_stump, y, x);
	else if (game->map->cells[y][x] == 'H')
		display_texture(game, &game->graphics->tree, y, x);
	else if (game->map->cells[y][x] == 'J')
		display_texture(game, &game->graphics->pine_tree, y, x);
	else if (game->map->cells[y][x] == 'K')
		display_texture(game, &game->graphics->apple_tree, y, x);
	else if (game->map->cells[y][x] == 'L')
		display_texture(game, &game->graphics->tree_stump, y, x);

	else if (game->map->cells[y][x] == 'Q')
		display_texture(game, &game->graphics->rock, y, x);
	else if (game->map->cells[y][x] == 'W')
		display_texture(game, &game->graphics->two_rocks, y, x);
	else if (game->map->cells[y][x] == 'R')
		display_texture(game, &game->graphics->three_rocks, y, x);
	else if (game->map->cells[y][x] == 'T')
		display_texture(game, &game->graphics->plain_rock, y, x);
	else if (game->map->cells[y][x] == 'Y')
		display_texture(game, &game->graphics->two_plain_rocks, y, x);
	else if (game->map->cells[y][x] == 'A')
		display_texture(game, &game->graphics->three_plain_rocks, y, x);
	else if (game->map->cells[y][x] == 'S')
		display_texture(game, &game->graphics->hill_rock, y, x);
	else if (game->map->cells[y][x] == 'D')
		display_texture(game, &game->graphics->two_hill_rocks, y, x);
	else if (game->map->cells[y][x] == 'G')
		display_texture(game, &game->graphics->snowy_rock, y, x);
	else if (game->map->cells[y][x] == 'Z')
		display_texture(game, &game->graphics->two_snowy_rocks, y, x);
	else if (game->map->cells[y][x] == 'V')
		display_texture(game, &game->graphics->three_snowy_rocks, y, x);
	else if (game->map->cells[y][x] == 'F')
	{
		display_texture(game, &game->graphics->field->spring, y, x);
		display_texture(game, &game->graphics->field->summer, y, x);
		display_texture(game, &game->graphics->field->fall, y, x);
		display_texture(game, &game->graphics->field->winter, y, x);
	}
	else if (game->map->cells[y][x] == 'M')
		add_mill(game, y, x);
}
