/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:26:40 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/25 19:34:13 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game  game;
	// int	 	return_value;

	// return_value = parse(&game, ac, av);
	parse(&game, ac, av);
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);
    game.win = mlx_new_window(game.mlx, 1920, 1080, "cub3D");
    game.img.img = mlx_new_image(game.mlx, 1920, 1080);
    game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel,
                        &game.img.line_length, &game.img.endian);
    my_mlx_pixel_put(&game.img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	mlx_hook(game.win, 2, KeyPressMask, (int (*)(void))handle_keypress, &game);
	mlx_hook(game.win, 17, StructureNotifyMask, (int (*)(void))handle_close, &game);
    mlx_loop(game.mlx);
    return (0);
}
