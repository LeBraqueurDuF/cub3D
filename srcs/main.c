/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:40 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/06 11:27:38 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game  game;

    init_game(&game);
    parse(&game, ac, av);
    init_mlx(&game);
    game.win_width = 1920;
    game.win_height = 1080;
    init_tex(&game);
    init_player_vectors(&game);
    mlx_hook(game.win_ptr, 2, KeyPressMask, (int (*)(void))handle_keypress, &game);
    mlx_hook(game.win_ptr, 3, KeyReleaseMask, (int (*)(void))handle_keyrelease, &game);
    mlx_hook(game.win_ptr, 17, StructureNotifyMask, (int (*)(void))handle_close, &game);
    mlx_loop_hook(game.mlx_ptr, (int (*)(void))render, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}
