/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/09 16:46:40 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

// The linked list to guarantee GNL results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}				t_list;

// Functions from list_mgmt.c
t_list	*create_list(int fd);
t_list	*create_node(char *line);
void	free_list(t_list *head);

#endif