/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:46:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 19:21:03 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "./directive.h"

// * Functions from the "checks" folder :
// ? Functions from the "argument.c" file :
void	check_argument_extension(char *argv);
void	check_program_argument(int argc, char *argv);
// ? Functions from the "elements.c" file :
void	check_if_game_is_complet(t_game *game);
void	define_key_position(t_game *game, t_position **pos);
void	save_element(t_game *game);
void	scan_cells_elements(t_game *game);
// ? Functions from the "map.c" file :
void	check_if_map_has_limits(t_game *game);
void	check_if_map_is_adapted(t_game *game);
void	check_if_map_is_rectangular(t_game *game);
// ? Functions from the "pathway.c" file :
int		scan_pathway(t_game *game, size_t y, size_t x);
void	check_pathway_validity(t_game *game);
void	clone_cells(t_game *game);

// * Functions from the "errors" folder :
// ? Functions from the "occurences.c" file :
int		elements_validity_error_occured(t_error error);
int		map_validity_error_occured(t_error error);
int		unallocated_error_occured(t_error error);
void	error_occurred(t_game *game, t_error error);
// ? Functions from the "print.c" file :
void	print_error(char *error_message);

// * Functions from the "map" folder :
// ? Functions from the "cells.c" file :
void	copy_line_into_cell(t_game *game, size_t y, char *current_line);
void	set_cells(t_game *game);
// ? Functions from the "saving.c" file :
int		open_fd(t_game *game, char *argv);
t_list	*create_node(t_game *game);
void	save_map_in_a_list(t_game *game, int fd);
void	get_map(t_game *game, char *argv);
// ? Functions from the "setup.c" file :
void	set_map(t_game *game, char *argv);
// ? Functions from the "sizes.c" file :
size_t	get_width(char *line);
void	set_height(t_game *game);

// * Functions from the "memory" folder :
// ? Functions from the "allocation.c" file :
void	*allocation(t_game *game, size_t size, t_error error);
// ? Functions from the "freeing.c" file :
void	free_cells(char ***cells);
void	free_game(t_game **game);
void	free_list(t_list **head);
void	free_map(t_map **map);

// * Functions from the "utils" folder :
// ? Functions from the "is_inside.c" file :
int		is_inside(char c, char *string);

//! TO SORT :
void	set_animation(t_game *game, int element, int textures, ...);

#endif