/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:16:41 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 16:52:49 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* calculating the number of rows and columns of the map,
and checking for rectangle */
static	int	map_size(char	*file, t_map *map)
{
	char	*line;
	int		retval;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (E_FILE_OPEN);
	retval = get_next_line(fd, &line);
	map->colum_num = ft_strlen(line);
	map->line_num = 1;
	while (retval > 0)
	{
		free (line);
		retval = get_next_line(fd, &line);
		if (map->colum_num != (int)ft_strlen(line))
			retval = E_FORM;
		map->line_num++;
	}
	free (line);
	close (fd);
	return (retval);
}

/* reopen and write oll from file to massiv */
static	int	from_file_to_map(char *file, t_map *map)
{
	int	fd;
	int	retval;
	int	y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (E_FILE_OPEN);
	map->map = (char **)malloc(sizeof(char *) * map->line_num + 1);
	map->map[map->line_num] = NULL;
	if (!(map->map))
		return (E_MEMORY_ALLOCATION);
	y = 1;
	retval = get_next_line(fd, &(map->map[0]));
	while (retval > 0)
	{
		retval = get_next_line(fd, &(map->map[y]));
		y++;
	}
	close (fd);
	return (retval);
}

static	int	check_ber(char *str)
{
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '\0')
		return (E_FILE_FORMAT);
	if (*(str + 1) == 'b' && *(str + 2) == 'e'
		&& *(str + 3) == 'r' && *(str + 4) == '\0')
		return (0);
	else
		return (E_FILE_FORMAT);
	return (0);
}

static	int	initial_map(t_game *game, char **argv)
{
	int	retval;

	game->move = 0;
	retval = check_ber(argv[1]);
	if (retval != 0)
		return (retval);
	retval = map_size(argv[1], &game->map);
	if (retval != 0)
		return (retval);
	retval = from_file_to_map(argv[1], &game->map);
	if (retval != 0)
		return (retval);
	retval = check_characters(game);
	if (retval != 0)
		return (retval);
	return (0);
}

int	initial_game(t_game *game, int argc, char **argv)
{
	int	retval;

	game->map.map = NULL;
	game->data.mlx = NULL;
	game->data.win = NULL;
	game->map_obj.empty = NULL;
	if (argc != 2)
		return (E_FILE_OPEN);
	game->data.mlx = mlx_init();
	if (game->data.mlx == NULL)
		return (E_MLX);
	retval = initial_map(game, argv);
	if (retval != 0)
		return (retval);
	game->data.win = mlx_new_window(game->data.mlx,
			game->map.colum_num * CEL_SIZE,
			game->map.line_num * CEL_SIZE, "SoLong");
	if (game->data.win == NULL)
		return (E_MLX);
	initial_map_obj(&game->map_obj, game->data.mlx);
	game->process = TRUE;
	return (0);
}
