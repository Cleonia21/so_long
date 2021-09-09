/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:29:31 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 16:51:57 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

# define	CEL_SIZE	16 /* размер минимальной площади */

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_map_obj
{
	void	*wall;
	void	*empty;
	void	*herro;
	void	*food;
	void	*exit;
}				t_map_obj;

typedef struct s_map
{
	char	**map;
	int		line_num;
	int		colum_num;
}				t_map;

typedef struct s_obj_pos
{
	int		herro_x;
	int		herro_y;
	int		food_num;
}				t_obj_pos;

typedef struct s_game
{
	t_data		data;
	t_map_obj	map_obj;
	t_map		map;
	t_obj_pos	obj_pos;
	int			move;
	int			process;
}				t_game;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

enum e_map
{
	EMPTY = '0',
	HERRO = 'P',
	WALL = '1',
	FOOD = 'C',
	EXIT = 'E',
};

enum e_errors
{
	E_MLX = -10,
	E_FILE_READ = -1,
	E_FILE_OPEN = -2,
	E_FILE_FORMAT = -11,
	E_MEMORY_ALLOCATION = -3,
	E_CLOUSE = -4,
	E_HERRO = -5,
	E_EXIT = -6,
	E_FOOD = -7,
	E_FORM = -8,
	E_FORBID_SYMBOL = -9
};

size_t	ft_strlen(const char *str);
void	char_mas_print(char **mas);
void	game_exit(t_game *game, int error);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	initial_map_obj(t_map_obj *map_obj, void *mlx);
int		render(t_game *game);
int		initial_game(t_game *game, int argc, char **argv);
int		my_hook(int key, t_game *game);
int		check_characters(t_game *game);

#endif
