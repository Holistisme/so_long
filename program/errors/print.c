/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:29:23 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 16:17:12 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Informs the user of an error
void	print_error(char *error_message)
{
	write(2, "Error\n", string_length("Error\n"));
	write(2, error_message, string_length(error_message));
}
