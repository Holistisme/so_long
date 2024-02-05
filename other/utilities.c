/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:15 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 18:19:23 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Returns the size of a string of characters
size_t	get_size(char *string)
{
	size_t	size;

	size = 0;
	if (!string)
		return (0);
	while (string[size])
		++size;
	return (size);
}

// Removes the newline character from a string
char	*remove_newline(char *string, size_t width)
{
	char	*new_string;
	void	*new_pointer;
	size_t	index;

	new_string = malloc(width + 1);
	if (!new_string)
		return (NULL);
	new_pointer = new_string;
	index = 0;
	while (string[index] && string[index] != '\n' && index < width)
		*new_string++ = string[index++];
	*new_string = '\0';
	return (new_pointer);
}

// Defines spawn coordinates and returns its existence
int	define_spawn(t_map *map, size_t coordinates_x, size_t coordinates_y)
{
	map->spawn_x = coordinates_x;
	map->spawn_y = coordinates_y;
	return (1);
}


// Informs the user of an error, then stops program execution
void	termination(char *error_message)
{
	write(2, "Error\n", get_size("Error\n"));
	write(2, error_message, get_size(error_message));
	exit(EXIT_FAILURE);
}
