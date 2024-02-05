/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 18:30:47 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Checks that the number of items returned equals those on the map
void	check_pathway_validity(t_map *map)
{
	char	**cloned_cells;

	cloned_cells = copy_cells(map);
	if (scan_map(map->spawn_x, map->spawn_y, cloned_cells) != map->collectibles + 1)
		erroneous_path(map, cloned_cells, ERROR_INVALID_PATH);
	free_cells(cloned_cells);
}

// Copies map cells
char	**copy_cells(t_map *map)
{
	char	**copied_cells;
	size_t	line;
	size_t	index;

	copied_cells = malloc(sizeof(char *) * (map->height + 1));
	if (!copied_cells)
		erroneous_cells(map, ERROR_UNALLOCATED_CELLS);
	line = 0;
	while (map->cells[line])
	{
		index = 0;
		copied_cells[line] = malloc(map->width + 1);
		if (!copied_cells[line])
			erroneous_path(map, copied_cells, ERROR_UNALLOCATED_CELLS);
		while (map->cells[line][index])
		{
			copied_cells[line][index] = map->cells[line][index];
			++index;
		}
		copied_cells[line][index] = '\0';
		++line;
	}
	copied_cells[line] = NULL;
	return (copied_cells);
}

// Returns the number of elements reachable from the spawn
int	scan_map(size_t x, size_t y, char **cells)
{
	int	reachable_items;

	reachable_items = 0;
	if (cells[x][y] == 'C' || cells[x][y] == 'E')
		++reachable_items;
	cells[x][y] = '#';
	if (cells[x + 1][y] != '1' && cells[x + 1][y] != '#')
		reachable_items += scan_map(x + 1, y, cells);
	if (cells[x - 1][y] != '1' && cells[x - 1][y] != '#')
		reachable_items += scan_map(x - 1, y, cells);
	if (cells[x][y + 1] != '1' && cells[x][y + 1] != '#')
		reachable_items += scan_map(x, y + 1, cells);
	if (cells[x][y - 1] != '1' && cells[x][y - 1] != '#')
		reachable_items += scan_map(x, y - 1, cells);
	return (reachable_items);
}

// Frees map memory and cells copy, then informs the user of the error
void	erroneous_path(t_map *map, char **cells, t_error_code code)
{
	free_map(map);
	free_cells(cells);
	if (code == ERROR_UNALLOCATED_CELLS)
		termination("Program failed to copy the cells for verification!");
	if (code == ERROR_INVALID_PATH)
		termination("Path is invalid, some items are unreachable!");
}

// Frees all cells
void	free_cells(char **cells)
{
	size_t	index;

	if (cells)
	{
		index = 0;
		while (cells[index])
			free(cells[index++]);
		free(cells);
	}
}
