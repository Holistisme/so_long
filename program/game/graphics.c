/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:07:17 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 18:39:34 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

void	set_graphics_to_null(t_graphics	*graphics)
{
	graphics->castle = NULL;
}

// ? Assigns each texture to an address while releasing this first after action
void	set_texture(t_game *game, mlx_image_t **target, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_occurred(game, UNLOADED_TEXTURE);
	*target = mlx_texture_to_image(game->window, texture);
	mlx_delete_texture(texture);
	if (!*target)
		error_occurred(game, UNALLOCATED_IMAGE);
}

// ? Initializes the map's mandatory textures
void	basic_textures_initialization(t_game *game)
{

}

// ? Generates and displays an unique, permanent texture,
// ? like the edges of the map.
void	permanent_texture(t_game *game)
{
	
}

// ? Traverses cells and calls subfunctions to load graphics
void	load_graphics(t_game *game)
{
	game->map->current_position->y = 0;

	while (game->map->cells[game->map->current_position->y])
	{
		game->map->current_position->x = 0;
		while (game->map->cells[game->map->current_position->y][game->map->current_position->x])
		{
			if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], "01234LR"))
				char_is_digit(game, game->map->position_scan);
			else if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], "abcdefg"))
				char_is_lowercase(game, game->map->position_scan);
			else if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], "XPCEUIOHJKQWTYABSDFZVM"))
				char_is_uppercase(game, game->map->position_scan);
			else if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], "/~^\\"))
				display_mountain(game, game->map->cells[game->map->position_scan->y][game->map->position_scan->x], game->map->position_scan);
			++game->map->position_scan->x;
		}
		++game->map->position_scan->y;
	}
	game->map->position_scan->y = 0;
	while (game->map->cells[game->map->position_scan->y])
	{
		game->map->position_scan->x = 0;
		while (game->map->cells[game->map->position_scan->y][game->map->position_scan->x])
		{
			if (is_inside(game->map->cells[game->map->position_scan->y][game->map->position_scan->x], ".|{}"))
			{
				new_grass(game, game->map->position_scan, game->map->cells[game->map->position_scan->y][game->map->position_scan->x]);
				if (!game->graphics->guards)
					set_guards_textures(game);
				if (game->map->cells[game->map->position_scan->y][game->map->position_scan->x] == '{')
				{
					if (!game->graphics->guards->left)
						set_lateral_side_blocking_textures(game, &game->graphics->guards->left, LEFT);
					add_guard(&game, &game->graphics->guards->left);
				}
				else if (game->map->cells[game->map->position_scan->y][game->map->position_scan->x] == '.')
				{
					if (!game->graphics->guards->back)
						set_vertical_side_blocking_textures(game, &game->graphics->guards->back, BACK);
					add_guard(&game, &game->graphics->guards->back);
				}
			}
			++game->map->position_scan->x;
		}
		++game->map->position_scan->y;
	}
}
