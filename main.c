/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/02/05 18:47:29 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// Main test program
int	main(int argc, char **argv)
{
	int		fd;
	t_list	*premap;
	t_map	*map;

	check_map_file(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		erroneous_file_name(ERROR_INVALID_FD);
	premap = set_list(fd);
	map = set_map(premap);
	size_t i;
	i = 0;
	while (map->cells[i])
		printf("%s", map->cells[i++]);
	free_map(map);
	return (0);
}
