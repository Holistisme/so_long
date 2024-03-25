/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:51:31 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:15:27 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Assigns each texture from an external path
void	set_graphics(t_game *game)
{
	set_texture(game, &game->graphics->limit, "./textures/limit.png");
	set_texture(game, &game->graphics->water, "./textures/water.png");
	set_texture(game, &game->graphics->deep_water, "./textures/deep_water.png");
	set_texture(game, &game->graphics->sand, "./textures/sand.png");
	set_texture(game, &game->graphics->sandy_water,
		"./textures/sandy_water.png");
	set_texture(game, &game->graphics->wall, "./textures/wall.png");
	set_texture(game, &game->graphics->tower, "./textures/tower.png");
	set_texture(game, &game->graphics->house, "./textures/house.png");
	set_texture(game, &game->graphics->battle, "./textures/battle.png");
	set_texture(game, &game->graphics->pine, "./textures/pine.png");
	set_texture(game, &game->graphics->pine_stump, "./textures/pine_stump.png");
	set_texture(game, &game->graphics->snowy_pine, "./textures/snowy_pine.png");
	set_texture(game, &game->graphics->tree, "./textures/tree.png");
	set_texture(game, &game->graphics->pine_tree, "./textures/pine_tree.png");
	set_texture(game, &game->graphics->apple_tree, "./textures/apple_tree.png");
	set_texture(game, &game->graphics->tree_stump, "./textures/tree_stump.png");
	set_texture(game, &game->graphics->rock, "./textures/rock.png");
	set_texture(game, &game->graphics->two_rocks, "./textures/two_rocks.png");
	set_texture(game, &game->graphics->three_rocks, "./textures/three_rocks.png");
	set_texture(game, &game->graphics->plain_rock, "./textures/plain_rock.png");
	set_texture(game, &game->graphics->two_plain_rocks, "./textures/two_plain_rocks.png");
	set_texture(game, &game->graphics->three_plain_rocks, "./textures/three_plain_rocks.png");
	set_texture(game, &game->graphics->hill_rock, "./textures/hill_rock.png");
	set_texture(game, &game->graphics->two_hill_rocks, "./textures/two_hill_rocks.png");
	set_texture(game, &game->graphics->three_hill_rocks, "./textures/three_hill_rocks.png");
	set_texture(game, &game->graphics->snowy_rock, "./textures/snowy_rock.png");
	set_texture(game, &game->graphics->two_snowy_rocks, "./textures/two_snowy_rocks.png");
	set_texture(game, &game->graphics->three_snowy_rocks, "./textures/three_snowy_rocks.png");
	set_texture(game, &game->graphics->ground->snow,
			"./textures/snow.png");
}

// ? Assigns each texture to an address while releasing this first after action
void	set_texture(t_game *game, mlx_image_t **target, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_occurred(game, LOADING_TEXTURE);
	*target = mlx_texture_to_image(game->window, texture);
	mlx_delete_texture(texture);
	if (!*target)
		error_occurred(game, IMAGE_ALLOCATION);
}

// ? Traverses cells and calls subfunctions to load graphics
void	load_graphics(t_game *game)
{
	game->map->position_scan = allocate(game, sizeof(t_position), 0); //TODO : Changer le code d'erreur!
	game->map->position_scan->y = 0;
	while (game->map->cells[game->map->position_scan->y])
	{
		game->map->position_scan->x = 0;
		while (game->map->cells[game->map->position_scan->y][game->map->position_scan->x])
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

// ? Simplifies the display of a graphic
void	display_texture(t_game *game, mlx_image_t **texture, t_position *position)
{
	mlx_image_to_window(game->window, *texture, position->x * 64, position->y * 64);
}

