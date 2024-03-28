/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:45:13 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 17:11:36 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Depending on the number of arguments, generates then disables each image.
void	set_animation(t_game *game, int element, int hidden, ...)
{
	mlx_image_t	*image;
	va_list		args;

	va_start(args, hidden);
	display_texture(game, va_arg(args, mlx_image_t *),
		game->map->current_position, game->graphics->background_focus);
	while (hidden--)
	{
		image = va_arg(args, mlx_image_t *);
		display_texture(game, image, game->map->current_position,
			game->graphics->background_focus);
		image->instances[element].enabled = false;
	}
	va_end(args);
}

// * Depending on the number of arguments, set all textures.
void	set_all_textures(t_game *game, int count, ...)
{
	va_list		args;

	va_start(args, count);
	while (count--)
		set_texture(game, va_arg(args, mlx_image_t **),
			va_arg(args, const char *));
	va_end(args);
}

// ? Assigns each texture to an address while freeing this first after action
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

// ? Disables the previous instance to enables the next one
void	switch_instances(mlx_image_t *previous, mlx_image_t *next, size_t index)
{
	previous->instances[index].enabled = false;
	next->instances[index].enabled = true;
}

//  ? Recovers the index of an instance by comparing it with a target position
size_t	get_image_index(t_game *game, char c, t_position *trigger)
{
	size_t	index;
	size_t	y;
	size_t	x;

	index = 0;
	y = 1;
	while (game->map->cells[y + 1])
	{
		x = 1;
		while (game->map->cells[y][x + 1])
		{
			if (y == trigger->y / 64 && x == trigger->x / 64)
				return (index);
			else if (game->map->cells[y][x++] == c)
				++index;
		}
		++y;
	}
	return (index);
}
