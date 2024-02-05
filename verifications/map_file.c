/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:16:43 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 17:56:07 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Checks if there is one and only one map file and its validity
void	check_map_file(int argc, char **argv)
{
	if (argc < 2)
		erroneous_file_name(ERROR_NO_FILE);
	else if (argc > 2)
		erroneous_file_name(ERROR_MULTIPLE_FILES);
	check_extension(argv[1]);
}

// Checks if the map extension is .ber
void	check_extension(char *file_name)
{
	char	*ber;
	size_t	index;

	ber = ".ber";
	index = get_size(file_name);
	if (index < 5)
		erroneous_file_name(ERROR_UNRECOGNISED_EXTENSION);
	index -= 4;
	while (*ber)
		if (*ber++ != file_name[index++])
			erroneous_file_name(ERROR_UNRECOGNISED_EXTENSION);
}

// Depending on the error code, stops the program and inform the user
void	erroneous_file_name(t_error_code code)
{
	if (code == ERROR_NO_FILE)
		termination("No map specified!");
	else if (code == ERROR_MULTIPLE_FILES)
		termination("Too many maps have been detected!");
	else if (code == ERROR_UNRECOGNISED_EXTENSION)
		termination("The file requested is not a .ber!");
	else if (code == ERROR_INVALID_FD)
		termination("Map opening failed!");
}
