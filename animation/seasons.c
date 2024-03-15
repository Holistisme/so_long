/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seasons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:59:34 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/15 15:09:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// * At the encounter of a key day, will proceed to the setting up of a season
void	check_season(t_game *game)
{
	if (game->day == 60)
		first_fresh_season_is_here(game->graphics->ground);
	else if (game->day == 120)
		hot_season_is_here(game->graphics->ground);
	else if (game->day == 240)
		second_fresh_season_is_here(game->graphics->ground);
	else if (game->day == 300)
		winter_is_here(game->graphics->ground);
}

// ? Process for displaying the first fresh season
void	first_fresh_season_is_here(t_ground *ground)
{
	display_instances(ground->snow, ground->count, false);
	display_instances(ground->simple_grass->dark,
		ground->simple_grass->count, true);
	{
		if (ground->left_grass)
			display_instances(ground->left_grass->dark,
				ground->left_grass->count, true);
		if (ground->right_grass)
			display_instances(ground->right_grass->dark,
				ground->right_grass->count, true);
	}
}

// ? Process for displaying the hot season
void	hot_season_is_here(t_ground *ground)
{
	exchange_textures(ground->simple_grass->dark,
		ground->simple_grass->light, ground->simple_grass->count);
	if (ground->left_grass)
		exchange_textures(ground->left_grass->dark,
			ground->left_grass->light, ground->left_grass->count);
	if (ground->right_grass)
		exchange_textures(ground->right_grass->dark,
			ground->right_grass->light, ground->right_grass->count);
}

// ? Process for displaying the second fresh season
void	second_fresh_season_is_here(t_ground *ground)
{
	exchange_textures(ground->simple_grass->light,
		ground->simple_grass->dark, ground->simple_grass->count);
	if (ground->left_grass)
		exchange_textures(ground->left_grass->light,
			ground->left_grass->dark, ground->left_grass->count);
	if (ground->right_grass)
		exchange_textures(ground->right_grass->light,
			ground->right_grass->dark, ground->right_grass->count);
}

// ? Process for displaying the winter season
void	winter_is_here(t_ground *ground)
{
	display_instances(ground->simple_grass->dark,
		ground->simple_grass->count, false);
	if (ground->left_grass)
		display_instances(ground->left_grass->dark,
			ground->left_grass->count, false);
	if (ground->right_grass)
		display_instances(ground->right_grass->dark,
			ground->right_grass->count, false);
	display_instances(ground->snow, ground->count, true);
}
