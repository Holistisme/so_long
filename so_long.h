/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 08:56:15 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
#include <stdio.h> //! A SUICIDER A LA FIN

typedef struct s_border
{
	mlx_image_t	*first;
	mlx_image_t	*second;
	mlx_image_t	*third;
	mlx_image_t	*fourth;
	mlx_image_t	*fifth;
}	t_border;

typedef struct s_paris
{
	mlx_image_t	*english;
	mlx_image_t	*french;
}	t_paris;

typedef struct s_castle
{
	mlx_image_t	*english;
	mlx_image_t	*french;
}	t_castle;

typedef struct s_mill
{
	mlx_image_t	*first;
	mlx_image_t	*second;
}	t_mill;

typedef struct s_field
{
	mlx_image_t	*spring;
	mlx_image_t	*summer;
	mlx_image_t	*fall;
	mlx_image_t	*winter;
}	t_field;

typedef struct s_grass
{
	int			count;
	mlx_image_t	*dark;
	mlx_image_t	*light;
}	t_grass;

typedef struct s_mountain
{
	mlx_image_t	*middle;
	mlx_image_t	*left;
	mlx_image_t	*right;
	mlx_image_t	*peak;
}	t_mountain;

typedef struct s_blocking
{
	mlx_image_t	*long_range;
	mlx_image_t	*medium_range;
	mlx_image_t	*short_range;
}	t_blocking;

typedef struct s_waiting
{
	mlx_image_t	*back;
	mlx_image_t	*front;
	mlx_image_t	*left;
	mlx_image_t	*right;
}	t_waiting;

typedef struct s_guard
{
	int			count;
	int			index;
	size_t		current_frame;
	t_blocking	*back;
	t_blocking	*front;
	t_blocking	*left;
	t_blocking	*right;
	t_waiting	*waiting;
}	t_guard;

typedef struct s_character
{
	mlx_image_t *skin;
	t_position	*position;
}				t_character;

typedef enum e_texture
{
	CHARACTER,
	BLOCKING
}	t_texture;

typedef enum e_direction
{
	BACK,
	FRONT,
	LEFT,
	RIGHT
}	t_direction;

#endif