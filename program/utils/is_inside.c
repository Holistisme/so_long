/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:09:39 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/27 16:10:05 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Returns 1 if the character is found in the string. Otherwise 0
int	is_inside(char c, char *string)
{
	size_t	scan;

	scan = 0;
	while (string[scan])
		if (c == string[scan++])
			return (1);
	return (0);
}
