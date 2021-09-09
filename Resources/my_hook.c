/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:13:17 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 13:14:38 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	new_herro_pos(int key, t_game *game, int *y, int *x)
{
	*y = game->obj_pos.herro_y;
	*x = game->obj_pos.herro_x;
	if (key == KEY_UP)
		(*y)--;
	if (key == KEY_DOWN)
		(*y)++;
	if (key == KEY_LEFT)
		(*x)--;
	if (key == KEY_RIGHT)
		(*x)++;
}

int	key_exit(t_game *game)
{
	if (game->obj_pos.food_num == 0)
	{
		game->map.map[game->obj_pos.herro_y][game->obj_pos.herro_x] = EMPTY;
		game->process = FALSE;
		printf("The game is over. Thanks for participating.");
		printf("Your score: %d\n", ++game->move);
		printf("Click ESC to clouse the window.\n");
	}
	return (0);
}

int	my_hook(int key, t_game *game)
{
	int	new_y;
	int	new_x;

	if (key == ESC)
		game_exit(game, 0);
	if (game->process == TRUE)
	{
		new_herro_pos(key, game, &new_y, &new_x);
		if (game->map.map[new_y][new_x] == WALL)
			return (0);
		if (game->map.map[new_y][new_x] == EXIT)
			return (key_exit(game));
		game->map.map[game->obj_pos.herro_y][game->obj_pos.herro_x] = EMPTY;
		if (game->map.map[new_y][new_x] == FOOD)
			game->obj_pos.food_num--;
		game->map.map[new_y][new_x] = HERRO;
		game->obj_pos.herro_y = new_y;
		game->obj_pos.herro_x = new_x;
		printf("number of movements: %d\n", ++game->move);
	}
	return (0);
}
