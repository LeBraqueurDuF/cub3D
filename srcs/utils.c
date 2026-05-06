/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:27:25 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 18:08:08 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_current_time(void)
{
	double			current;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec + current_time.tv_usec / 1000000.0;
	return (current);
}

void	set_delta_time(t_game *game, double current)
{
	game->delta_time = current - game->last_time;
	if (game->delta_time > 0.1)
		game->delta_time = 0.1;
	game->last_time = current;
}
