/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 17:01:30 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// * Frees allocated memory, calls to inform user, then exits program
void	error_occurred(t_game **game, t_error error)
{
	free((*game));
	game = NULL;
	if (error == NO_FILE)
		print_error("No argument to get the game map!");
	else if (error == MULTIPLE_FILES)
		print_error("Too many arguments to choose a game map!");
	else if (error == UNRECOGNISED_EXTENSION)
		print_error("Invalid map extension!");
	else if (error == UNALLOCATED_GAME)
		print_error("Allocation for game structure fails!");
	else if (error == UNALLOCATED_MAP)
		print_error("Allocation for map structure fails!");
	else if (error == INVALID_FD)
		print_error("Obtaining data from the requested file has failed!");
	else if (error == NULL_LINE)
		print_error("GNL was unable to return anything on its first call!");
	else if (error == UNALLOCATED_NODE)
		print_error("Allocation for a node in the linked list fails!");
	exit(EXIT_FAILURE);
}

// ? Informs the user of an error
void	print_error(char *error_message)
{
	write(2, "Error\n", string_length("Error\n"));
	write(2, error_message, string_length(error_message));
}
