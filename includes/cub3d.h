/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:44 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/27 21:46:13 by sesquier         ###   ########.fr       */
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

/*

// Ancienne version des structures

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_map
{
    char    **grid;       // la carte en 2D (tableau de strings)
    int     rows;         // nombre de lignes
    int     cols;         // largeur max
}   t_map;

typedef struct s_player
{
    double  x;            // position X dans la carte
    double  y;            // position Y dans la carte
    char    dir;          // direction initiale : N S E W
}   t_player;

typedef struct s_config
{
    char    *no;          // chemins vers les textures
    char    *so;
    char    *we;
    char    *ea;
    int     floor[3];     // RGB sol
    int     ceil[3];      // RGB plafond
}   t_config;

typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_data      img;
    t_map       map;
    t_player    player;
    t_config    config;
}   t_game;

#endif

*/

// nouvelle version :

typedef struct s_image  // remplace s_data
{
    void    *img_ptr;
    char    *pixels;
    int     bits_per_pixels;
    int     line_lenth;
    int     endian;
} t_image;

typedef struct s_map
{
    char    **grid;
    int     width; // largeur
    int     height; // hauteur  
} t_map;

typedef struct s_texture    // remplace s_config
{
    char    *path; //chemin vers la texture
    void    *img_ptr;
    char    *pixels;
    int     width;
    int     height;
    int     bits_per_pixels;
    int     line_lenth;
    int     endian;
} t_texture;

typedef struct s_player
{
    double  pos_x;  // position X dans la carte
    double  pos_y;  // position Y dans la carte
    char    dir;    // direction initiale : N S E W
    double  dir_X;  // coord X vecteur dir
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


void    put_infos(t_game *game, char *idx, char *infos);
void    take_infos(t_game *game, char *line, char *idx);
void    colors_infos(t_game *game, char *idx, char *num, int count);
void    take_numbers(t_game *game, char *line, char *idx);
void    line_parser(char *line, t_game *game);
void    file_name_checker(char *file);
void    parse(t_game *game, int ac, char **av);

int     handle_close(void *param);
int     handle_keypress(int keysym, void *param);
void    my_mlx_pixel_put(t_image *img, int x, int y, int color);

void    err_incorrect_file(char *file);

void    debug_game(t_game *game);

#endif