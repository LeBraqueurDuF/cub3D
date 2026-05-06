/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:01:06 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/29 18:27:09 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    err_incorrect_file(char *file)
{
    ft_putstr_fd("Error: cannot open file: ", 2);
    ft_putendl_fd(file, 2);
    exit(EXIT_FAILURE);
}

// void    debug_game(t_game *game)
// {
//     printf("--- CONFIG ---\n");
//     printf("NO: %s\n", game->north.path);
//     printf("SO: %s\n", game->south.path);
//     printf("WE: %s\n", game->west.path);
//     printf("EA: %s\n", game->east.path);
//     printf("Floor: %d %d %d\n", game->floor_color[0], game->floor_color[1], game->floor_color[2]);
//     printf("Ceil:  %d %d %d\n", game->ceil_color[0], game->ceil_color[1], game->ceil_color[2]);
// }

void    debug_game(t_game *game)
{
    int i;

    printf("\n========== DEBUG GAME ==========\n");
    printf("--- TEXTURES ---\n");
    printf("NO: %s\n", game->north.path ? game->north.path : "NULL");
    printf("SO: %s\n", game->south.path ? game->south.path : "NULL");
    printf("WE: %s\n", game->west.path ? game->west.path : "NULL");
    printf("EA: %s\n", game->east.path ? game->east.path : "NULL");
    printf("--- COLORS ---\n");
    printf("Floor: %d %d %d\n",
        game->floor_color[0], game->floor_color[1], game->floor_color[2]);
    printf("Ceil:  %d %d %d\n",
        game->ceil_color[0], game->ceil_color[1], game->ceil_color[2]);
    printf("--- PLAYER ---\n");
    printf("Direction: %c\n", game->player.dir ? game->player.dir : '?');
    printf("Pos: (%.2f, %.2f)\n", game->player.pos_x, game->player.pos_y);
    printf("--- MAP ---\n");
    printf("Width:  %d\n", game->map.width);
    printf("Height: %d\n", game->map.height);
    printf("Grid:\n");
    i = 0;
    while (i < game->map.height)
    {
        printf("  [%02d] |%s|\n", i, game->map.grid[i]);
        i++;
    }
    printf("================================\n\n");
}