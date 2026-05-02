/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:58:05 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/02 18:32:25 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    dda_loop(t_game *game, t_ray *ray)
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
			break;
	}
}

void    calc_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void    calc_wall_height(t_game *game, t_ray *ray)
{
	ray->wall_height = game->win_height / ray->wall_dist;
	ray->draw_start = (game->win_height - ray->wall_height) / 2;
	//Martin
	// if (ray->draw_start < 0)
		// ray->draw_start = 0;
	ray->draw_end = (game->win_height + ray->wall_height) / 2;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
}

void    calc_text_col(t_ray *ray, t_texture *texture, t_game *game)
{
	if (ray->side == 0)
		ray->wall_hit = game->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = game->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_hit = ray->wall_hit - floor(ray->wall_hit);
	ray->tex_col = (int)(ray->wall_hit * texture->tex_width);
}

t_texture   *choose_tex(t_game *game, t_ray *ray)
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
}

int read_pix(t_texture *texture, int tex_col, int tex_row) //on lit la couleur dans le tableau de pixel de la texture en calculant son adresse
{
	char    *address;

	address = texture->pixels + (tex_row * texture->line_length)
		+ (tex_col * (texture->bits_per_pixels / 8));
	return (*(int *)address); //*(int *) interprete les 4octets a cette adresse comme un int (c'est la couleur encodee en rgb)
}

void    write_pix(t_image *render, int x, int y, int color) // on ecrit ce pixel dans le render a la position x, y
{
	char    *address;

	address = render->pixels + (y * render->line_length)
		+ (x * (render->bits_per_pixels / 8));
	*(int *)address = color; 
}

int rgb_to_int(int *color)
{
    return (color[0] << 16 | color[1] << 8 | color[2]);
}

void    draw_col(t_game *game, t_ray *ray, int x)
{
	int         y;
	t_texture   *texture;
	int         relative_pos; // combien de pixels parcourus dans la bande
	double      ratio; //dit ou l'on se situe dans la bande
	int         tex_row; // on comprime ou etire la text pour qu'elle remplisse completement la bande
	int         color;

	y = 0;
	texture = choose_tex(game, ray);
	calc_text_col(ray, texture, game);
	while (y < ray->draw_start)
	{
		write_pix(&game->render, x, y, rgb_to_int(game->floor_color));
		y++;
	}
	//Martin
	// if (0 > ray->draw_start)
		// y = -ray->draw_start;
	// while (y <= ray->draw_end)
	while (y <= ray->draw_end && y <= game->win_height)
	{
		relative_pos = y - ray->draw_start;
		ratio = (double)relative_pos / (double)ray->wall_height;
		tex_row = (int)(ratio * texture->tex_height);
		color = read_pix(texture, ray->tex_col, tex_row);
		write_pix(&game->render, x, y, color);
		y++;
	}
	while (y < game->win_height)
	{
		write_pix(&game->render, x, y, rgb_to_int(game->ceil_color));
		y++;
	}
}
