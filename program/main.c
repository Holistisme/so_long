/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 16:01:26 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/directive.h"

// * The program head that calls each key step
int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	srand(time(NULL));
	check_program_argument(argc, argv[1]);
	game = allocation(game, sizeof(t_game), UNALLOCATED_GAME);
	game->map = NULL;
	game->graphics = NULL;
	game->window = NULL;
	game->map = allocation(game, sizeof(t_map), UNALLOCATED_MAP);
	set_map(game, argv[1]);
	set_game(game);
	free_game(&game);
	return (0);
}
