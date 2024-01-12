/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/12 20:40:04 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Main test program
int	main(void)
{
	int		fd;
	t_list	*map_file;
	t_list	*current;

	fd = open("map.ber", O_RDONLY);
	map_file = create_list(fd);
	close(fd);
	current = map_file;
	while (current)
	{
		printf("%s", current->line);
		current = current->next;
	}
	printf("\n\n");
	map_checking(map_file);
	free_list(map_file);
	return (0);
}
