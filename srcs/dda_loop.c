/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:58:05 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 15:42:06 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_loop(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

void	calc_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	calc_wall_height(t_game *game, t_ray *ray)
{
	ray->wall_height = game->win_height / ray->wall_dist;
	ray->draw_start = (game->win_height - ray->wall_height) / 2;
	ray->draw_end = (game->win_height + ray->wall_height) / 2;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
}

void	calc_text_col(t_ray *ray, t_texture *texture, t_game *game)
{
	if (ray->side == 0)
		ray->wall_hit = game->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = game->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_hit = ray->wall_hit - floor(ray->wall_hit);
	ray->tex_col = (int)(ray->wall_hit * texture->tex_width);
	if (ray->tex_col >= texture->tex_width)
		ray->tex_col = texture->tex_width - 1;
}

t_texture	*choose_tex(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x == 1)
			return (&game->west);
		else
			return (&game->east);
	}
	if (ray->side == 1)
	{
		if (ray->step_y == 1)
			return (&game->north);
		else
			return (&game->south);
	}
	return (NULL);
}
