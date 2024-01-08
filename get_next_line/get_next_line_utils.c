/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:40:04 by aheitz            #+#    #+#             */
/*   Updated: 2023/12/07 16:22:19 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_buffer(char *buffer)
{
	size_t	index_after_newline;
	size_t	index;

	if (!*buffer)
		return ;
	index = 0;
	index_after_newline = search_newline(buffer) + 1;
	while (buffer[index_after_newline])
		buffer[index++] = buffer[index_after_newline++];
	buffer[index] = '\0';
}

char	*stock_buffer(char *buffer, char *stocked_char)
{
	char	*stocked_buffer;
	void	*stocked_buffer_ptr;
	size_t	index;

	stocked_buffer = malloc(string_length(stocked_char) + \
		string_length(buffer) + 1);
	if (!stocked_buffer)
		return (free(stocked_char), *buffer = '\0', NULL);
	stocked_buffer_ptr = stocked_buffer;
	index = 0;
	if (stocked_char)
	{
		while (stocked_char[index])
			*stocked_buffer++ = stocked_char[index++];
	}
	while (*buffer)
		*stocked_buffer++ = *buffer++;
	*stocked_buffer = '\0';
	return (free(stocked_char), stocked_buffer_ptr);
}

ssize_t	search_newline(char *string)
{
	size_t	index;

	if (!string)
		return (-1);
	index = 0;
	while (string[index])
	{
		if (string[index] == '\n')
			return (index);
		++index;
	}
	return (-1);
}

char	*extract_line(char *string)
{
	char	*line;
	size_t	index;

	if (!string)
		return (NULL);
	if (search_newline(string) >= 0)
		line = malloc(search_newline(string) + 2);
	else
		line = malloc(string_length(string) + 1);
	if (!line)
		return (free(string), NULL);
	index = 0;
	while (string[index])
	{
		if (string[index] == '\n')
		{
			line[index++] = '\n';
			break ;
		}
		line[index] = string[index];
		++index;
	}
	line[index] = '\0';
	return (free(string), line);
}

size_t	string_length(char *string)
{
	size_t	length;

	length = 0;
	if (!string)
		return (length);
	while (string[length])
		++length;
	return (length);
}
