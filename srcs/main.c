/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:40 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/01 17:40:53 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game  game;

    init_game(&game);
    // printf("After init: height=%d width=%d\n", game.map.height, game.map.width);
	parse(&game, ac, av);
    init_mlx(game);
    init_tex(game);
    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.render.img_ptr, 0, 0);
    mlx_hook(game.win_ptr, 2, KeyPressMask, (int (*)(void))handle_keypress, &game);
    mlx_hook(game.win_ptr, 2, KeyReleaseMask, (int (*)(void))handle_keyrelease, &game);
    mlx_hook(game.win_ptr, 17, StructureNotifyMask, (int (*)(void))handle_close, &game);
    mlx_loop_hook(game.mlx_ptr, (int (*)(void))render, &game)
    mlx_loop(game.mlx_ptr);
    return (0);
}
