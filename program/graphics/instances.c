/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:45:13 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 19:19:39 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Depending on the number of arguments, generates then deactivate each image.
void	set_animation(t_game *game, int element, int textures, ...)
{
	mlx_image_t	*image;
	va_list		args;

	va_start(args, textures--);
	mlx_image_to_window(game, va_arg(args, mlx_image_t *),
		game->map->current_position->x, game->map->current_position->y);
	while (textures--)
	{
		image = va_arg(args, mlx_image_t *);
		mlx_image_to_window(game, image, game->map->current_position->x,
			game->map->current_position->y);
		image->instances[element].enabled = false;
	}
	va_end(args);
}
