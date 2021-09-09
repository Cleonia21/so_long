/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:12:37 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 13:12:38 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	put_image(t_game *game, void *obj, int x, int y)
{
	x = x * CEL_SIZE;
	y = y * CEL_SIZE;
	mlx_put_image_to_window(game->data.mlx, game->data.win, obj, x, y);
}

int	render(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->data.mlx, game->data.win);
	y = 0;
	while (y < game->map.line_num)
	{
		x = 0;
		while (x < game->map.colum_num)
		{
			put_image(game, game->map_obj.empty, x, y);
			if (game->map.map[y][x] == WALL)
				put_image(game, game->map_obj.wall, x, y);
			if (game->map.map[y][x] == HERRO)
				put_image(game, game->map_obj.herro, x, y);
			if (game->map.map[y][x] == FOOD)
				put_image(game, game->map_obj.food, x, y);
			if (game->map.map[y][x] == EXIT)
				put_image(game, game->map_obj.exit, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
