/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:51:13 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:39:30 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Sets the height of the map
void	set_height(t_game *game)
{
	t_list	*current;

	current = game->map->gnl_map;
	game->map->height = 0;
	while (current)
	{
		++game->map->height;
		current = current->next;
	}
}

// * Returns the width of the map
size_t	get_width(char *line)
{
	size_t	index;

	index = 0;
	while (line[index] && line[index] != '\n')
		++index;
	return (index);
}
