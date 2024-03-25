/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:47:15 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/25 11:50:10 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "so_long.h"

// * The various error enumerations
typedef enum e_error
{
	NO_FILE,
	MULTIPLE_FILES,
	UNRECOGNISED_EXTENSION,
	UNALLOCATED_GAME,
	UNALLOCATED_MAP,
	// ! BAR
	// ! Error related to file opening
	INVALID_FD,
	// ! Errors related to get_next_line program
	NULL_GNL,
	NODE_ALLOCATION,
	// ! Errors related to map requirements
	MAP_TOO_SMALL,
	MAP_TOO_WIDE,
	RECTANGULAR_MAP,
	INVALID_LIMITS,
	// ! Error related to map cell allocation
	CELLS_ALLOCATION,
	// ! Errors related to map elements
	UNRECOGNISED_ELEMENT,
	POSITION_ALLOCATION,
	MULTIPLE_SPAWN,
	MULTIPLE_EXIT,
	NO_COLLECTIBLE,
	NO_SPAWN,
	NO_EXIT,
	// ! Errors related to copy allocation and path verification!
	CLONED_CELLS_ALLOCATION,
	CLONED_LINE_ALLOCATION,
	INVALID_PATH,
	// * NEW ERRORS
	WINDOW_ALLOCATION,
	GRAPHICS_ALLOCATION,
	LOADING_TEXTURE,
	IMAGE_ALLOCATION,
	CHARACTER_ALLOCATION,
	MILL_TEXTURE,
	GRASS_COUNTER,
	GRASS_TEXTURE,
	BLOCKING_ALLOCATION,
	GUARDS_ALLOCATION,
	GUARDS_WAITING_ALLOCATION
}	t_error;

#endif