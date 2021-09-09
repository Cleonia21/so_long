/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:22:13 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 16:55:05 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	errors(char error)
{
	if (error == E_FILE_FORMAT)
		printf("Error\nFile not in format \".ber\".\n");
	if (error == E_MLX)
		printf("Error\n\"mlx\" library function.\n");
	if (error == E_FILE_READ)
		printf("Error\nFile not read.\n");
	if (error == E_FILE_OPEN)
		printf("Error\nFile not open.\n");
	if (error == E_MEMORY_ALLOCATION)
		printf("Error\nMemory was not allocated.\n");
	if (error == E_CLOUSE)
		printf("Error\nThe map is not surrounded by a wall.\n");
	if (error == E_HERRO)
		printf("Error\nThe hero is not on the map.\n");
	if (error == E_EXIT)
		printf("Error\nThere's no exit out on the map\n");
	if (error == E_FOOD)
		printf("Error\nNo food on the map.\n");
	if (error == E_FORM)
		printf("Error\nMap is not rectangular.\n");
	if (error == E_FORBID_SYMBOL)
		printf("Error\nUnrecognized symbol on the card\n");
}

/* free char **mas */
static	void	free_map(char ***map)
{
	char	*buf;
	char	**buf2;

	if (*map && **map && map)
	{
		buf2 = *map;
		while (**map)
		{
			buf = **map;
			(*map)++;
			free (buf);
		}
		free (buf2);
	}
}

static	void	free_game(t_game *game)
{
	if (game->data.win)
		mlx_destroy_window(game->data.mlx, game->data.win);
	if (game->map_obj.empty)
	{
		mlx_destroy_image(game->data.mlx, game->map_obj.empty);
		mlx_destroy_image(game->data.mlx, game->map_obj.exit);
		mlx_destroy_image(game->data.mlx, game->map_obj.food);
		mlx_destroy_image(game->data.mlx, game->map_obj.herro);
		mlx_destroy_image(game->data.mlx, game->map_obj.wall);
	}
}

void	game_exit(t_game *game, int error)
{
	free_map(&game->map.map);
	free_game(game);
	errors(error);
	exit(0);
}
