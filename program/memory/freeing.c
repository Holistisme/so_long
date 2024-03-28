/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:04:26 by aheitz            #+#    #+#             */
/*   Updated: 2024/03/28 16:36:43 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/directive.h"

// * Frees game memory by calling free sub-functions
void	free_game(t_game **game)
{
	if (game && *game)
	{
		if ((*game)->window)
			mlx_terminate((*game)->window);
		free_graphics(&(*game)->graphics); //POTENTIEL PROBLEME
		free_map(&(*game)->map);
		free(*game);
		*game = NULL;
	}
}

// ! Frees map memory by calling free sub-functions
void	free_map(t_map **map)
{
	if (map && *map)
	{
		if ((*map)->cells)
			free_cells(&(*map)->cells);
		if ((*map)->cloned_cells)
			free_cells(&(*map)->cloned_cells);
		if ((*map)->gnl_line)
			free((*map)->gnl_line);
		if ((*map)->gnl_map)
			free_list(&(*map)->gnl_map);
		if ((*map)->current_position)
			free((*map)->current_position);
		if ((*map)->exit)
			free((*map)->exit);
		if ((*map)->spawn)
			free((*map)->spawn);
		free(*map);
		*map = NULL;
	}
}

// ! Frees memory for a linked list
void	free_list(t_list **head)
{
	t_list	*current;

	current = NULL;
	if (head)
	{
		while (*head)
		{
			current = *head;
			*head = (*head)->next;
			free(current->line);
			current->line = NULL;
			free(current);
			current = NULL;
		}
	}
}

// ! Frees memory for a double character pointer
void	free_cells(char ***cells)
{
	size_t	index;

	index = 0;
	if (cells && *cells)
	{
		while ((*cells)[index])
		{
			free((*cells)[index]);
			(*cells)[index++] = NULL;
		}
		free(*cells);
		*cells = NULL;
	}
}

void	free_graphics(t_graphics **graphics)
{
	if (graphics && *graphics)
	{
		if ((*graphics)->castle)
			free((*graphics)->castle);
		if ((*graphics)->paris)
			free((*graphics)->paris);
		if ((*graphics)->ground)
		{
			if ((*graphics)->ground->left_grass)
				free((*graphics)->ground->left_grass);
			if ((*graphics)->ground->right_grass)
				free((*graphics)->ground->right_grass);
			if ((*graphics)->ground->simple_grass)
				free((*graphics)->ground->simple_grass);
			free((*graphics)->ground);
		}
		if ((*graphics)->background_focus)
			free((*graphics)->background_focus);
		free(*graphics);
		*graphics = NULL;
	}
}

void	free_graphics_structure(t_game *game, void **structure, int textures, ...)
{
	mlx_image_t	**image;
	va_list		args;

	va_start(args, textures);
	while (textures--)
	{
		image = va_arg(args, mlx_image_t **);
		mlx_delete_image(game->window, *image);
		*image = NULL;
	}
	if (structure && *structure)
	{
		free(*structure);
		*structure = NULL;
	}
	va_end(args);
}
