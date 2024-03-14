// int	move_confirmation(t_game *game, int x, int y)
// {
// 	if (game->map->cells[x][y] == '1')
// 		return (0);
// 	return (1);
// }

// void	display_texture(t_game *game, mlx_image_t **texture, size_t x, size_t y)
// {
// 	mlx_image_to_window(game->window, *texture, x * 64, y * 64);
// }

// void	check_case(t_game *game)
// {
// 	if (game->map->cells[game->character->x / 64][game->character->y / 64] == 'C' && game->graphics->chest->instances[check_instance(game)].enabled)
// 	{
// 		game->graphics->chest->instances[check_instance(game)].enabled = false;
// 		--game->map->collectibles;
// 		if (!game->map->collectibles)
// 			time_to_quit(game);
// 	}
// 	if (game->map->cells[game->character->x / 64][game->character->y / 64] == 'E' && game->graphics->portal->enabled)
// 	{
// 		free_game(game);
// 		write(1, "VICTORY!\n", 9);
// 	}
// }

// int	check_instance(t_game *game)
// {
// 	int		number;
// 	size_t	line;
// 	size_t	column;

// 	number = -1;
// 	line = 0;
// 	while (game->map->cells[line])
// 	{
// 		column = 0;
// 		while (game->map->cells[line][column])
// 		{
// 			if (game->map->cells[line][column] == 'C')
// 				++number;
// 			if (line == game->character->x / 64 && column == game->character->y / 64)
// 				break;
// 			++column;
// 		}
// 		if (line == game->character->x / 64 && column == game->character->y / 64)
// 			break;
// 		++line;
// 	} 
// 	return (number);
// }

// void	time_to_quit(t_game *game)
// {
// 	game->graphics->portal->enabled = true;
// }
