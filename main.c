/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:39:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/01/09 16:50:06 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	t_list	*main_file;
	t_list	*current;

	fd = open("main.c", O_RDONLY);
	main_file = create_list(fd);
	current = main_file;
	while (current)
	{
		printf("%s", current->line);
		current = current->next;
	}
	free_list(main_file);
	close(fd);
	return (0);
}
