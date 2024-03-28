/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:00:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 14:47:36 by aheitz           ###   ########.fr       */
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
	size_t	y;
	size_t	x;
}	t_position;

typedef struct s_focus
{
	int	x;
	int	y;
}	t_focus;

// ? The structure for the castle graphics
typedef struct s_castle
{
	int			count;
	mlx_image_t	*english;
	mlx_image_t	*french;
}	t_castle;

// ? The structure for the grass graphics
typedef struct s_grass
{
	int			count;
	mlx_image_t	*dark;
	mlx_image_t	*light;
}	t_grass;

// ? The structure for the ground graphics
typedef struct s_ground
{
	int			count;
	t_grass		*left_grass;
	t_grass		*right_grass;
	t_grass		*simple_grass;
	mlx_image_t	*snow;
}	t_ground;

// ? The structure for Paris graphics
typedef struct s_paris
{
	mlx_image_t	*english;
	mlx_image_t	*french;
}	t_paris;

// ? The graphics (or their structure) of the game
typedef struct s_graphics
{
	mlx_image_t	*limit;
	t_castle	*castle;
	t_ground	*ground;
	t_focus		*background_focus;
	t_paris		*paris;
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
	t_position	*current_position;
	t_position	*exit;
	t_position	*spawn;
}	t_map;

// ? The game structure containing the most essential elements.
typedef struct s_game
{
	mlx_t		*window;
	t_graphics	*graphics;
	t_map		*map;
}	t_game;

#endif