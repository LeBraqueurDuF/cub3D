/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:58:46 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 11:36:47 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void   init_ray(t_game *game, t_ray *ray, int x)
// {
//     ray->camera_x = 2.0 * x / game->win_width - 1.0;
//     ray->dir_x = game->player.dir_x + game->player.plan_x * ray->camera_x;
//     ray->dir_y = game->player.dir_y + game->player.plan_y * ray->camera_x;
//     ray->map_x = (int)game->player.pos_x;
//     ray->map_y = (int)game->player.pos_y;
//     if (ray->dir_x == 0)
//         ray->delta_dist_x = 1e30;
//     else
//         ray->delta_dist_x = fabs(1 / ray->dir_x); //fabs = fonction valeur absolue pour doubles
//     if (ray->dir_y == 0)
//         ray->delta_dist_y = 1e30;
//     else
//         ray->delta_dist_y = fabs(1 / ray->dir_y);
//     if (ray->dir_x > 0)
//     {
//         ray->step_x = 1;
//         ray->side_dist_x = (ray->map_x + 1 - game->player.pos_x) * ray->delta_dist_x;
//     }
//     else
//     {
//         ray->step_x = -1;
//         ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_dist_x;
//     }
//     if (ray->dir_y > 0)
//     {
//         ray->step_y = 1;
//         ray->side_dist_y = (ray->map_y + 1 - game->player.pos_y) * ray->delta_dist_y;
//     }
//     else
//     {
//         ray->step_y = -1;
//         ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_dist_y;
//     }
// }

static void	init_ray_x(t_game *game, t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x > 0)
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
}

static void	init_ray_y(t_game *game, t_ray *ray)
{
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	if (ray->dir_y > 0)
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - game->player.pos_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / game->win_width - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plan_x * ray->camera_x;
	ray->dir_y = game->player.dir_y + game->player.plan_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	init_ray_x(game, ray);
	init_ray_y(game, ray);
}
