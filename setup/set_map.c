/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:06:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/14 12:55:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Generates the map and all its information
void	set_map(t_game *game)
{
	game->map->collectibles = 0;
	game->map->fields = 0;
	game->map->height = get_height(game->map->list);
	game->map->width = get_width(game->map->list->line);
	game->map->spawn = NULL;
	game->map->exit = NULL;
	check_if_map_is_adapted(game);
	check_if_map_is_rectangular(game);
	check_if_map_has_limits(game);
	set_cells(game);
	free_list(&game->map->list);
	scan_cells_elements(game);
	check_if_game_is_complet(game);
	check_pathway_validity(game);
}

// * Generates the cells of the map
void	set_cells(t_game *game)
{
	t_list	*current;
	size_t	index;

	game->map->cells = allocate(game, sizeof(char *) * (game->map->height + 1),
			12);
	current = game->map->list;
	index = 0;
	while (current && index < game->map->height)
	{
		copy_node_to_cell(game, index++, current->line);
		current = current->next;
	}
	game->map->cells[index] = NULL;
}

// ? Saves the map positions up to the newline character
void	copy_node_to_cell(t_game *game, size_t y, char *line)
{
	size_t	x;

	game->map->cells[y] = NULL;
	game->map->cells[y] = allocate(game, game->map->width + 1, 8);
	x = 0;
	while (line[x] && line[x] != '\n')
	{
		game->map->cells[y][x] = line[x];
		++x;
	}
	game->map->cells[y][x] = '\0';
}

// ? Returns the height of the map
size_t	get_height(t_list *head)
{
	t_list	*current;
	size_t	height;

	height = 0;
	current = head;
	while (current)
	{
		++height;
		current = current->next;
	}
	return (height);
}

// ? Returns the width of the map
size_t	get_width(char *line)
{
	size_t	width;

	width = 0;
	if (!line)
		return (0);
	while (line[width] && line[width] != '\n')
		++width;
	return (width);
}
