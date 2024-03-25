/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 12:02:16 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// * The program head that calls each key step
int	main(int argc, char **argv)
{
	t_game	*game;

	//srand(time(NULL)); // Utilisez la fonction time(NULL) pour initialiser le générateur avec une graine différente à chaque exécution //!
	check_program_argument(argc, argv);
	game = NULL;
	game = allocation(NULL, sizeof(t_game), UNALLOCATED_GAME);
	game->map = NULL;
	game->map = allocation(game, sizeof(t_map), UNALLOCATED_MAP);
	//set_map_to_null(&game->map);
	//game->map->fd = open(argv[1], O_RDONLY);
	//if (game->map->fd == -1)
	//	error_occurred(game, 5);
	//save_map(game);
	//close(game->map->fd);
	//set_map(game);
	//start_game(game);
	//free_game(&game);
	//printf("CHECK!");
	free_game(&game);
	return (0);
}

// error_occurred(game, UNALLOCATED_GAME); //! TEST D'ERREUR

// ? Checks whether the user has entered a single valid map
void	check_program_argument(int argc, char **argv)
{
	if (argc < 2)
		error_occurred(NULL, NO_FILE);
	else if (argc > 2)
		error_occurred(NULL, MULTIPLE_FILES);
	check_argument_extension(argv[1]);
}


// ? Checks whether the string entered as an argument ends with .ber
void	check_argument_extension(char *file_name)
{
	char	*ber;
	size_t	index;

	ber = ".ber";
	index = string_length(file_name);
	if (index < 4)
		error_occurred(NULL, UNRECOGNISED_EXTENSION);
	index -= 4;
	while (*ber)
		if (*ber++ != file_name[index++])
			error_occurred(NULL, UNRECOGNISED_EXTENSION);
}

// * Frees allocated memory, calls to inform user, then exits program
void	error_occurred(t_game *game, t_error error)
{
	free(game);
	if (error == NO_FILE)
		print_error("No argument to get the game map!");
	else if (error == MULTIPLE_FILES)
		print_error("Too many arguments to choose a game map!");
	else if (error == UNRECOGNISED_EXTENSION)
		print_error("Invalid map extension!");
	else if (error == UNALLOCATED_GAME)
		print_error("Allocation for game structure fails!");
	else if (error == UNALLOCATED_MAP)
		print_error("Allocation for map structure fails!");
	exit(EXIT_FAILURE);
}

// ? Informs the user of an error
void	print_error(char *error_message)
{
	write(2, "Error\n", string_length("Error\n"));
	write(2, error_message, string_length(error_message));
}

// * Allocates memory with malloc and handles error if it fails
void	*allocation(t_game *game, size_t size, t_error error)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_occurred(game, error);
	return (ptr);
}

// * Frees game memory by calling free sub-functions
void	free_game(t_game **game)
{
	if (game && *game)
	{
		//free_map(&(*game)->map);
		free((*game)->map);
		free(*game);
		*game = NULL;
	}
}
