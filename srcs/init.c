/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:15:21 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/25 15:15:26 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int handle_close(void *param)
{
    t_game  *game;

    game = (t_game *)param;
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    exit(0);
}

int handle_keypress(int keysym, void *param)
{
    printf("keysym: %d\n", keysym);
    if (keysym == XK_Escape)
        handle_close(param);
    return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
