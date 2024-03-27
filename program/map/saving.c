/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:36:50 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:32:50 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Calls up fd opening, then manages map saving in a chained list 
// * before closing the fd.
void	get_map(t_game *game, char *argv)
{
	int		fd;

	fd = open_fd(game, argv);
	save_map_in_a_list(game, fd);
	close(fd);
}

// ? Opens file descriptor and checks if functional
int	open_fd(t_game *game, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_occurred(game, INVALID_FD);
	return (fd);
}

// ? Gradually creates a chained list from nodes of lines read by GNL
void	save_map_in_a_list(t_game *game, int fd)
{
	t_list	*current;

	game->map->gnl_line = get_next_line(fd);
	if (!game->map->gnl_line)
		error_occurred(game, NULL_LINE);
	game->map->gnl_map = create_node(game);
	current = game->map->gnl_map;
	game->map->gnl_line = get_next_line(fd);
	while (game->map->gnl_line)
	{
		current->next = create_node(game);
		current = current->next;
		game->map->gnl_line = get_next_line(fd);
	}
}

// ? Creates a node with the result of GNL for the chain list
t_list	*create_node(t_game *game)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = allocation(game, sizeof(t_list), UNALLOCATED_NODE);
	new_node->line = NULL;
	new_node->line = game->map->gnl_line;
	new_node->next = NULL;
	return (new_node);
}
