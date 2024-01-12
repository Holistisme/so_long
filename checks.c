/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:18:49 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/12 20:37:54 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checking(t_list *head)
{
	int			elem_count_checking_value;
	t_elem		*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem || set_elem(elem) == -1)
		error_mgmt(head, NULL, ERR_INIT_ELEMENTS);
	if (limits_checking(head) == -1)
		error_mgmt(head, elem, ERR_LIMITS);
	if (rectangle_checking(head) == -1)
		error_mgmt(head, elem, ERR_NON_RECT);
	if (elem_map_checking(head, elem) == -1)
		error_mgmt(head, elem, ERR_UNKNOWN_POS);
	elem_count_checking_value = elem_count_checking(elem);
	if (elem_count_checking_value == -1)
		error_mgmt(head, elem, ERR_MANY_SPAWNS);
	if (elem_count_checking_value == -2)
		error_mgmt(head, elem, ERR_NO_COLLECT);
	if (elem_count_checking_value == -3)
		error_mgmt(head, elem, ERR_MANY_EXITS);
	free(elem);
}

int		limits_checking(t_list *head)
{
	size_t	index;
	t_list	*current;

	index = 0;
	while (head->line[index] != '\n')
		if (head->line[index++] != '1')
			return (-1);
	current = head->next;
	while (current->next)
	{
		if (current->line[0] != '1' || current->line[index - 1] != '1')
			return (-1);
		current = current->next;
	}
	index = 0;
	while (current->line[index])
		if (current->line[index++] != '1')
			return (-1);
	return (0);
}

int		elem_map_checking(t_list *head, t_elem *elements)
{
	size_t		i;
	t_list		*current;

	current = head->next;
	while (current->next)
	{
		i = 1;
		while (current->line[i] != '\n')
		{
			if (current->line[i] == 'C')
				++elements->collectibles;
			else if (current->line[i] == 'P')
				++elements->spawn;
			else if (current->line[i] == 'E')
				++elements->exit;
			else if (current->line[i] != '0' && current->line[i] != '1')
				return (-1);
			++i;
		}
		current = current->next;
	}
	return (0);
}

int		elem_count_checking(t_elem *elements)
{
	if (elements->spawn != 1)
		return (-1);
	if (!elements->collectibles)
		return (-2);
	if (elements->exit != 1)
		return (-3);
	return (0);
}

int		rectangle_checking(t_list *head)
{
	t_list	*scan;

	scan = head->next;
	while (scan)
	{
		if (get_width(scan->line) != get_width(head->line))
			return (-1);
		scan = scan->next;
	}
	return (0);
}
