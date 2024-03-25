/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:33:35 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:25:08 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Makes all instances appear or disappear according to user choice
void	display_instances(mlx_image_t *image, size_t count, bool is_displayed)
{
	size_t	index;

	index = 0;
	while (index < count)
		image->instances[index++].enabled = is_displayed;
}

// ? Disables first instances to display second instances
void	exchange_textures(mlx_image_t *old, mlx_image_t *new, size_t size)
{
	display_instances(old, size, false);
	display_instances(new, size, true);
}

// ? Generates a texture on the map, then immediately deactivates it
void	display_and_disable(t_game *game, mlx_image_t **image,
	t_position *position, size_t index)
{
	display_texture(game, image, position);
	(*image)->instances[index].enabled = false;
}

// ? Initializes an instance according to its type,
// ? then immediately disables it
void	intitialize_but_disable(t_game **game, mlx_image_t **image,
	t_texture texture, size_t index)
{
	if (texture == CHARACTER)
		mlx_image_to_window((*game)->window, (*image), (*game)->map->position_scan->x
			* 64 + 8, (*game)->map->position_scan->y * 64 + 8);
	else if (texture == BLOCKING)
		mlx_image_to_window((*game)->window, (*image), (*game)->map->position_scan->x
			* 64 - 32, (*game)->map->position_scan->y * 64 + 8);
	(*image)->instances[index].enabled = false;
}

// ? Disables the previous instance to enables the next one
void	switch_an_instance(mlx_image_t *previous,
	mlx_image_t *next, size_t index)
{
	previous->instances[index].enabled = false;
	next->instances[index].enabled = true;
}
