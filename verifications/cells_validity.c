/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:42:35 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 18:24:55 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Browses the cells to scan the legitimacy of each element
void	check_cells_validity(t_map *map)
{
	int		spawn;
	int		exit;
	size_t	x;
	size_t	y;

	spawn = 0;
	exit = 0;
	x = 1;
	while (x < (map->height - 1))
	{
		y = 1;
		while (y < (map->width - 1))
		{
			if (map->cells[x][y] == 'C')
				++map->collectibles;
			else if (map->cells[x][y] == 'P')
				spawn += define_spawn(map, x, y);
			else if (map->cells[x][y] == 'E')
				++exit;
			else if (map->cells[x][y] != '0' && map->cells[x][y] != '1')
				erroneous_cells(map, ERROR_UNRECOGNISED_ELEMENT);
			++y;
		}
		++x;
	}
	check_number_elements(map, spawn, exit);
}

// Checks that the map contains the right number of items
void	check_number_elements(t_map *map, int spawn, int exit)
{
	if (spawn < 1)
		erroneous_cells(map, ERROR_NO_SPAWN);
	if (spawn > 1)
		erroneous_cells(map, ERROR_TOO_MANY_SPAWNS);
	if (!map->collectibles)
		erroneous_cells(map, ERROR_NO_COLLECTIBLE);
	if (exit < 1)
		erroneous_cells(map, ERROR_NO_EXIT);
	if (exit > 1)
		erroneous_cells(map, ERROR_TOO_MANY_EXITS);
}

// Frees map memory and informs user of error
void	erroneous_cells(t_map *map, t_error_code code)
{
	free_map(map);
	if (code == ERROR_UNRECOGNISED_ELEMENT)
		termination("A cell on the map is an unexpected character!");
	else if (code == ERROR_NO_SPAWN)
		termination("No spawn on the map!");
	else if (code == ERROR_TOO_MANY_SPAWNS)
		termination("Too many spawn on the map!");
	else if (code == ERROR_NO_COLLECTIBLE)
		termination("No collectible on the map!");
	else if (code == ERROR_NO_EXIT)
		termination("No exit on the map!!");
	else if (code == ERROR_TOO_MANY_EXITS)
		termination("Too many exits on the map!");
	else if (code == ERROR_UNALLOCATED_CELLS)
		termination("Creation of map cells has failed!");
}
