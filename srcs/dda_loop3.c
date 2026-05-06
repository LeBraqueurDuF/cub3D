/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:43:25 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 15:20:21 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    draw_col(t_game *game, t_ray *ray, int x)
// {
//     int         y;
//     t_texture   *texture;
//     int         relative_pos; // combien de pixels parcourus dans la bande
//     double      ratio; //dit ou l'on se situe dans la bande
//     int         tex_row; // on comprime ou etire la text pour qu'elle rempli
//     int         color;

//     y = 0;
// 	texture = choose_tex(game, ray);
// 	if (!texture || !texture->pixels)
//     	return ;
//     calc_text_col(ray, texture, game);
//     while (y < ray->draw_start)
//     {
//         write_pix(&game->render, x, y, rgb_to_int(game->floor_color));
//         y++;
//     }
//     while (y <= ray->draw_end && y <= game->win_height)
//     {
//         relative_pos = y - ray->draw_start;
//         ratio = (double)relative_pos / (double)ray->wall_height;
//         tex_row = (int)(ratio * texture->tex_height);
//         if (tex_row >= texture->tex_height)
//             tex_row = texture->tex_height;
//         color = read_pix(texture, ray->tex_col, tex_row);
//         write_pix(&game->render, x, y, color);
//         y++;
//     }
//     while (y < game->win_height)
//     {
//         write_pix(&game->render, x, y, rgb_to_int(game->ceil_color));
//         y++;
//     }
// }

static void	draw_ceiling(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		write_pix(&game->render, x, y, rgb_to_int(game->ceil_color));
		y++;
	}
}

static void	draw_wall(t_game *game, t_ray *ray, t_texture *tex, int x)
{
	int		y;
	int		relative_pos;
	double	ratio;
	int		tex_row;

	if (ray->draw_start < 0)
		y = 0;
	else
		y = ray->draw_start;
	while (y <= ray->draw_end && y < game->win_height)
	{
		relative_pos = y - ray->draw_start;
		ratio = (double)relative_pos / (double)ray->wall_height;
		tex_row = (int)(ratio * tex->tex_height);
		if (tex_row >= tex->tex_height)
			tex_row = tex->tex_height - 1;
		write_pix(&game->render, x, y, read_pix(tex, ray->tex_col, tex_row));
		y++;
	}
	while (y < game->win_height)
	{
		write_pix(&game->render, x, y, rgb_to_int(game->floor_color));
		y++;
	}
}

void	draw_col(t_game *game, t_ray *ray, int x)
{
	t_texture	*texture;

	texture = choose_tex(game, ray);
	if (!texture || !texture->pixels)
		return ;
	calc_text_col(ray, texture, game);
	draw_ceiling(game, ray, x);
	draw_wall(game, ray, texture, x);
}
