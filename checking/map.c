/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:12:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/19 12:19:35 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Checks if the space is big enough to hold all the elements,
// ? but small enough to have space to display them.
void	check_if_map_is_adapted(t_game *game)
{
	if (game->map->height < 2 || game->map->width < 2)
		error_occurred(game, 8);
	if (game->map->height > 32 || game->map->width > 62)
		error_occurred(game, 9);
	if (game->map->height * game->map->width < 15)
		error_occurred(game, 8);
}

// ? Checks if the map is rectangular
void	check_if_map_is_rectangular(t_game *game)
{
	t_list	*scan;

	scan = game->map->list->next;
	while (scan)
	{
		if (get_width(scan->line) != game->map->width)
			error_occurred(game, 10);
		scan = scan->next;
	}
}

// ? Checks that the map is framed by walls
void	check_if_map_has_limits(t_game *game)
{
	size_t	index;
	t_list	*scan;

	scan = game->map->list;
	while (scan)
	{
		if (scan == game->map->list || !scan->next)
		{
			index = 0;
			while (scan->line[index] && scan->line[index] != '\n')
				if (scan->line[index++] != '1')
					error_occurred(game, 11);
		}
		else if (scan->line[0] != '1'
			|| scan->line[game->map->width - 1] != '1')
			error_occurred(game, 11);
		scan = scan->next;
	}
}
