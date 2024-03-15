/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:36:51 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 16:41:50 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*start_animation(void *arg)
{
	t_game *game;

	game = arg;
	months_generation(game);
	while (1)
	{
		check_season(game);
		mill_animation(game);
		months_animation(game);
		fields_animation(game);
		++game->day;
		if (game->day > 360)
			game->day = 0;
		usleep(250000);
	}
	return (NULL);
}

void	fields_animation(t_game *game)
{
	int	index;

	index = 0;
	while (index <= game->map->fields)
	{
		if (game->day < 60 || game->day > 330)
		{
			game->graphics->field->spring->instances[index].enabled = false;
			game->graphics->field->summer->instances[index].enabled = false;
			game->graphics->field->fall->instances[index].enabled = false;
			game->graphics->field->winter->instances[index].enabled = true;
		}
		else if (game->day > 240)
		{
			game->graphics->field->winter->instances[index].enabled = false;
			game->graphics->field->spring->instances[index].enabled = false;
			game->graphics->field->summer->instances[index].enabled = false;
			game->graphics->field->fall->instances[index].enabled = true;
		}
		else if (game->day > 150)
		{
			game->graphics->field->fall->instances[index].enabled = false;
			game->graphics->field->winter->instances[index].enabled = false;
			game->graphics->field->spring->instances[index].enabled = false;
			game->graphics->field->summer->instances[index].enabled = true;
		}
		else if (game->day > 60)
		{
			game->graphics->field->summer->instances[index].enabled = false;
			game->graphics->field->fall->instances[index].enabled = false;
			game->graphics->field->winter->instances[index].enabled = false;
			game->graphics->field->spring->instances[index].enabled = true;
		}
		++index;
	}
}

void	months_generation(t_game *game)
{
	game->graphics->month->position = allocate(game, sizeof(t_position), MILL_TEXTURE); //TODO : Changer le code d'erreur!
	game->graphics->month->position->x = 0;
	game->graphics->month->position->y = game->map->width / 2 - 1;
	display_texture(game, &game->graphics->month->january, game->graphics->month->position);
	display_texture(game, &game->graphics->month->february, game->graphics->month->position);
	game->graphics->month->february->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->march, game->graphics->month->position);
	game->graphics->month->march->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->april, game->graphics->month->position);
	game->graphics->month->april->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->may, game->graphics->month->position);
	game->graphics->month->may->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->june, game->graphics->month->position);
	game->graphics->month->june->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->july, game->graphics->month->position);
	game->graphics->month->july->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->august, game->graphics->month->position);
	game->graphics->month->august->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->september, game->graphics->month->position);
	game->graphics->month->september->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->october, game->graphics->month->position);
	game->graphics->month->october->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->november, game->graphics->month->position);
	game->graphics->month->november->instances[0].enabled = false;
	display_texture(game, &game->graphics->month->december, game->graphics->month->position);
	game->graphics->month->december->instances[0].enabled = false;
}

void	months_animation(t_game *game)
{
	if (game->day == 0)
	{
		game->graphics->month->december->instances[0].enabled = false;
		game->graphics->month->january->instances[0].enabled = true;
	}
	if (game->day == 30)
	{
		game->graphics->month->january->instances[0].enabled = false;
		game->graphics->month->february->instances[0].enabled = true;
	}
	if (game->day == 60)
	{
		game->graphics->month->february->instances[0].enabled = false;
		game->graphics->month->march->instances[0].enabled = true;
	}
	if (game->day == 90)
	{
		game->graphics->month->march->instances[0].enabled = false;
		game->graphics->month->april->instances[0].enabled = true;
	}
	if (game->day == 120)
	{
		game->graphics->month->april->instances[0].enabled = false;
		game->graphics->month->may->instances[0].enabled = true;
	}
	if (game->day == 150)
	{
		game->graphics->month->may->instances[0].enabled = false;
		game->graphics->month->june->instances[0].enabled = true;
	}
	if (game->day == 180)
	{
		game->graphics->month->june->instances[0].enabled = false;
		game->graphics->month->july->instances[0].enabled = true;
	}
	if (game->day == 210)
	{
		game->graphics->month->july->instances[0].enabled = false;
		game->graphics->month->august->instances[0].enabled = true;
	}
	if (game->day == 240)
	{
		game->graphics->month->august->instances[0].enabled = false;
		game->graphics->month->september->instances[0].enabled = true;
	}
	if (game->day == 270)
	{
		game->graphics->month->september->instances[0].enabled = false;
		game->graphics->month->october->instances[0].enabled = true;
	}
	if (game->day == 300)
	{
		game->graphics->month->october->instances[0].enabled = false;
		game->graphics->month->november->instances[0].enabled = true;
	}
	if (game->day == 330)
	{
		game->graphics->month->november->instances[0].enabled = false;
		game->graphics->month->december->instances[0].enabled = true;
	}
}
