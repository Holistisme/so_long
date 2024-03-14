/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:16:43 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/19 11:06:27 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Checks if there is one and only one map file and its validity
void	check_program_argument(int argc, char **argv)
{
	if (argc < 2)
		error_occurred(NULL, 0);
	else if (argc > 2)
		error_occurred(NULL, 1);
	check_argument_extension(argv[1]);
}

// ? Checks if the map extension is .ber
void	check_argument_extension(char *file_name)
{
	char	*ber;
	size_t	index;

	ber = ".ber";
	index = string_length(file_name);
	if (index < 4)
		error_occurred(NULL, 2);
	index -= 4;
	while (*ber)
		if (*ber++ != file_name[index++])
			error_occurred(NULL, 2);
}
