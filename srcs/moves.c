/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:20:52 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 15:37:49 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    move_forward(t_game *game)
// {
//     double  new_pos_x;
//     double  new_pos_y;

//     new_pos_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
//     new_pos_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
//     if (game->map.grid[(int)game->player.pos_y][(int)new_pos_x] != '1')
//         game->player.pos_x = new_pos_x;
//     if (game->map.grid[(int)new_pos_y][(int)game->player.pos_x] != '1')
//         game->player.pos_y = new_pos_y;
// }

void    move_forward(t_game *game)
{
    double  new_pos_x;
    double  new_pos_y;
    double speed;
    
    speed = MOVE_SPEED * game->delta_time;
    new_pos_x = game->player.pos_x + game->player.dir_x * speed;
    new_pos_y = game->player.pos_y + game->player.dir_y * speed;
    if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x + game->player.dir_x * WALL_MARGIN)] != '1')
        game->player.pos_x = new_pos_x;
    if (game->map.grid[(int)(new_pos_y + game->player.dir_y * WALL_MARGIN)][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
}

void    move_back(t_game *game)
{
    double  new_pos_x;
    double  new_pos_y;
    double speed;
    
    speed = MOVE_SPEED * game->delta_time;
    new_pos_x = game->player.pos_x - game->player.dir_x * speed;
    new_pos_y = game->player.pos_y - game->player.dir_y * speed;
    if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x - game->player.dir_x * WALL_MARGIN)] != '1')
        game->player.pos_x = new_pos_x;
    if (game->map.grid[(int)(new_pos_y - game->player.dir_y * WALL_MARGIN)][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
}

void    move_right(t_game *game)
{
    double  new_pos_x;
    double  new_pos_y;
    double  margin_x;
    double  margin_y;
    double speed;
    
    speed = MOVE_SPEED * game->delta_time;
    margin_x = game->player.dir_y * WALL_MARGIN;
    margin_y = game->player.dir_x * WALL_MARGIN;
    new_pos_x = game->player.pos_x - game->player.dir_y * speed;
    new_pos_y = game->player.pos_y + game->player.dir_x * speed;
    if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x + margin_x)] != '1')
        game->player.pos_x = new_pos_x;
    if (game->map.grid[(int)(new_pos_y + margin_y)][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
}

void    move_left(t_game *game)
{
    double  new_pos_x;
    double  new_pos_y;
    double  margin_x;
    double  margin_y;
    double speed;
    
    speed = MOVE_SPEED * game->delta_time;
    margin_x = game->player.dir_y * WALL_MARGIN;
    margin_y = game->player.dir_x * WALL_MARGIN;
    new_pos_x = game->player.pos_x + game->player.dir_y * speed;
    new_pos_y = game->player.pos_y - game->player.dir_x * speed;
    if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x + margin_x)] != '1')
        game->player.pos_x = new_pos_x;
    if (game->map.grid[(int)(new_pos_y + margin_y)][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
}

void    rotate_right(t_game *game)
{
    double  old_dir_x;
    double  old_plan_x;
    double  angle;

    angle = ROT_SPEED * game->delta_time;
    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
    game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
    old_plan_x = game->player.plan_x;
    game->player.plan_x = game->player.plan_x * cos(angle) - game->player.plan_y * sin(angle);
    game->player.plan_y = old_plan_x * sin(angle) + game->player.plan_y * cos(angle);
}

void    rotate_left(t_game *game)
{
    double  old_dir_x;
    double  old_plan_x;
    double  angle;

    angle = ROT_SPEED * game->delta_time;
    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(-angle) - game->player.dir_y * sin(-angle);
    game->player.dir_y = old_dir_x * sin(-angle) + game->player.dir_y * cos(-angle);
    old_plan_x = game->player.plan_x;
    game->player.plan_x = game->player.plan_x * cos(-angle) - game->player.plan_y * sin(-angle);
    game->player.plan_y = old_plan_x * sin(-angle) + game->player.plan_y * cos(-angle);
}

void    update_player(t_game *game, t_ray *ray)
{
    if (game->player.move_forward == 1)
        move_forward(game);
    if (game->player.move_back == 1)
        move_back(game);
    if (game->player.move_left == 1)
        move_left(game);
    if (game->player.move_right == 1)
        move_right(game);
    if (game->player.rotate_left == 1)
        rotate_left(game);
    if (game->player.rotate_right == 1)
        rotate_right(game);
}
