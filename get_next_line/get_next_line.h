/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:39:14 by aheitz            #+#    #+#             */
/*   Updated: 2023/12/07 16:19:22 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*extract_line(char *string);
char	*get_next_line(int fd);
char	*stock_buffer(char *buffer, char *stocked_char);
char	*read_to_stock(int fd, char *buffer);
size_t	string_length(char *string);
ssize_t	search_newline(char *string);
void	update_buffer(char *buffer);

#endif