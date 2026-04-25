/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:44 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/25 16:07:41 by sesquier         ###   ########.fr       */
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