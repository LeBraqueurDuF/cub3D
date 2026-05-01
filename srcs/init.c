/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:15:21 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/01 14:57:32 by ale-coss         ###   ########.fr       */
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

int     init_mlx(t_game *game)
{
        game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
        return (1);
    game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "cub3D");
    game.render.img_ptr = mlx_new_image(game.mlx_ptr, 1920, 1080);
    game.render.pixels = mlx_get_data_addr(game.render.img_ptr,
        &game.render.bits_per_pixels,
        &game.render.line_lenth,
        &game.render.endian);
    return (0);
}

int    init_north(t_game *game)
{
    game->north.img_ptr = mlx_xpm_file_to_image(mlx_ptr, game->north.path,
        &game->north.tex_width, &game->north.tex_height);
    if (!game->img_ptr)
        return (1);
    game->north.pixels = mlx_get_data_addr(game->north.img_ptr, 
		&game->north.bits_per_pixels, &game->north.line_lenth,
		&game->north.endian);
	return (0);
}

int    init_south(t_game *game)
{
    game->south.img_ptr = mlx_xpm_file_to_image(mlx_ptr, game->south.path,
        &game->south.tex_width, &game->south.tex_height);
    if (!game->img_ptr)
        return (1);
    game->south.pixels = mlx_get_data_addr(game->south.img_ptr, 
		&game->south.bits_per_pixels, &game->south.line_lenth,
		&game->south.endian);
	return (0);
}

int    init_west(t_game *game)
{
    game->west.img_ptr = mlx_xpm_file_to_image(mlx_ptr, game->west.path,
        &game->west.tex_width, &game->west.tex_height);
    if (!game->img_ptr)
        return (1);
    game->west.pixels = mlx_get_data_addr(game->west.img_ptr, 
		&game->west.bits_per_pixels, &game->west.line_lenth,
		&game->west.endian);
	return (0);
}

int    init_east(t_game *game)
{
    game->east.img_ptr = mlx_xpm_file_to_image(mlx_ptr, game->east.path,
        &game->east.tex_width, &game->east.tex_height);
    if (!game->img_ptr)
        return (1);
    game->east.pixels = mlx_get_data_addr(game->east.img_ptr, 
		&game->east.bits_per_pixels, &game->east.line_lenth,
		&game->east.endian);
	return (0);
}

void	init_tex(t_game *game)
{
	init_north(game);
	init_south(game);
	init_west(game);
	init_east(game);
}