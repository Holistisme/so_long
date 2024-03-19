/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seasons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:59:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/18 11:40:17 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * At the encounter of a key day, will proceed to the setting up of a season
void	check_season(t_game *game)
{
	if (game->day == 60)
		first_fresh_season_is_here(game);
	else if (game->day == 90)
		exchange_textures(game->graphics->field->winter,
			game->graphics->field->spring, game->map->fields);
	else if (game->day == 120)
		hot_season_is_here(game);
	else if (game->day == 240)
		second_fresh_season_is_here(game);
	else if (game->day == 270)
		exchange_textures(game->graphics->field->fall,
			game->graphics->field->winter, game->map->fields);
	else if (game->day == 300)
		winter_is_here(game);
}

// ? Process for displaying the first fresh season
void	first_fresh_season_is_here(t_game *game)
{
	display_instances(game->graphics->ground->snow,
		game->graphics->ground->count, false);
	display_instances(game->graphics->ground->simple_grass->dark,
		game->graphics->ground->simple_grass->count, true);
	{
		if (game->graphics->ground->left_grass)
			display_instances(game->graphics->ground->left_grass->dark,
				game->graphics->ground->left_grass->count, true);
		if (game->graphics->ground->right_grass)
			display_instances(game->graphics->ground->right_grass->dark,
				game->graphics->ground->right_grass->count, true);
	}
}

// ? Process for displaying the hot season
void	hot_season_is_here(t_game *game)
{
	exchange_textures(game->graphics->ground->simple_grass->dark,
		game->graphics->ground->simple_grass->light,
		game->graphics->ground->simple_grass->count);
	if (game->graphics->ground->left_grass)
		exchange_textures(game->graphics->ground->left_grass->dark,
			game->graphics->ground->left_grass->light,
			game->graphics->ground->left_grass->count);
	if (game->graphics->ground->right_grass)
		exchange_textures(game->graphics->ground->right_grass->dark,
			game->graphics->ground->right_grass->light,
			game->graphics->ground->right_grass->count);
	exchange_textures(game->graphics->field->spring,
		game->graphics->field->summer, game->map->fields);
}

// ? Process for displaying the second fresh season
void	second_fresh_season_is_here(t_game *game)
{
	exchange_textures(game->graphics->ground->simple_grass->light,
		game->graphics->ground->simple_grass->dark, 
		game->graphics->ground->simple_grass->count);
	if (game->graphics->ground->left_grass)
		exchange_textures(game->graphics->ground->left_grass->light,
			game->graphics->ground->left_grass->dark,
			game->graphics->ground->left_grass->count);
	if (game->graphics->ground->right_grass)
		exchange_textures(game->graphics->ground->right_grass->light,
			game->graphics->ground->right_grass->dark,
			game->graphics->ground->right_grass->count);
	exchange_textures(game->graphics->field->summer,
		game->graphics->field->fall, game->map->fields);
}

// ? Process for displaying the winter season
void	winter_is_here(t_game *game)
{
	display_instances(game->graphics->ground->simple_grass->dark,
		game->graphics->ground->simple_grass->count, false);
	if (game->graphics->ground->left_grass)
		display_instances(game->graphics->ground->left_grass->dark,
			game->graphics->ground->left_grass->count, false);
	if (game->graphics->ground->right_grass)
		display_instances(game->graphics->ground->right_grass->dark,
			game->graphics->ground->right_grass->count, false);
	display_instances(game->graphics->ground->snow,
		game->graphics->ground->count, true);
}
