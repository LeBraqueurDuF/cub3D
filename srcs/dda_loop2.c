/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:42:14 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 11:48:57 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_pix(t_texture *texture, int tex_col, int tex_row)
{
	char	*address;

	address = texture->pixels + (tex_row * texture->line_length)
		+ (tex_col * (texture->bits_per_pixels / 8));
	return (*(int *)address);
}

void	write_pix(t_image *render, int x, int y, int color)
{
	char	*address;

	address = render->pixels + (y * render->line_length)
		+ (x * (render->bits_per_pixels / 8));
	*(int *)address = color;
}

int	rgb_to_int(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}
