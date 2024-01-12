/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:19:03 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/12 19:47:06 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_elem(t_elem *elem_struct)
{
	elem_struct->collectibles = 0;
	elem_struct->spawn = 0;
	elem_struct->exit = 0;
	return (0);
}

size_t	get_width(char *line)
{
	size_t	width;

	width = 0;
	if (!line)
		return (width);
	while (line[width] && line[width] != '\n')
		++width;
	return (width);
}

void	error_indication(t_err_code code)
{
	if (code == ERR_LIMITS)
		write(2, "Error\nThe map does not have conventional limits!", 48);
	else if (code == ERR_NON_RECT)
		write(2, "Error\nThe map is not a conventional rectangle!", 46);
	else if (code == ERR_UNKNOWN_POS)
		write(2, "Error\nThe map contains unknown characters!", 42);
	else if (code == ERR_MANY_SPAWNS)
		write(2, "Error\nThe map has more than one spawn point!", 44);
	else if (code == ERR_MANY_EXITS)
		write(2, "Error\nThe map has more than one exit!", 37);
	else if (code == ERR_NO_COLLECT)
		write(2, "Error\nThe map has no collectibles!", 34);
	else if (code == ERR_BAD_PATH)
		write(2, "Error\nThe map has no path between its main elements!", 52);
	else if (code == ERR_INIT_ELEMENTS)
		write(2, "Error\nElements control structure could not be created", 53);
}

void	error_mgmt(t_list *head, t_elem *elem_struct, t_err_code code)
{
	free_list(head);
	if (elem_struct)
		free(elem_struct);
	error_indication(code);
	exit(EXIT_FAILURE);
}
