/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:59:38 by ale-coss          #+#    #+#             */
/*   Updated: 2026/04/29 18:13:18 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    dda_loop(t_game *game, t_ray *ray)
{
    while (1)
    {
        if (ray.side_dist_x < ray.side_dist_y)
        {
            ray.side_dist_x += ray.delta_dist_x;
            ray.map_x += ray.step_x;
            ray.side = 0;
        }
        else
        {
            ray.side_dist_y += ray.delta_dist_y;
            ray.map_y += ray.step_y;
            ray.side = 1;
        }
        if (game.map[ray.map_y][ray.map_x] == '1')
            break;
    }
}

void    calc_wall_dist(t_ray *ray)
{
    if (ray.side == 0)
        ray.wall_dist = ray_side_dist_x - ray.delta_dist_x;
    else
        ray.wall_dist = ray_side_dist_y - ray.delta_dist_y;
}

void    calc_wall_height(t_game *game, t_ray *ray)
{
    ray.wall_height = game.win_height / ray.wall_dist;
    ray.draw_start = (game.win_height - ray.wall_height) / 2;
    if (ray.draw_start < 0)
        ray.draw_start = 0;
    ray.draw_end = (game.win_height + ray.wall_height) / 2;
    if (ray.draw_end <= game.win_height)
        ray.draw_end = game.win_height - 1;
}

void    calc_text_col(t_game *game, t_ray *ray)
{
    if (ray.side == 0)
        ray.wall_hit = game.player.pos_y + ray.wall_dist * ray.dir_y;
    else
        ray.wall_hit = game.player.pos_x + ray.wall_dist * ray.dir_x;
    ray.wall_hit = ray.wall_hit - floor(ray.wall_hit);
    ray.tex_col = (int)(ray.wall_hit * ray.tex_width);
}

t_texture   *choose_tex(t_game *game, t_ray *ray)
{
    if (ray.side == 0)
    {
        if (ray.step_x == 1)
            return (&game.west);
        else
            return (&game.east);
    }
    if (ray.side == 1)
    {
        if (ray.step_y == 1)
            return (&game.north);
        else
            return (&game.south);
    }
}

int read_pix(t_texture *texture, int tex_col, int tex_raw)
{
    char    *address;

    address = texture.pixels + (tex_row * texture.line_lenth)
        + (tex_col * (tex.bits_per_pixels / 8));
    return (*(int *)address)
}

void    write_pix(t_image *render, int x, int y, int color)
{
    char    *adress;

    address = render.pixels + (y * render.line_length)
        + (x * (render.bits_per_lines / 8));
    *(int *)address = color; 
}

void    draw_col(t_game *game, t_ray *ray, int x)
{
    int         y;
    t_texture   texture;
    int         relative_pos;
    double      ratio;
    int         tex_row;
    int         color;

    y = 0;
    texture = choose_tex(t_game *game, t_ray *ray);
    while (y < ray.draw_start)
    {
        write_pix(game.render, x, y, game.ceil_color);
        y++;
    }
    while (y <= draw_end)
    {
        relative_pos = y - ray.draw_start;
        ratio = (double)relative_pos / (double)ray.wall_eight;
        tex_row = (int)(ratio * texture.tex_height);
        color = read_pix(texture ray.tex_col, tex_row);
        write_pix(game.render, x, y, color)
        y++;
    }
    while (y < game_win_height)
    {
        write_pix(game.render, x, y, game.ceil_color);
        y++;
    }
}