/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:06:43 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/23 14:45:47 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Sets a linked list with lines read by get_next_line
void	save_map(t_game *game)
{
	t_list	*current;

	game->map->line = get_next_line(game->map->fd);
	if (!game->map->line)
		error_occurred(game, 6);
	game->map->list = create_node(game);
	current = game->map->list;
	game->map->line = get_next_line(game->map->fd);
	while (game->map->line)
	{
		current->next = create_node(game);
		current = current->next;
		game->map->line = get_next_line(game->map->fd);
	}
}

// ? Creates a node with the line returned by get_next_line
t_list	*create_node(t_game *game)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = allocate(game, sizeof(t_list), 7);
	new_node->line = game->map->line;
	new_node->next = NULL;
	return (new_node);
}
