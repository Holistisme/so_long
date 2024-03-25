/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:42 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 11:59:31 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../../get_next_line/get_next_line.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include "enum.h"
# include "structs.h"
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
#include <stdio.h> //! A SUICIDER A LA FIN

// * Structures for the smooth running of the project
// ? The coordinates storage structure
typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_position;

// ? The linked list structure to guarantee get_next_line results
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

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

typedef struct s_ground
{
	t_grass		*simple_grass;
	t_grass		*left_grass;
	t_grass		*right_grass;
	mlx_image_t	*snow;
	int			count;
}	t_ground;

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

typedef struct s_month
{
	t_position	*position;
	mlx_image_t	*january;
	mlx_image_t	*february;
	mlx_image_t	*march;
	mlx_image_t	*april;
	mlx_image_t	*may;
	mlx_image_t	*june;
	mlx_image_t	*july;
	mlx_image_t	*august;
	mlx_image_t	*september;
	mlx_image_t	*october;
	mlx_image_t	*november;
	mlx_image_t	*december;
}	t_month;

// * NEW
typedef struct s_graphics
{
	mlx_image_t		*limit;
	mlx_image_t		*deep_water;
	mlx_image_t		*water;
	mlx_image_t		*sandy_water;
	mlx_image_t		*sand;
	mlx_image_t		*wall;
	mlx_image_t		*tower;
	mlx_image_t 	*battle;
	mlx_image_t 	*house;
	mlx_image_t 	*pine;
	mlx_image_t 	*pine_stump;
	mlx_image_t 	*snowy_pine;
	mlx_image_t 	*tree;
	mlx_image_t 	*pine_tree;
	mlx_image_t 	*apple_tree;
	mlx_image_t 	*tree_stump;
	mlx_image_t 	*rock;
	mlx_image_t 	*two_rocks;
	mlx_image_t 	*three_rocks;
	mlx_image_t 	*plain_rock;
	mlx_image_t 	*two_plain_rocks;
	mlx_image_t 	*three_plain_rocks;
	mlx_image_t 	*hill_rock;
	mlx_image_t 	*two_hill_rocks;
	mlx_image_t 	*three_hill_rocks;
	mlx_image_t 	*snowy_rock;
	mlx_image_t 	*two_snowy_rocks;
	mlx_image_t 	*three_snowy_rocks;
	t_castle		*castle;
	t_ground		*ground;
	t_mill			*mill;
	t_field			*field;
	t_month			*month;
	t_paris			*paris;
	t_border		*border;
	t_mountain		*mountain;
	t_guard			*guards;
}	t_graphics;

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

void	check_program_argument(int argc, char **argv);
void	check_argument_extension(char *file_name);
void	print_error(char *error_message);
void	error_occurred(t_game *game, t_error error);
void	print_error(char *error_message);
void	*allocation(t_game *game, size_t size, t_error error);
void	free_game(t_game **game);

//! BAR
// * Functions from the "error/" folder :
// ? Functions from the "management.c" file :
void	report_error_a(t_error code);
void	report_error_b(t_error code);

// ? Functions from the "free.c" file :
void	free_game(t_game **game);
void	set_map_to_null(t_map **map);
void	free_map(t_map **map);
void	free_cells(char ***cells);
void	free_list(t_list **head);

// * Functions from the "checking/" folder :
// ? Functions from the "elements.c" file :
void	scan_cells_elements(t_game *game);
void	save_element(t_game *game, size_t x, size_t y);
void	define_key_position(t_game *game, t_position **pos, size_t x, size_t y);
void	check_if_game_is_complet(t_game *game);

// ? Functions from the "pathway.c" file :
void	check_pathway_validity(t_game *game);
void	clone_cells(t_game *game);
int		scan_pathway(t_game *game, size_t x, size_t y);
int		is_inside(char c, char *string);

// ? Functions from the "map.c" file :
void	check_if_map_is_adapted(t_game *game);
void	check_if_map_is_rectangular(t_game *game);
void	check_if_map_has_limits(t_game *game);

