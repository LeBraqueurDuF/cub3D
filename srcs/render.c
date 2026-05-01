/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:29:15 by ale-coss          #+#    #+#             */
/*   Updated: 2026/05/01 17:37:44 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    cast_ray(t_game *game, t_ray *ray, int x)
{
    init_ray(game, ray, x);
    dda_loop(game, ray);
    calc_wall_dist(ray);
    calc_wall_height(game,ray);
    draw_col(game, ray, x);
}

int render(void *param)
{
    int     x;
    t_ray   ray;
    t_game  *game;

    x = 0;
    game = (t_game *)param;
    while (x < game->win_width)
    {
        update_palyer(game);
        cast_ray(game, &ray, x);
        x++;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
        game->render.img_ptr, 0, 0);
    return(0)
}