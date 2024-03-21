/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:36:51 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/21 14:04:10 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*start_animation(void *arg)
{
	t_game	*game;

	game = arg;
	while (1)
	{
		guards_animation(game);
		check_season(game);
		if (game->graphics->mill)
			mill_animation(game);
		if (game->day < 180)
			first_half_year(game);
		if (game->day > 150)
			second_half_year(game);
		++game->day;
		if (game->day > 360)
			game->day = 0;
		usleep(250000);
		printf("DAY : %zu\n", game->day);
	}
	return (NULL);
}
