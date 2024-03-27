/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occurences.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 16:00:18 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Frees allocated memory, calls to inform user, then exits program
void	error_occurred(t_game *game, t_error error)
{
	free_game(&game);
	if (!unallocated_error_occured(error))
		if (!map_validity_error_occured(error))
			elements_validity_error_occured(error);
	exit(EXIT_FAILURE);
}

// ? Informs the user of an error on the elements
int	elements_validity_error_occured(t_error error)
{
	if (error == INVALID_PATHWAY)
		print_error("Some elements are inaccessible from the spawn!");
	else if (error == UNRECOGNISED_ELEMENT)
		print_error("Presence of an unknown character on the map!");
	else if (error == MULTIPLE_EXIT)
		print_error("Multiple exits detection!");
	else if (error == MULTIPLE_SPAWN)
		print_error("Multiple spawns detection!");
	else if (error == NO_COLLECTIBLE)
		print_error("The map has no collectible!");
	else if (error == NO_EXIT)
		print_error("The map has no exit!");
	else if (error == NO_SPAWN)
		print_error("The map has no spawn!");
	else
		return (0);
	return (1);
}

// ? Informs the user of an error on the map
int	map_validity_error_occured(t_error error)
{
	if (error == INVALID_FD)
		print_error("Obtaining data from the requested file has failed!");
	else if (error == INVALID_LIMITS)
		print_error("Map limits are invalid!");
	else if (error == MAP_TOO_SMALL)
		print_error("Map too small to hold the required number of elements!");
	else if (error == MAP_TOO_WIDE)
		print_error("Map too large to display correctly!");
	else if (error == MULTIPLE_FILES)
		print_error("Too many arguments to choose a game map!");
	else if (error == NO_FILE)
		print_error("No argument to get the game map!");
	else if (error == NON_RECTANGULAR_MAP)
		print_error("The map is not rectangular!");
	else if (error == UNRECOGNISED_EXTENSION)
		print_error("Invalid map extension!");
	else
		return (0);
	return (1);
}

// ? Informs the user of an error on an allocation
int	unallocated_error_occured(t_error error)
{
	if (error == UNALLOCATED_CELL)
		print_error("Allocation for a simple cell fails!");
	else if (error == UNALLOCATED_CELLS)
		print_error("Allocation for cells structure fails!");
	else if (error == UNALLOCATED_CLONED_CELLS)
		print_error("Allocation for cloned cells structure fails!");
	else if (error == UNALLOCATED_CLONED_LINE)
		print_error("Allocation for cloned line fails!");
	else if (error == UNALLOCATED_GAME)
		print_error("Allocation for game structure fails!");
	else if (error == UNALLOCATED_MAP)
		print_error("Allocation for map structure fails!");
	else if (error == UNALLOCATED_NODE)
		print_error("Allocation for a node in the linked list fails!");
	else if (error == UNALLOCATED_POSITION)
		print_error("Allocation for a position fails!");
	else if (error == NULL_LINE)
		print_error("GNL was unable to return anything on its first call!");
	else
		return (0);
	return (1);
}
