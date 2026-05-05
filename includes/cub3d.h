/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:44 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/05 22:07:53 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../LIBFT/libft.h"

# define WIDTH	2560
# define HEIGHT	1440
# define MOVE_SPEED 0.00001
# define ROT_SPEED 0.00001

typedef struct s_image
{
	void    *img_ptr;
	char    *pixels;
	int     bits_per_pixels;
	int     line_length;
	int     endian;
} t_image;

typedef struct s_map
{
	char    **grid;
	int     width; // largeur
	int     height; // hauteur  
} t_map;

typedef struct s_texture
{
	char    *path;
	void    *img_ptr;
	char    *pixels;
	int     tex_width;
	int     tex_height;
	int     bits_per_pixels;
	int     line_length;
	int     endian;
} t_texture;

typedef struct s_player
{
	double  pos_x;  // position X dans la carte
	double  pos_y;  // position Y dans la carte
	char    dir;    // direction initiale : N S E W
	double  dir_x;  // coord X vecteur dir
	double  dir_y;  // coord Y vecteur dir
	double  plan_x; // coord X plan camera
	double  plan_y; // coord Y plan camera
	int     move_forward; 
	int     move_back;
	int     move_left;
	int     move_right;
	int     rotate_left;
	int     rotate_right;
} t_player;

typedef struct s_ray
{
	double  camera_x; //pos sur le plan camera
	double  dir_x;
	double  dir_y;
	int     map_x; // case actuelle dans x
	int     map_y; // case actuelle dans y
	double  delta_dist_x; // distance entre 2 lignes verticales
	double  delta_dist_y; //distance entre 2 lignes horizontales
	double  side_dist_x;  //distance reelle a parcourir avant prochaine ligne verticale
	double  side_dist_y;  // distance reelle a parcourir avant prochaine ligne horizontale
	int     step_x; // direction de deplacement x (-1 = gauche ou 1 = droite);
	int     step_y; // direction de deplacement y (-1 vers le haut ou 1 vers le bas)
	int     side; // 0 mur vertical touche, 1 mur horizontal touche
	double  wall_dist; //distance finale au mur
	int     wall_height; //hauteur de la bande a dessiner
    double  wall_hit;
    int     tex_col;
    int     draw_start;
    int     draw_end;
} t_ray;

typedef struct s_game
{
	void        *mlx_ptr;
	void        *win_ptr;
	int         win_width;
	int         win_height;
	t_image     render;
	t_texture   north;
	t_texture   south;
	t_texture   west;
	t_texture   east;
	int         floor_color[3]; // modifie en 3 pour RGB
	int         ceil_color[3]; //modifie en 3 pour RGB
	t_map       map;
	t_player    player;
} t_game;

// Parsing
void	parse(t_game *game, int ac, char **av);
void	file_name_checker(char *file);
void	parse_pass1(t_game *game, char *file);
void	parse_pass2(t_game *game, char *file);
bool	is_map_line(char *line);
void    line_parser(char *line, t_game *game);
void    put_infos(t_game *game, char *idx, char *infos);
void    take_infos(t_game *game, char *line, char *idx);
void    check_config_complete(t_game *game);
void    check_player(t_game *game);
void    alloc_map(t_game *game);
void    check_map_closed(t_game *game);
void    colors_infos(t_game *game, char *idx, char *num, int count);
void    take_numbers(t_game *game, char *line, char *idx);
// void    file_name_checker(char *file);
// void    parse(t_game *game, int ac, char **av);

// Init
int     handle_close(void *param);
int     handle_keypress(int keysym, void *param);
int		handle_keyrelease(int keysym, void *param);
void    my_mlx_pixel_put(t_image *img, int x, int y, int color);
void    init_texture(t_texture *tex);
void    init_player(t_player *player);
void    init_game(t_game *game);
int     init_mlx(t_game *game);
int    init_north(t_game *game);
int    init_south(t_game *game);
int    init_west(t_game *game);
int    init_east(t_game *game);
void	init_tex(t_game *game);
void    init_player_vectors(t_game *game);

// DDA
void   init_ray(t_game *game, t_ray *ray, int x);
void    dda_loop(t_game *game, t_ray *ray);
void    calc_wall_dist(t_ray *ray);
void    calc_wall_height(t_game *game, t_ray *ray);
void    calc_text_col(t_ray *ray, t_texture *texture, t_game *game);
t_texture   *choose_tex(t_game *game, t_ray *ray);
int read_pix(t_texture *texture, int tex_col, int tex_row);
void    write_pix(t_image *render, int x, int y, int color);
void    draw_col(t_game *game, t_ray *ray, int x);
int rgb_to_int(int *color);

// Render
void    cast_ray(t_game *game, t_ray *ray, int x);
int render(void *param);

void	move_forward(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	update_player(t_game *game, t_ray *ray);

// Errors & debug
void    err_incorrect_file(char *file);
void    free_game(t_game *game);
void    debug_game(t_game *game);

#endif