/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:33:04 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 17:44:40 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Checks whether the user has entered a single valid map
void	check_program_argument(int argc, char *argv)
{
	if (argc < 2)
		error_occurred(NULL, NO_FILE);
	else if (argc > 2)
		error_occurred(NULL, MULTIPLE_FILES);
	check_argument_extension(argv);
}

// ? Checks whether the string entered as an argument ends with .ber
void	check_argument_extension(char *argv)
{
	char	*ber;
	size_t	index;

	ber = ".ber";
	index = string_length(argv);
	if (index < 4)
		error_occurred(NULL, UNRECOGNISED_EXTENSION);
	index -= 4;
	while (*ber)
		if (*ber++ != argv[index++])
			error_occurred(NULL, UNRECOGNISED_EXTENSION);
}
