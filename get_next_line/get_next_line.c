/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:39:37 by aheitz            #+#    #+#             */
/*   Updated: 2023/12/07 16:17:39 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (*buffer = '\0', NULL);
	return (read_to_stock(fd, buffer));
}

char	*read_to_stock(int fd, char *buffer)
{
	char	*stock;
	ssize_t	read_bytes;

	stock = NULL;
	read_bytes = 42;
	if (*buffer)
		stock = stock_buffer(buffer, stock);
	while (read_bytes > 0 && search_newline(stock) < 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(stock), *buffer = '\0', NULL);
		buffer[read_bytes] = '\0';
		stock = stock_buffer(buffer, stock);
	}
	if (stock && *stock)
		return (update_buffer(buffer), extract_line(stock));
	return (free(stock), *buffer = '\0', NULL);
}
