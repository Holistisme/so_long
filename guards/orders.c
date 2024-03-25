/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:02 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/22 16:26:58 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// ? Checks that the guard doesn't stop blocking,
// ? otherwise take a random waiting pose
void	guard_waiting(t_game *game, t_guard *guard, size_t index)
{
	int		probability;

	if (is_stopping_blocking(guard, guard->left)) // ?
		return ;
	//if (is_stopping_blocking(guard, guard->back)) // ?
	//	return ;
	stop_waiting(guard);
	probability = rand() % 100;
	if (probability < 25)
		game->graphics->guards->waiting->back->instances[index].enabled = true;
	else if (probability < 50)
		game->graphics->guards->waiting->front->instances[index].enabled = true;
	else if (probability < 75)
		game->graphics->guards->waiting->left->instances[index].enabled = true;
	else
		game->graphics->guards->waiting->right->instances[index].enabled = true;
}

// ? Disables waiting instances to gradually stretch a guard's spear
void	guard_blocking(t_guard *guard, t_blocking *direction)
{
	if (direction->long_range->instances[guard->index].enabled)
		return ;
	else if (direction->medium_range->instances[guard->index].enabled)
		switch_an_instance(direction->medium_range,
			direction->long_range, guard->index);
	else if (direction->short_range->instances[guard->index].enabled)
		switch_an_instance(direction->short_range,
			direction->medium_range, guard->index);
	else
	{
		stop_waiting(guard);
		direction->short_range->instances[guard->index].enabled = true;
	}
}

// ? If a blocking image is enable, gradually disables it.
int	is_stopping_blocking(t_guard *guard, t_blocking *direction)
{
	if (direction->long_range->instances[guard->index].enabled)
	{
		switch_an_instance(direction->long_range, direction->medium_range, guard->index);
		return (1);
	}
	else if (direction->medium_range->instances[guard->index].enabled)
	{
		switch_an_instance(direction->medium_range, direction->short_range, guard->index);
		return (1);
	}
	else if (direction->short_range->instances[guard->index].enabled)
		direction->short_range->instances[guard->index].enabled = false;
	return (0);
}

// ? If a waiting image is enable, disables it.
void	stop_waiting(t_guard *guard)
{
	if (guard->waiting->back->instances[guard->index].enabled)
		guard->waiting->back->instances[guard->index].enabled = false;
	else if (guard->waiting->front->instances[guard->index].enabled)
		guard->waiting->front->instances[guard->index].enabled = false;
	else if (guard->waiting->left->instances[guard->index].enabled)
		guard->waiting->left->instances[guard->index].enabled = false;
	else if (guard->waiting->right->instances[guard->index].enabled)
		guard->waiting->right->instances[guard->index].enabled = false;
}
