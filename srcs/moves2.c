/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:03:25 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/13 17:44:17 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(t_game *game, double x, double y)
{
	if (game->map.grid[(int)(y + PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] ==
		'1')
		return (0);
	if (game->map.grid[(int)(y - PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] ==
		'1')
		return (0);
	if (game->map.grid[(int)(y + PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] ==
		'1')
		return (0);
	if (game->map.grid[(int)(y - PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] ==
		'1')
		return (0);
	return (1);
}

void	move_forward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x
		+ game->player.dir_x * speed;
	new_pos_y = game->player.pos_y
		+ game->player.dir_y * speed;
	next_x = game->player.pos_x;
	next_y = game->player.pos_y;
	if (is_walkable(game, new_pos_x, game->player.pos_y))
		next_x = new_pos_x;
	if (is_walkable(game, next_x, new_pos_y))
		next_y = new_pos_y;
	game->player.pos_x = next_x;
	game->player.pos_y = next_y;
}

void	move_back(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x
		- game->player.dir_x * speed;
	new_pos_y = game->player.pos_y
		- game->player.dir_y * speed;
	next_x = game->player.pos_x;
	next_y = game->player.pos_y;
	if (is_walkable(game, new_pos_x, game->player.pos_y))
		next_x = new_pos_x;
	if (is_walkable(game, next_x, new_pos_y))
		next_y = new_pos_y;
	game->player.pos_x = next_x;
	game->player.pos_y = next_y;
}

void	move_right(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x
		- game->player.dir_y * speed;
	new_pos_y = game->player.pos_y
		+ game->player.dir_x * speed;
	next_x = game->player.pos_x;
	next_y = game->player.pos_y;
	if (is_walkable(game, new_pos_x, game->player.pos_y))
		next_x = new_pos_x;
	if (is_walkable(game, next_x, new_pos_y))
		next_y = new_pos_y;
	game->player.pos_x = next_x;
	game->player.pos_y = next_y;
}

void	move_left(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;
	double	speed;
	double	next_x;
	double	next_y;

	speed = MOVE_SPEED * game->delta_time;
	new_pos_x = game->player.pos_x
		+ game->player.dir_y * speed;
	new_pos_y = game->player.pos_y
		- game->player.dir_x * speed;
	next_x = game->player.pos_x;
	next_y = game->player.pos_y;
	if (is_walkable(game, new_pos_x, game->player.pos_y))
		next_x = new_pos_x;
	if (is_walkable(game, next_x, new_pos_y))
		next_y = new_pos_y;
	game->player.pos_x = next_x;
	game->player.pos_y = next_y;
}
