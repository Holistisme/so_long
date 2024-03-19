/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   months.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:01:28 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 15:23:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_months_textures(t_game *game)
{
	set_texture(game, &game->graphics->month->january,
		"./textures/months/january.png");
	set_texture(game, &game->graphics->month->february,
		"./textures/months/february.png");
	set_texture(game, &game->graphics->month->march,
		"./textures/months/march.png");
	set_texture(game, &game->graphics->month->april,
		"./textures/months/april.png");
	set_texture(game, &game->graphics->month->may,
		"./textures/months/may.png");
	set_texture(game, &game->graphics->month->june,
		"./textures/months/june.png");
	set_texture(game, &game->graphics->month->july,
		"./textures/months/july.png");
	set_texture(game, &game->graphics->month->august,
		"./textures/months/august.png");
	set_texture(game, &game->graphics->month->september,
		"./textures/months/september.png");
	set_texture(game, &game->graphics->month->october,
		"./textures/months/october.png");
	set_texture(game, &game->graphics->month->november,
		"./textures/months/november.png");
	set_texture(game, &game->graphics->month->december,
		"./textures/months/december.png");
}

void	display_months(t_game *game)
{
	load_months_textures(game);
	display_texture(game, &game->graphics->month->january,
		game->graphics->month->position);
	display_and_disable(game, &game->graphics->month->february,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->march,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->april,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->may,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->june,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->july,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->august,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->september,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->october,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->november,
		game->graphics->month->position, 0);
	display_and_disable(game, &game->graphics->month->december,
		game->graphics->month->position, 0);
}

void	first_half_year(t_game *game)
{
	if (game->day == 0)
		exchange_textures(game->graphics->month->december,
			game->graphics->month->january, 0);
	if (game->day == 30)
		exchange_textures(game->graphics->month->january,
			game->graphics->month->february, 0);
	if (game->day == 60)
		exchange_textures(game->graphics->month->february,
			game->graphics->month->march, 0);
	if (game->day == 90)
		exchange_textures(game->graphics->month->march,
			game->graphics->month->april, 0);
	if (game->day == 120)
		exchange_textures(game->graphics->month->april,
			game->graphics->month->may, 0);
	if (game->day == 150)
		exchange_textures(game->graphics->month->may,
			game->graphics->month->june, 0);
}

void	second_half_year(t_game *game)
{
	if (game->day == 180)
		exchange_textures(game->graphics->month->june,
			game->graphics->month->july, 0);
	if (game->day == 210)
		exchange_textures(game->graphics->month->july,
			game->graphics->month->august, 0);
	if (game->day == 240)
		exchange_textures(game->graphics->month->august,
			game->graphics->month->september, 0);
	if (game->day == 270)
		exchange_textures(game->graphics->month->september,
			game->graphics->month->october, 0);
	if (game->day == 300)
		exchange_textures(game->graphics->month->october,
			game->graphics->month->november, 0);
	if (game->day == 330)
		exchange_textures(game->graphics->month->november,
			game->graphics->month->december, 0);
}
