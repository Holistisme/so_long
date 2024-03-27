/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 07:46:50 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:33:28 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Generates all map information and initiates checking
void	set_map(t_game *game, char *argv)
{
	game->map->cells = NULL;
	game->map->cloned_cells = NULL;
	game->map->gnl_line = NULL;
	game->map->gnl_map = NULL;
	game->map->current_position = NULL;
	game->map->spawn = NULL;
	game->map->exit = NULL;
	get_map(game, argv);
	set_height(game);
	game->map->width = 0;
	game->map->width = get_width(game->map->gnl_map->line);
	check_if_map_is_adapted(game);
	check_if_map_is_rectangular(game);
	check_if_map_has_limits(game);
	set_cells(game);
	scan_cells_elements(game);
	check_if_game_is_complet(game);
	check_pathway_validity(game);
}
