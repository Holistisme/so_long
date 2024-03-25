/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:00:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 16:00:29 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "so_long.h"

// ? The linked list structure to guarantee GNL results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

// * The map and its key information
typedef struct s_map
{
	//char			**cells;
	//char			**cloned_cells;
	//char			*line;
	//int				collectibles;
	//int				fields;
	//int				mills;
	//size_t			height;
	//size_t			width;
	//t_position		*spawn;
	//t_position		*exit;
	//t_position		*position_scan;
	t_list	*list;
}	t_map;

// * The game structure containing the most essential elements.
typedef struct s_game
{
	t_map		*map;
	//mlx_t		*window;
	//t_graphics	*graphics;
	//t_character	*character;
	//size_t		day;
	//mlx_image_t *victory;
}	t_game;

#endif