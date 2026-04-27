/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:01:06 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/27 21:46:01 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    err_incorrect_file(char *file)
{
    ft_putstr_fd("Error: cannot open file: ", 2);
    ft_putendl_fd(file, 2);
    exit(EXIT_FAILURE);
}

void    debug_game(t_game *game)
{
    printf("--- CONFIG ---\n");
    printf("NO: %s\n", game->north.path);
    printf("SO: %s\n", game->south.path);
    printf("WE: %s\n", game->west.path);
    printf("EA: %s\n", game->east.path);
    printf("Floor: %d %d %d\n", game->floor_color[0], game->floor_color[1], game->floor_color[2]);
    printf("Ceil:  %d %d %d\n", game->ceil_color[0], game->ceil_color[1], game->ceil_color[2]);
}
