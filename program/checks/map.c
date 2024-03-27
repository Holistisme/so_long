/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:47:53 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:45:12 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Checks if the space is big enough to hold all the elements,
// * but small enough to have space to display them.
void	check_if_map_is_adapted(t_game *game)
{
	if (game->map->height < 2 || game->map->width < 2)
		error_occurred(game, MAP_TOO_SMALL);
	else if (game->map->height > 32 || game->map->width > 62)
		error_occurred(game, MAP_TOO_WIDE);
	else if (game->map->height * game->map->width < 15)
		error_occurred(game, MAP_TOO_SMALL);
}

// * Checks if the map is rectangular
void	check_if_map_is_rectangular(t_game *game)
{
	t_list	*scan;

	scan = game->map->gnl_map;
	while (scan)
	{
		if (get_width(scan->line) != game->map->width)
			error_occurred(game, NON_RECTANGULAR_MAP);
		scan = scan->next;
	}
}

// * Checks that the map is framed by walls
void	check_if_map_has_limits(t_game *game)
{
	size_t	index;
	t_list	*scan;

	scan = game->map->gnl_map;
	while (scan)
	{
		if (scan == game->map->gnl_map || !scan->next)
		{
			index = 0;
			while (scan->line[index] && scan->line[index] != '\n')
				if (scan->line[index++] != '1')
					error_occurred(game, INVALID_LIMITS);
		}
		else if (scan->line[0] != '1'
			|| scan->line[game->map->width - 1] != '1')
			error_occurred(game, INVALID_LIMITS);
		scan = scan->next;
	}
}
