/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:03:25 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 17:10:15 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x + game->player.dir_x * speed;
	new_pos_y = game->player.pos_y + game->player.dir_y * speed;
	if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x
		+ game->player.dir_x * WALL_MARGIN)] != '1')
		game->player.pos_x = new_pos_x;
	if (game->map.grid[(int)(new_pos_y + game->player.dir_y
			* WALL_MARGIN)][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_pos_y;
}

void	move_back(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x - game->player.dir_x * speed;
	new_pos_y = game->player.pos_y - game->player.dir_y * speed;
	if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x
		- game->player.dir_x * WALL_MARGIN)] != '1')
		game->player.pos_x = new_pos_x;
	if (game->map.grid[(int)(new_pos_y - game->player.dir_y
			* WALL_MARGIN)][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_pos_y;
}

void	move_right(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	margin_x;
	double	margin_y;
	double	speed;

	speed = MOVE_SPEED * game->delta_time;
	margin_x = game->player.dir_y * WALL_MARGIN;
	margin_y = game->player.dir_x * WALL_MARGIN;
	new_pos_x = game->player.pos_x - game->player.dir_y * speed;
	new_pos_y = game->player.pos_y + game->player.dir_x * speed;
	if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x
		+ margin_x)] != '1')
		game->player.pos_x = new_pos_x;
	if (game->map.grid[(int)(new_pos_y
			+ margin_y)][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_pos_y;
}

void	move_left(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	margin_x;
	double	margin_y;
	double	speed;

	speed = MOVE_SPEED * game->delta_time;
	margin_x = game->player.dir_y * WALL_MARGIN;
	margin_y = game->player.dir_x * WALL_MARGIN;
	new_pos_x = game->player.pos_x + game->player.dir_y * speed;
	new_pos_y = game->player.pos_y - game->player.dir_x * speed;
	if (game->map.grid[(int)game->player.pos_y][(int)(new_pos_x
		+ margin_x)] != '1')
		game->player.pos_x = new_pos_x;
	if (game->map.grid[(int)(new_pos_y
			+ margin_y)][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_pos_y;
}