// * Functions from the "setup/" folder :
// ? Functions from the "save_map.c" file :
void	save_map(t_game *game);
t_list	*create_node(t_game *game);

// ? Functions from the "set_map.c" file :
void	set_map(t_game *game);
void	set_cells(t_game *game);
void	copy_node_to_cell(t_game *game, size_t y, char *line);
size_t	get_height(t_list *head);
size_t	get_width(char *line);

//! NEW
void	set_game(t_game *game);
void	open_window(t_game *game);
void	set_graphics(t_game *game);
void	set_texture(t_game *game, mlx_image_t **target, const char *path);
void	load_graphics(t_game *game);
void	display_texture(t_game *game, mlx_image_t **texture, t_position *position);
void	char_is_digit(t_game *game, t_position *position);
void	char_is_uppercase(t_game *game, t_position *position);
void	start_game(t_game *game);
void	set_character(t_game *game);
void	move_request(mlx_key_data_t key_data, void *param);

void	*start_animation(void *arg);

void	fields_animation(t_game *game);
void	grass_animation(t_game *game);
void	char_is_lowercase(t_game *game, t_position *position);

void	months_animation(t_game *game);
void	months_generation(t_game *game);
void	grass_generation(t_game *game);

void	add_mill(t_game *game, t_position *position);
void	load_mill_texture(t_game *game);
void	mill_animation(t_game *game);
void	display_instances(mlx_image_t *image, size_t count, bool is_displayed);
void	display_and_disable(t_game *game, mlx_image_t **image,
			t_position *position, size_t index);
void	exchange_textures(mlx_image_t *old, mlx_image_t *new, size_t size);
void	check_season(t_game *game);
void	new_grass(t_game *game, t_position *position, char c);
void	grass_initilization(t_game *game, t_grass **grass,
			const char *dark, const char *light);
void	add_grass(t_game *game, t_grass **grass,
			t_position *position);
void	check_season(t_game *game);
void	first_fresh_season_is_here(t_game *game);
void	hot_season_is_here(t_game *game);
void	second_fresh_season_is_here(t_game *game);
void	winter_is_here(t_game *game);
void	new_field(t_game *game, t_position *position);
void	field_initilization(t_game *game);
void	add_field(t_game *game, t_position *position);
void	load_months_textures(t_game *game);
void	display_months(t_game *game);
void	first_half_year(t_game *game);
void	second_half_year(t_game *game);
void	set_castle_textures(t_game *game);
void	take_castle(t_game *game);
int	get_castle_index(t_game *game);
void	set_paris_textures(t_game *game);
void	take_paris(t_game *game);
char	get_random_grass(void);
mlx_image_t	**get_random_border_texture(t_border *border);
void	set_borders_textures(t_game *game);
void	set_moutains_textures(t_game *game);
void	display_mountain(t_game *game, char c, t_position *position);
void	set_guards_textures(t_game *game);
void	add_guard(t_game **game, t_blocking **blocking);
void	display_character_texture(t_game *game, mlx_image_t **texture, t_position *position);
void	display_and_disable_character(t_game *game, mlx_image_t **image,
	t_position *position, size_t index);
void	guard_waiting(t_game *game, t_guard *guard, size_t index);
void	guard_blocking(t_guard *guard, t_blocking *direction);
int	is_stopping_blocking(t_guard *guard, t_blocking *direction);
void	stop_waiting(t_guard *guard);
void	guards_animation(t_game *game);
int	is_player_near(t_game *game);
void	display_and_disable_blocking(t_game *game, mlx_image_t **image, t_position *position, size_t index);
void	guard_order(t_game *game);
void	switch_an_instance(mlx_image_t *previous, mlx_image_t *next, size_t index);
void	display_an_instance(mlx_image_t *target, size_t index, bool is_displayed);
void	intitialize_but_disable(t_game **game, mlx_image_t **image, t_texture texture, size_t index);
void	set_lateral_side_blocking_textures(t_game *game,
	t_blocking **blocking, t_direction direction);
void	set_vertical_side_blocking_textures(t_game *game,
	t_blocking **blocking, t_direction direction);

#endif