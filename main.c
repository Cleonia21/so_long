/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:26:17 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 16:48:58 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_game *game)
{
	game_exit(game, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		retval;

	retval = initial_game(&game, argc, argv);
	if (retval != 0)
		game_exit(&game, retval);
	mlx_hook(game.data.win, 17, 0L, destroy, (void *)&game);
	mlx_hook(game.data.win, 2, 1L << 2, my_hook, (void *)&game);
	mlx_loop_hook(game.data.mlx, render, (void *)&game);
	mlx_loop(game.data.mlx);
	return (0);
}
