/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 11:07:37 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// * The program to launch the game
int	main(int argc, char **argv)
{
	t_game	*game;

	srand(time(NULL)); // Utilisez la fonction time(NULL) pour initialiser le générateur avec une graine différente à chaque exécution
	check_program_argument(argc, argv);
	game = NULL;
	game = allocate(NULL, sizeof(t_game), 3);
	game->map = NULL;
	game->map = allocate(game, sizeof(t_map), 4);
	set_map_to_null(&game->map);
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd == -1)
		error_occurred(game, 5);
	save_map(game);
	close(game->map->fd);
	set_map(game);
	start_game(game);
	free_game(&game);
	return (0);
}
