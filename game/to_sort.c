// int	move_confirmation(t_game *game, int x, int y)
// {
// 	if (game->map->cells[x][y] == '1')
// 		return (0);
// 	return (1);
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
