/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:11:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 11:52:48 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// * Frees allocated memory, calls to inform user, then exits program
void	error_occurred(t_error error)
{
	//else if (error > 2) //?
	//	free_game(&game); //?
	if (error == NO_FILE)
		print_error("No argument to get the game map!");
	else if (error == MULTIPLE_FILES)
		print_error("Too many arguments to choose a game map!");
	else if (error == UNRECOGNISED_EXTENSION)
		print_error("Invalid map extension!");
	exit(EXIT_FAILURE);
}

// // ? Calls to write to the user the error encountered. First list.
// void	report_error_a(t_error_code code)
// {
// 	if (code == 0)
// 		print_error("No argument to get the game map!");
// 	else if (code == 1)
// 		print_error("Too many arguments to choose a game map!");
// 	else if (code == 2)
// 		print_error("Invalid map extension!");
// 	else if (code == 3)
// 		print_error("Allocation for game structure fails!");
// 	else if (code == 4)
// 		print_error("Allocation for map structure fails!");
// 	else if (code == 5)
// 		print_error("Obtaining data from the requested file has failed!");
// 	else if (code == 6)
// 		print_error("GNL was unable to return anything on its first call");
// 	else if (code == 7)
// 		print_error("Allocation for a node in the linked list fails!");
// 	else if (code == 8)
// 		print_error("Map too small to hold the required number of elements!");
// 	else if (code == 9)
// 		print_error("Map too large to display correctly!");
// 	else if (code == 10)
// 		print_error("The map is not rectangular!");
// 	else if (code == 11)
// 		print_error("Map limits are invalid!");
// }

	// else if (error == 3)
	// 	print_error("Allocation for game structure fails!");
	// else if (error == 4)
	// 	print_error("Allocation for map structure fails!");
	// else if (error == 5)
	// 	print_error("Obtaining data from the requested file has failed!");
	// else if (error == 6)
	// 	print_error("GNL was unable to return anything on its first call");
	// else if (error == 7)
	// 	print_error("Allocation for a node in the linked list fails!");
	// else if (error == 8)
	// 	print_error("Map too small to hold the required number of elements!");
	// else if (error == 9)
	// 	print_error("Map too large to display correctly!");
	// else if (error == 10)
	// 	print_error("The map is not rectangular!");
	// else if (error == 11)
	// 	print_error("Map limits are invalid!");
	// else if (error == 12)
	// 	print_error("Allocation for cells structure fails!");
	// else if (error == 13)
	// 	print_error("Presence of an unknown character on the map!");
	// else if (error == 14)
	// 	print_error("Allocation for a position fails!");
	// else if (error == 15)
	// 	print_error("Multiple spawns detection!");
	// else if (error == 16)
	// 	print_error("Multiple exits detection!");
	// else if (error == 17)
	// 	print_error("The map has no collectible!");
	// else if (error == 18)
	// 	print_error("The map has no spawn!");
	// else if (error == 19)
	// 	print_error("The map has no exit!");
	// else if (error == 20)
	// 	print_error("Allocation for cloned cells structure fails!");
	// else if (error == 21)
	// 	print_error("Allocation for cloned line fails!");
	// else if (error == 22)
	// 	print_error("Some elements are inaccessible from the spawn!");
	// if (code < 12)
	// 	report_error_a(code);
	// else
	// 	report_error_b(code);

// // ? Calls to write to the user the error encountered. Second list.
// void	report_error_b(t_error_code code)
// {
// 	if (code == 12)
// 		print_error("Allocation for cells structure fails!");
// 	else if (code == 13)
// 		print_error("Presence of an unknown character on the map!");
// 	else if (code == 14)
// 		print_error("Allocation for a position fails!");
// 	else if (code == 15)
// 		print_error("Multiple spawns detection!");
// 	else if (code == 16)
// 		print_error("Multiple exits detection!");
// 	else if (code == 17)
// 		print_error("The map has no collectible!");
// 	else if (code == 18)
// 		print_error("The map has no spawn!");
// 	else if (code == 19)
// 		print_error("The map has no exit!");
// 	else if (code == 20)
// 		print_error("Allocation for cloned cells structure fails!");
// 	else if (code == 21)
// 		print_error("Allocation for cloned line fails!");
// 	else if (code == 22)
// 		print_error("Some elements are inaccessible from the spawn!");
// }
