/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:59:56 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 17:00:42 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir_vec(t_player *p, double dx, double dy)
{
	p->dir_x = dx;
	p->dir_y = dy;
}

static void	set_plan_vec(t_player *p, double px, double py)
{
	p->plan_x = px;
	p->plan_y = py;
}

void	init_player_vectors(t_game *game)
{
	if (game->player.dir == 'N')
	{
		set_dir_vec(&game->player, 0, -1);
		set_plan_vec(&game->player, 0.66, 0);
	}
	else if (game->player.dir == 'S')
	{
		set_dir_vec(&game->player, 0, 1);
		set_plan_vec(&game->player, -0.66, 0);
	}
	else if (game->player.dir == 'E')
	{
		set_dir_vec(&game->player, 1, 0);
		set_plan_vec(&game->player, 0, 0.66);
	}
	else if (game->player.dir == 'W')
	{
		set_dir_vec(&game->player, -1, 0);
		set_plan_vec(&game->player, 0, -0.66);
	}
}
