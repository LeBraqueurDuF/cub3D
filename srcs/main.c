/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:40 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/29 18:53:56 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game  game;

    init_game(&game);
    // printf("After init: height=%d width=%d\n", game.map.height, game.map.width);
	parse(&game, ac, av);
    game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
        return (1);
    game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "cub3D");
    game.render.img_ptr = mlx_new_image(game.mlx_ptr, 1920, 1080);
    game.render.pixels = mlx_get_data_addr(game.render.img_ptr,
        &game.render.bits_per_pixels,
        &game.render.line_lenth,
        &game.render.endian);
    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.render.img_ptr, 0, 0);
    mlx_hook(game.win_ptr, 2, KeyPressMask, (int (*)(void))handle_keypress, &game);
    mlx_hook(game.win_ptr, 17, StructureNotifyMask, (int (*)(void))handle_close, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}
