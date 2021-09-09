/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_map_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:16:12 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 14:45:45 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initial_map_obj(t_map_obj *map_obj, void *mlx)
{
	int	x;
	int	y;

	x = CEL_SIZE;
	y = CEL_SIZE;
	map_obj->wall = mlx_xpm_file_to_image(mlx, "pictures/wall.xpm", &x, &y);
	map_obj->empty = mlx_xpm_file_to_image(mlx, "pictures/empty.xpm", &x, &y);
	map_obj->herro = mlx_xpm_file_to_image(mlx, "pictures/herro.xpm", &x, &y);
	map_obj->food = mlx_xpm_file_to_image(mlx, "pictures/food.xpm", &x, &y);
	map_obj->exit = mlx_xpm_file_to_image(mlx, "pictures/exit.xpm", &x, &y);
}
