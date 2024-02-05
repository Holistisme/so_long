/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 18:29:35 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

// The linked list to guarantee GNL results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

// The structure for the map loaded by the player
typedef struct s_map
{
	char		**cells;
	int			collectibles;
	int			spawn_x;
	int			spawn_y;
	size_t		height;
	size_t		width;
}				t_map;

// The enumeration for error codes
typedef enum e_error_code
{
	ERROR_NO_FILE,
	ERROR_MULTIPLE_FILES,
	ERROR_UNRECOGNISED_EXTENSION,
	ERROR_INVALID_FD,
	ERROR_UNRECOGNISED_ELEMENT,
	ERROR_INSUFFICIENT_SPACE,
	ERROR_INVALID_LIMITS,
	ERROR_NON_RECTANGULAR_MAP,
	ERROR_NO_SPAWN,
	ERROR_TOO_MANY_SPAWNS,
	ERROR_NO_COLLECTIBLE,
	ERROR_NO_EXIT,
	ERROR_TOO_MANY_EXITS,
	ERROR_INVALID_PATH,
	ERROR_UNALLOCATED_CELLS
}				t_error_code;

// Functions from verifications/cells_validity.c
void	check_cells_validity(t_map *map);
void	check_number_elements(t_map *map, int spawn, int exit);
void	erroneous_cells(t_map *map, t_error_code code);

// Functions from initialization/set_map.c
t_map	*set_map(t_list *list);
void	set_cells(t_list *head, t_map *map);
size_t	get_height(t_list *head);
size_t	get_width(char *line);
void	free_map(t_map *map);

// Functions from verifications/map_validity.c
void	check_map_validity(t_list *head, t_map *map);
int		map_is_quite_large(size_t height, size_t width);
int		map_is_rectangular(t_list *head, size_t width);
int		map_has_limits(t_list *head, size_t width);
void	erroneous_map(t_list *head, t_map *map, t_error_code code);

// Functions from verifications/map_file.c
void	check_map_file(int argc, char **argv);
void	check_extension(char *file_name);
void	erroneous_file_name(t_error_code code);

// Functions from other/utilities.c
size_t	get_size(char *string);
char	*remove_newline(char *string, size_t width);
int		define_spawn(t_map *map, size_t coordinates_x, size_t coordinates_y);
void	termination(char *error_message);

// Functions from initialization/set_list.c
t_list	*set_list(int fd);
t_list	*create_node(char *line);
void	free_list(t_list *head);

// Functions from verifications/pathway.c
void	check_pathway_validity(t_map *map);
char	**copy_cells(t_map *map);
int		scan_map(size_t x, size_t y, char **cells);
void	erroneous_path(t_map *map, char **cells, t_error_code code);
void	free_cells(char **cells);

#endif