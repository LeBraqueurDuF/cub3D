/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:15:21 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 16:45:43 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keysym == XK_Escape)
		handle_close(param);
	if (keysym == XK_w || keysym == XK_Up)
		game->player.move_forward = 1;
	if (keysym == XK_s || keysym == XK_Down)
		game->player.move_back = 1;
	if (keysym == XK_a)
		game->player.move_left = 1;
	if (keysym == XK_d)
		game->player.move_right = 1;
	if (keysym == XK_Left)
		game->player.rotate_left = 1;
	if (keysym == XK_Right)
		game->player.rotate_right = 1;
	return (0);
}

int	handle_keyrelease(int keysym, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keysym == XK_w || keysym == XK_Up)
		game->player.move_forward = 0;
	if (keysym == XK_s || keysym == XK_Down)
		game->player.move_back = 0;
	if (keysym == XK_a)
		game->player.move_left = 0;
	if (keysym == XK_d)
		game->player.move_right = 0;
	if (keysym == XK_Left)
		game->player.rotate_left = 0;
	if (keysym == XK_Right)
		game->player.rotate_right = 0;
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->render.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->render.img_ptr);
	if (game->north.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->north.img_ptr);
	if (game->south.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->south.img_ptr);
	if (game->west.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->west.img_ptr);
	if (game->east.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->east.img_ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_game(game);
	exit(0);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line_length + x * (img->bits_per_pixels / 8));
	*(unsigned int *)dst = color;
}

void	init_texture(t_texture *tex)
{
	tex->path = NULL;
	tex->img_ptr = NULL;
	tex->pixels = NULL;
	tex->tex_width = 0;
	tex->tex_height = 0;
	tex->bits_per_pixels = 0;
	tex->line_length = 0;
	tex->endian = 0;
}
