/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:27:29 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:27:55 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Checks whether the last distance is within the player's reach
int	is_player_near(t_game *game)
{
	int	distance_y;
	int	distance_x;

	distance_y = game->map->position_scan->y
		- game->character->position->y / 64;
	distance_x = game->map->position_scan->x
		- game->character->position->x / 64;
	if (distance_y < 4 && distance_y > -4 && distance_x < 4 && distance_x > -4)
		return (1);
	return (0);
}
