/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:46:14 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 17:03:59 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "so_long.h"

// * Functions from the "program" folder :
// ? Functions from the "errors.c" file :
void	error_occurred(t_game **game, t_error error);
void	print_error(char *error_message);

// ! FUNCTIONS TO SORT
void	check_program_argument(int argc, char *argv);
void	check_argument_extension(char *argv, char *ber, int index);
void	allocate(t_game **game, size_t size, void **ptr, t_error error);
void	free_game(t_game **game);
void	free_list(t_list **head, t_list *current);
void	create_node(t_game **game, t_list **new_node, char *line);
void	save_map(t_game **game, int fd, char *line, t_list *current);

#endif