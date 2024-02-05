/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:06:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 19:01:47 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Generates the map and all its information
t_map	*set_map(t_list *head)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		free_list(head);
		termination("Memory allocation failed for the map!");
	}
	map->height = get_height(head);
	map->width = get_width(head->line);
	map->collectibles = 0;
	check_map_validity(head, map);
	set_cells(head, map);
	check_cells_validity(map);
	check_pathway_validity(map);
	return (map);
}

// Generates the cells of the map
void	set_cells(t_list *head, t_map *map)
{
	t_list	*current;
	size_t	index;

	map->cells = malloc(sizeof(char *) * (map->height + 1));
	if (!map->cells)
		erroneous_map(head, map, ERROR_UNALLOCATED_CELLS);
	current = head;
	index = 0;
	while (current && index < map->height)
	{
		map->cells[index] = remove_newline(current->line, map->width);
		if (!map->cells[index++])
			erroneous_map(head, map, ERROR_UNALLOCATED_CELLS);
		current = current->next;
	}
	map->cells[index] = NULL;
	free_list(head);
}

// Returns the height of the map
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

// Returns the width of the map
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

// Frees the memory allocated for the map
void	free_map(t_map *map)
{
	size_t	index;

	if (!map)
		return ;
	if (map->cells)
	{
		index = 0;
		while (map->cells[index])
			free(map->cells[index++]);
		free(map->cells);
	}
	free(map);
}
