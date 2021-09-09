/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:22:24 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 13:25:22 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* calculates the number of characters on the map
and the coordinates of the last */
static	int	search_charct(char **map, char charct, int *y, int *x)
{
	int	charct_num;
	int	i;
	int	j;

	charct_num = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == charct)
			{
				charct_num++;
				*y = i;
				*x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (charct_num);
}

/* checking if the card is closed */
static	int	check_closed(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < game->map.colum_num)
	{
		if (game->map.map[0][x] != WALL ||
				game->map.map[game->map.line_num - 1][x] != WALL)
			return (E_CLOUSE);
		x++;
	}
	y = 0;
	while (y < game->map.line_num)
	{
		if (game->map.map[y][0] != WALL ||
				game->map.map[y][game->map.colum_num - 1] != WALL)
			return (E_CLOUSE);
		y++;
	}
	return (0);
}

/* compare argument sumbol whith oll valid sumbols */
static	int	compare(char c)
{
	if (c == EMPTY || c == WALL || c == HERRO || c == FOOD || c == EXIT)
		return (0);
	return (E_FORBID_SYMBOL);
}

/* check for extraneous characters */
static	int	forbiden_charct(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (compare(map[i][j]))
				return (E_FORBID_SYMBOL);
			j++;
		}
		i++;
	}
	return (0);
}

/* search for the necessary objects, checking their number.
Also check if the map is closed by walls */
int	check_characters(t_game *game)
{
	int	*y;
	int	*x;

	y = &game->obj_pos.herro_y;
	x = &game->obj_pos.herro_x;
	if (search_charct(game->map.map, EXIT, y, x) == 0)
		return (E_EXIT);
	game->obj_pos.food_num = search_charct(game->map.map, FOOD, y, x);
	if (game->obj_pos.food_num == 0)
		return (E_FOOD);
	if (search_charct(game->map.map, HERRO, y, x) != 1)
		return (E_HERRO);
	if (check_closed(game) == E_CLOUSE)
		return (E_CLOUSE);
	if (forbiden_charct(game->map.map) != 0)
		return (E_FORBID_SYMBOL);
	return (0);
}
