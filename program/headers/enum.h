/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:47:15 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 10:14:11 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H
# include "./directive.h"

// * The various error enumerations
typedef enum e_error
{
	// ! Errors related to allocations
	UNALLOCATED_CELL,
	UNALLOCATED_CELLS,
	UNALLOCATED_CLONED_CELLS,
	UNALLOCATED_CLONED_LINE,
	UNALLOCATED_GAME,
	UNALLOCATED_MAP,
	UNALLOCATED_NODE,
	UNALLOCATED_POSITION,
	NULL_LINE,
	// ! Errors related to map validity
	INVALID_FD,
	INVALID_LIMITS,
	MAP_TOO_SMALL,
	MAP_TOO_WIDE,
	MULTIPLE_FILES,
	NO_FILE,
	NON_RECTANGULAR_MAP,
	UNRECOGNISED_EXTENSION,
	// ! Errors related to elements validity
	INVALID_PATHWAY,
	MULTIPLE_EXIT,
	MULTIPLE_SPAWN,
	NO_COLLECTIBLE,
	NO_EXIT,
	NO_SPAWN,
	UNRECOGNISED_ELEMENT,
	// ! Errors related to game allocations
	UNALLOCATED_CASTLE,
	UNALLOCATED_IMAGE,
	UNALLOCATED_FOCUS,
	UNALLOCATED_GRAPHICS,
	UNALLOCATED_GRASS,
	UNALLOCATED_GROUND,
	UNALLOCATED_PARIS,
	UNALLOCATED_WINDOW,
	UNLOADED_TEXTURE,
}	t_error;

#endif