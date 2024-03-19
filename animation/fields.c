/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:48:17 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/18 11:38:07 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * Manages new field entries
void	new_field(t_game *game, t_position *position)
{
	if (!game->graphics->field)
		field_initilization(game);
	add_field(game, position);
}

// ? Initialize graphics for fields
void	field_initilization(t_game *game)
{
	game->graphics->field = allocate(game, sizeof(t_field), 0); // TODO CHANGER ERREUR
	set_texture(game, &game->graphics->field->fall,
		"./textures/fields/fall.png");
	set_texture(game, &game->graphics->field->spring,
		"./textures/fields/spring.png");
	set_texture(game, &game->graphics->field->summer,
		"./textures/fields/summer.png");
	set_texture(game, &game->graphics->field->winter,
		"./textures/fields/winter.png");
}

// ? Adds the four colored fields graphics to the map
void	add_field(t_game *game, t_position *position)
{
	display_and_disable(game, &game->graphics->field->fall,
		position, game->map->fields);
	display_and_disable(game, &game->graphics->field->spring,
		position, game->map->fields);
	display_and_disable(game, &game->graphics->field->summer,
		position, game->map->fields);
	display_texture(game, &game->graphics->field->winter, position);
	++game->map->fields;
}
