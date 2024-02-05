/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:12:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 19:01:27 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Checks map validity by calling up other functions
void	check_map_validity(t_list *head, t_map *map)
{
	if (!map_is_quite_large(map->height, map->width))
		erroneous_map(head, map, ERROR_INSUFFICIENT_SPACE);
	if (!map_is_rectangular(head, map->width))
		erroneous_map(head, map, ERROR_NON_RECTANGULAR_MAP);
	if (!map_has_limits(head, map->width))
		erroneous_map(head, map, ERROR_INVALID_LIMITS);
}

// Checks that the map has enough space for all the elements
int	map_is_quite_large(size_t height, size_t width)
{
	if (height < 2 || width < 2 || height * width < 15)
		return (0);
	return (1);
}

// Checks if the map is rectangular
int	map_is_rectangular(t_list *head, size_t width)
{
	t_list	*scan;

	scan = head->next;
	while (scan)
	{
		if (get_width(scan->line) != width)
			return (0);
		scan = scan->next;
	}
	return (1);
}

// Checks that the map is framed by walls
int	map_has_limits(t_list *head, size_t width)
{
	t_list	*scan;
	size_t	index;

	scan = head;
	while (scan)
	{
		if (head == scan || !scan->next)
		{
			index = 0;
			while (scan->line[index] && scan->line[index] != '\n')
				if (scan->line[index++] != '1')
					return (0);
		}
		else if (scan->line[0] != '1' || scan->line[width - 1] != '1')
			return (0);
		scan = scan->next;
	}
	return (1);
}

// Frees allocation of the list and map then stops program, justifying error
void	erroneous_map(t_list *head, t_map *map, t_error_code code)
{
	free_list(head);
	free(map);
	if (code == ERROR_INSUFFICIENT_SPACE)
		termination("The map does not have enough space for game elements!");
	else if (code == ERROR_NON_RECTANGULAR_MAP)
		termination("The map is not rectangular!");
	else if (code == ERROR_INVALID_LIMITS)
		termination("The map has no valid limits!");
	else if (code == ERROR_UNALLOCATED_CELLS)
		termination("Creation of map cells has failed!");
}
