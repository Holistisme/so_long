/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/12 20:26:17 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// The linked list to guarantee GNL results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

// The enumeration for error codes
typedef enum e_err_code
{
	ERR_LIMITS,
	ERR_NON_RECT,
	ERR_UNKNOWN_POS,
	ERR_MANY_SPAWNS,
	ERR_MANY_EXITS,
	ERR_NO_COLLECT,
	ERR_BAD_PATH,
	ERR_INIT_ELEMENTS
}				t_err_code;

// The structure for the list of map elements
typedef struct s_elem
{
	int			collectibles;
	int			spawn;
	int			exit;
}				t_elem;

// Functions from list_mgmt.c
t_list	*create_list(int fd);
t_list	*create_node(char *line);
void	list_error(void);
void	free_list(t_list *head);

// Functions from checks.c
void	map_checking(t_list *head);
int		rectangle_checking(t_list *head);
int		limits_checking(t_list *head);
int		elem_map_checking(t_list *head, t_elem *elements);
int		elem_count_checking(t_elem *elements);

// Functions from checks_utils.c
int		set_elem(t_elem *elem_struct);
size_t	get_width(char *line);
void	error_indication(t_err_code code);
void	error_mgmt(t_list *head, t_elem *elem_struct, t_err_code code);

#endif