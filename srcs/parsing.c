/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:01:02 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/25 19:57:01 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	put_infos(t_game *game, char *line, char *idx)
{
		
}

void    line_parser(char *line, t_game *game)
{
    if (!line)
        return ;
    if (ft_strncmp(line, "NO ", 3) == 0)
        put_infos(game, line, "NO");
    else if (ft_strncmp(line, "SO ", 3) == 0)
        put_infos(game, line, "SO");
    else if (ft_strncmp(line, "WE ", 3) == 0)
        put_infos(game, line, "WE");
    else if (ft_strncmp(line, "EA ", 3) == 0)
        put_infos(game, line, "EA");
    else if (ft_strncmp(line, "F ", 2) == 0)
        put_infos(game, line, "F");
    else if (ft_strncmp(line, "C ", 2) == 0)
        put_infos(game, line, "C");
}

void    file_name_checker(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (i < 4 || ft_strncmp(&file[i - 4], ".cub", 4) != 0)
    {
        ft_putendl_fd("Error: usage is <config_file.cub>", 2);
        exit(EXIT_FAILURE);
    }
}

void    parse(t_game *game, int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
	{
		ft_putendl_fd("Error: usage is <config_file.cub>", 2);
		exit(EXIT_FAILURE);
	}
	file_name_checker(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_incorrect_file(av[1]); // todo
	line = get_next_line(fd);
	while (line)
	{
		line_parser(line, game); // todo
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
}

/*
game.config.no      → "./textures/north.xpm"
game.config.so      → "./textures/south.xpm"
game.config.we      → "./textures/west.xpm"
game.config.ea      → "./textures/east.xpm"
game.config.floor   → {220, 100, 0}
game.config.ceil    → {135, 206, 235}

game.map.grid       → tableau 2D de la carte
game.map.rows       → 9
game.map.cols       → 15

game.player.x       → 3.5  (colonne du joueur + 0.5 pour le centrer)
game.player.y       → 2.5  (ligne du joueur + 0.5)
game.player.dir     → 'N'
*/