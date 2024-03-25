/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 17:04:50 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// * The program head that calls each key step
int	main(int argc, char **argv)
{
	t_game	*game;

	//srand(time(NULL)); // Utilisez la fonction time(NULL) pour initialiser le générateur avec une graine différente à chaque exécution //!
	check_program_argument(argc, argv[1]);
	game = NULL;
	allocate(&game, sizeof(t_game), (void*)&game, UNALLOCATED_GAME);
	game->map = NULL;
	allocate(&game, sizeof(t_map),  (void*)&game->map, UNALLOCATED_MAP);
	save_map(&game, open(argv[1], O_RDONLY), NULL, NULL);
	//set_map(game);
	//start_game(game);
	//free_game(&game);
	//printf("CHECK!");
	free_game(&game);
	return (0);
}

//! error_occurred(game, UNALLOCATED_GAME); //! TEST D'ERREUR

// ? Checks whether the user has entered a single valid map
void	check_program_argument(int argc, char *argv)
{
	if (argc < 2)
		error_occurred(NULL, NO_FILE);
	else if (argc > 2)
		error_occurred(NULL, MULTIPLE_FILES);
	check_argument_extension(argv, ".ber\0", string_length(argv) - 4);
}

// ? Checks whether the string entered as an argument ends with .ber
void	check_argument_extension(char *argv, char *ber, int index)
{
	if (index < 0)
		error_occurred(NULL, UNRECOGNISED_EXTENSION);
	while (*ber)
		if (*ber++ != argv[index++])
			error_occurred(NULL, UNRECOGNISED_EXTENSION);
}

// * Saves all lines read with GNL to a linked list
void	save_map(t_game **game, int fd, char *line, t_list *current)
{
	if (fd == -1)
		error_occurred(game, INVALID_FD);
	line = get_next_line(fd);
	if (!line)
		error_occurred(game, NULL_LINE);
	create_node(game, &(*game)->map->list, line);
	current = (*game)->map->list;
	line = get_next_line(fd);
	while (line)
	{
		create_node(game, &current->next, line);
		current = current->next;
		line = get_next_line(fd);
	}
	close(fd);
}

// ? Creates a node with the result of GNL for the chain list
void	create_node(t_game **game, t_list **new_node, char *line)
{
	allocate(game, sizeof(t_list), (void*)new_node, UNALLOCATED_NODE);
	(*new_node)->line = NULL;
	(*new_node)->line = line;
	(*new_node)->next = NULL;
}
