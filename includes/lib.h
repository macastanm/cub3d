/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:39:41 by ccosta-c          #+#    #+#             */
/*   Updated: 2024/01/04 14:55:31 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <X11/X.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# define RED "\033[1;31m"
# define NRM "\033[0;37m"
# define BLD "\033[1;37m"
# define GRN "\033[1;32m"
# define GRY "\033[38;2;150;150;150m"

# define HEIGHT 920
# define WIDTH 1920
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_info
{
	char	*file_path;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		f_color;
	bool	floor_rgb;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		c_color;
	bool	ceiling_rgb;
}			t_info;

typedef struct s_textures
{
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_textures;

typedef struct s_data
{
	t_info		*info;
	t_textures	*img;
	t_textures	*aux;
	t_textures	*no;
	t_textures	*so;
	t_textures	*we;
	t_textures	*ea;
	void		*win;
	void		*mlx;
	char		**og_map;
	char		**map;
	int			map_height;
	int			map_width;
	bool		map_found;
	float		p_x;
	float		p_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			i;
	int			mapx;
	int			mapy;
	double		pwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			draw_start;
	int			draw_end;
	int			lineheight;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		text_step;
	double		text_pos;
	int			press_a;
	int			press_d;
	int			press_w;
	int			press_s;
	int			press_right;
	int			press_left;
}				t_data;

///////////////////////parser.c////////////////////////
void		parser(t_data *data);
void		get_tex_col(t_data *data, int fd);
int			get_textures(t_data *data, char *line);
int			get_colors(t_data	*data, char *line);
int			get_colors_xtra(t_data *data, char *line, char *tile, char place);

///////////////////////checks.c////////////////////////
void		check_colors(t_data *data);
void		check_extension(char *file, char *extension);
void		check_textures(t_data *data);
int			check_numeric(char **rgb);
void		check_null(char *file, int fd, int error);

////////////////////////utils.c////////////////////////
void		convert_string_to_rgb(t_data *data, char **rgb, char place);
int			d_check_tex(t_data *data, char **pp);
int			ft_strcmp(const char *str1, const char *str2);

/////////////////////debugging.c///////////////////////
void		print_cub_info(t_data *data);
void		print_map(t_data *data, char **map, int size);
void		line_print_map(t_data *data, int size);

///////////////////////frees.c/////////////////////////
int			error_handler_checks(t_data *data, int i);
void		free_exit_checks(t_data *data);
void		free_mlx_checks(t_data *data);

///////////////////////frees2.c/////////////////////////
int			free_exit(t_data *data);
void		free_mlx(t_data *data);

/////////////////////initialize.c//////////////////////
t_data		*initialize_struct(char *path);
void		start_mlx(t_data *data);
void		open_images(t_data *data);
t_info		*initialize_tinfo(char *path);

/////////////////////initialize2.c/////////////////////
void		init_texture_stuff(t_data *data);
void		init_ray_stuff(t_data *structure);
void		init_texture_stuff2(t_data *data);
void		init_ray_stuff2(t_data *structure);
void		open_addr(t_data *data);

/////////////////////check_map.c//////////////////////
void		get_size(t_data *data);
int			check_line(t_data *data, char *line);
void		check_width(t_data *data, char *line);

/////////////////////get_map.c////////////////////////
void		get_map(t_data *data);
void		get_map_array(t_data *data);
void		write_line(t_data *data, char **map, char *line, int j);
void		fill_line(char *array_line, int l, int map_width);

/////////////////////get_map2.c///////////////////////
void		get_map_4_checks(t_data *data);
void		write_line_4_checks(t_data *data, char **map, char *line, int j);

/////////////////////verify_map.c/////////////////////
void		verify_map(t_data	*data);
void		check_characters(char **array, t_data *data);
void		verify_player(t_data *data, char letter, int x, int y);
void		fill_player_dir(t_data *data, char letter);
void		fill_player_dir2(t_data *data, char letter);

/////////////////////check_border.c///////////////////
void		check_borders(t_data *data);
void		flood_fill(char **map, t_data *data, int x, int y);

////////////////////////windows.c/////////////////////
void		start_windows(t_data *data);
void		draw_raycast(t_data *data);
int			game_loop(t_data *data);

///////////////////////rendering.c////////////////////
void		put_ceiling_floor(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_color(t_data *data);

///////////////////////raycaster.c////////////////////
void		ray_calculations(t_data *data);
void		get_step_sidedist(t_data *data);
void		get_hit(t_data *data);
void		get_wall_h(t_data *data);
void		get_tex_wall(t_data *data);

///////////////////////draw_wall.c////////////////////
void		draw_wall(t_data *data, int i);
void		get_tex_x(t_data *data);
int			ft_get_pixel(t_data *data, int x, int y);

///////////////////////ft_key.c///////////////////////
int			ft_press_key(int keysym, t_data *data);
int			ft_release_key(int keysym, t_data *data);

///////////////////////ft_movements.c///////////////////
int			ft_movements(t_data *data);
void		move_vertical(t_data *data, char flag);
void		move_hozintal(t_data *data, char flag);
void		check_wall_hit(t_data *data, double temp_x, double temp_y);
void		rotate_player(t_data *data, char flag);

#endif
