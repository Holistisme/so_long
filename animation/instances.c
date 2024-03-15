/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:33:35 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 16:45:03 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Makes all instances appear or disappear according to user choice
void	display_instances(mlx_image_t *image, size_t count, bool is_displayed)
{
	size_t	index;

	index = 0;
	while (index <= count)
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
