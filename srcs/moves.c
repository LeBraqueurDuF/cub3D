/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:28:22 by ale-coss          #+#    #+#             */
/*   Updated: 2026/05/01 16:51:12 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D"

void	move_forward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game.player->pos_x + game.player->dir_x * MOVE_SPEED;
	new_pos_y = game.player->pos_y + game.player->dir_y * MOVE_SPEED;
	if (game->map.grid[ray.map_y][new_pos_x] != '1')  // on verifie x et y separement pour pouvoir glisser le long des murs
		game.player->pos_x = new_pos_x;
	if (game->map.grid[new_pos_y][ray.map_x] != '1')
		game.player->pos_y = new_pos_y;
}

void	move_back(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game.player->pos_x - game.player->dir_x * MOVE_SPEED;
	new_pos_y = game.player->pos_y - game.player->dir_y * MOVE_SPEED;
	if (game->map.grid[ray.map_y][new_pos_x] != '1')  // on verifie x et y separement pour pouvoir glisser le long des murs
		game.player->pos_x = new_pos_x;
	if (game->map.grid[new_pos_y][ray.map_x] != '1')
		game.player->pos_y = new_pos_y;
}

void	move_left(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game.player->pos_x - game.player->dir_x * MOVE_SPEED;
	new_pos_y = game.player->pos_y + game.player->dir_y * MOVE_SPEED;
	if (game->map.grid[ray.map_y][new_pos_x] != '1')  // on verifie x et y separement pour pouvoir glisser le long des murs
		game.player->pos_x = new_pos_x;
	if (game->map.grid[new_pos_y][ray.map_x] != '1')
		game.player->pos_y = new_pos_y;
}

void	move_right(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game.player->pos_x + game.player->dir_x * MOVE_SPEED;
	new_pos_y = game.player->pos_y - game.player->dir_y * MOVE_SPEED;
	if (game->map.grid[ray.map_y][new_pos_x] != '1')  // on verifie x et y separement pour pouvoir glisser le long des murs
		game.player->pos_x = new_pos_x;
	if (game->map.grid[new_pos_y][ray.map_x] != '1')
		game.player->pos_y = new_pos_y;
}

void	rotate_left(t_game *game) // on rotate dir et plan cam du meme angle
{
	double	old_dir_x;
	double	old_plan_x;

	old_dir_x = game.player->dir_x;
	game.player->dir_x = game.player->dir_x * cos(ROT_SPEED) - game.player->dir_y * sin(ROT_SPEED);
	game.palyer->dir_y = old_dir_x * sin(ROT_SPEED) + game.player->dir_y * cos(ROT_SPEED);
	old_plan_x = game.player->plan_x;
	game.player->plan_x = game.player->plan_x * cos(ROT_SPEED) - game.player->plan_y * sin(ROT_SPEED);
	game.palyer->plan_y = old_plan_x * sin(ROT_SPEED) + game.player->plan_y * cos(ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plan_x;

	old_dir_x = game.player->dir_x;
	game.player->dir_x = game.player->dir_x * cos(- ROT_SPEED) - game.player->dir_y * sin(- ROT_SPEED);
	game.palyer->dir_y = old_dir_x * sin(- ROT_SPEED) + game.player->dir_y * cos(- ROT_SPEED);
	old_plan_x = game.player->plan_x;
	game.player->plan_x = game.player->plan_x * cos(- ROT_SPEED) - game.player->plan_y * sin(- ROT_SPEED);
	game.palyer->plan_y = old_plan_x * sin(- ROT_SPEED) + game.player->plan_y * cos(- ROT_SPEED);
}


void	update_palyer(t_game *game)
{
	if (game.player->move_forward == 1)
		move_forward(game);
	if (game.player->move_back == 1)
		move_back(game);
	if (game.player->move_left == 1)
		move_left(game);
	if (game.player->move_right == 1)
		move_right(game);
	if (game.player->rotate_left == 1)
		rotate_left(game);
}