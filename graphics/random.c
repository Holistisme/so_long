/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:08:06 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/19 14:38:31 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_random_grass(void)
{
	int	probability;

	probability = rand() % 100;
	if (probability < 5)
		return ('L');
	else if (probability < 10)
		return ('R');
	else
		return ('S');
}
