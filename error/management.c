/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:11:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/23 14:42:03 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Allocates memory on a pointer, but on error, initiates program stop
void	*allocate(t_game *game, size_t size, t_error_code code)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_occurred(game, code);
	return (ptr);
}

// * Frees allocated memory, calls to inform user, then exits program
void	error_occurred(t_game *game, t_error_code code)
{
	if (code == 4)
		free(game);
	else
		free_game(&game);
	if (code < 12)
		report_error_a(code);
	else
		report_error_b(code);
	exit(EXIT_FAILURE);
}

// ? Calls to write to the user the error encountered. First list.
void	report_error_a(t_error_code code)
{
	if (code == 0)
		print_error("No argument to get the game map!");
	else if (code == 1)
		print_error("Too many arguments to choose a game map!");
	else if (code == 2)
		print_error("Invalid map extension!");
	else if (code == 3)
		print_error("Allocation for game structure fails!");
	else if (code == 4)
		print_error("Allocation for map structure fails!");
	else if (code == 5)
		print_error("Obtaining data from the requested file has failed!");
	else if (code == 6)
		print_error("GNL was unable to return anything on its first call");
	else if (code == 7)
		print_error("Allocation for a node in the linked list fails!");
	else if (code == 8)
		print_error("Map too small to hold the required number of elements!");
	else if (code == 9)
		print_error("Map too large to display correctly!");
	else if (code == 10)
		print_error("The map is not rectangular!");
	else if (code == 11)
		print_error("Map limits are invalid!");
}

// ? Calls to write to the user the error encountered. Second list.
void	report_error_b(t_error_code code)
{
	if (code == 12)
		print_error("Allocation for cells structure fails!");
	else if (code == 13)
		print_error("Presence of an unknown character on the map!");
	else if (code == 14)
		print_error("Allocation for a position fails!");
	else if (code == 15)
		print_error("Multiple spawns detection!");
	else if (code == 16)
		print_error("Multiple exits detection!");
	else if (code == 17)
		print_error("The map has no collectible!");
	else if (code == 18)
		print_error("The map has no spawn!");
	else if (code == 19)
		print_error("The map has no exit!");
	else if (code == 20)
		print_error("Allocation for cloned cells structure fails!");
	else if (code == 21)
		print_error("Allocation for cloned line fails!");
	else if (code == 22)
		print_error("Some elements are inaccessible from the spawn!");
}

// ? Informs the user of an error
void	print_error(char *error_message)
{
	write(2, "Error\n", string_length("Error\n"));
	write(2, error_message, string_length(error_message));
}
