/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:15:21 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/28 15:49:51 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int handle_keypress(int keysym, void *param)
{
    printf("keysym: %d\n", keysym);
    if (keysym == XK_Escape)
        handle_close(param);
    return (0);
}

int handle_close(void *param)
{
    t_game  *game;

    game = (t_game *)param;
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    mlx_destroy_display(game->mlx_ptr);
    exit(0);
}

void    my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
    char    *dst;

    dst = img->pixels + (y * img->line_lenth + x * (img->bits_per_pixels / 8));
    *(unsigned int *)dst = color;
}

void    init_texture(t_texture *tex)
{
    tex->path = NULL;
    tex->img_ptr = NULL;
    tex->pixels = NULL;
    tex->width = 0;
    tex->height = 0;
    tex->bits_per_pixels = 0;
    tex->line_lenth = 0;
    tex->endian = 0;
}

void    init_player(t_player *player)
{
    player->pos_x = 0.0;
    player->pos_y = 0.0;
    player->dir = 0;
    player->dir_X = 0.0;
    player->dir_y = 0.0;
    player->plan_x = 0.0;
    player->plan_y = 0.0;
    player->move_forward = 0;
    player->move_back = 0;
    player->move_left = 0;
    player->move_right = 0;
    player->rotate_left = 0;
    player->rotate_right = 0;
}

void    init_game(t_game *game)
{
    game->mlx_ptr = NULL;
    game->win_ptr = NULL;
    game->win_width = 0;
    game->win_height = 0;
    game->render.img_ptr = NULL;
    game->render.pixels = NULL;
    game->render.bits_per_pixels = 0;
    game->render.line_lenth = 0;
    game->render.endian = 0;
    init_texture(&game->north);
    init_texture(&game->south);
    init_texture(&game->west);
    init_texture(&game->east);
    game->floor_color[0] = -1;
    game->floor_color[1] = -1;
    game->floor_color[2] = -1;
    game->ceil_color[0] = -1;
    game->ceil_color[1] = -1;
    game->ceil_color[2] = -1;
    game->map.grid = NULL;
    game->map.width = 0;
    game->map.height = 0;
    init_player(&game->player);
}
