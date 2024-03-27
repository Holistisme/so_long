/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:00:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 19:22:24 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "./directive.h"

// * Structures for the smooth running of the project
// ? The linked list structure to guarantee GNL results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

// ? The coordinates storage structure
typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_position;

// ? The structure for the castle graphics
typedef struct s_castle
{
	int			elements;
	mlx_image_t	*english;
	mlx_image_t	*french;
}	t_castle;

// ? The graphics (or their structure) of the game
typedef struct s_graphics
{
	t_castle	*castle;
}	t_graphics;

// ? The map and its key information
typedef struct s_map
{
	char		**cells;
	char		**cloned_cells;
	char		*gnl_line;
	int			collectibles;
	size_t		height;
	size_t		width;
	t_list		*gnl_map;
	t_position	*spawn;
	t_position	*exit;
	t_position	*current_position;
}	t_map;

// ? The game structure containing the most essential elements.
typedef struct s_game
{
	mlx_t		*window;
	t_graphics	*graphics;
	t_map		*map;
}	t_game;

#endif