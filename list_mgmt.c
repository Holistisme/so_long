/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:06:43 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/09 16:06:35 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Creates a linked list of lines read by GNL
t_list	*create_list(int fd)
{
	t_list	*head;
	t_list	*current;
	char	*line;

	head = create_node(get_next_line(fd));
	if (!head)
		return (NULL);
	current = head;
	line = get_next_line(fd);
	while (line)
	{
		current->next = create_node(line);
		if (!current->next)
		{
			free_list(head);
			return (NULL);
		}
		current = current->next;
		line = get_next_line(fd);
	}
	return (head);
}

// Creates a node with the line returned by GNL
t_list	*create_node(char *line)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node || !line)
		return (NULL);
	new_node->line = line;
	new_node->next = NULL;
	return (new_node);
}

// Frees list memory
void	free_list(t_list *head)
{
	t_list	*current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current->line);
		free(current);
	}
}
