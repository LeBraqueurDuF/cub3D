/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:01:02 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/27 16:31:32 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_infos(t_game *game, char *idx, char *infos)
{
	if (ft_strncmp(idx, "NO", 2) == 0)		game.config.no = infos;
	else if (ft_strncmp(idx, "SO", 2) == 0)
		game->config.so = infos;
	else if (ft_strncmp(idx, "WE", 2) == 0)
		game->config.we = infos;
	else if (ft_strncmp(idx, "EA", 2) == 0)
		game->config.ea = infos;
	else
		free(infos);
}

void take_infos(t_game *game, char *line, char *idx)
{
	int		i;
	int		j;
	char	infos[1000];

	i = 0;
	j = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	i += ft_strlen(idx);
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	while (line[i] && !ft_is_whitespace(line[i]))
   		infos[j++] = line[i++];
	infos[j] = '\0';
	put_infos(game, idx, ft_strdup(infos));
}

void	colors_infos(t_game *game, char *idx, char *num, int count)
{
	int	n;

	n = ft_atoi(num);
	if (idx[0] == 'F')
		game->config.floor[count] = n;
	else if (idx[0] == 'C')
		game->config.ceil[count] = n;
}

void	take_numbers(t_game *game, char *line, char *idx)
{
	int		i;
	int		j;
	int		count;
	char	num[100];

	i = 0;
	count = -1;
	while (line[i])
	{
		j = 0;
		while (line[i] && !ft_isprint(line[i]))
			i++;
		if (line[i] && (line[i] == idx[0] || line[i] == ','))
			i++;
		while (line[i] && !ft_isprint(line[i]))
			i++;
		while (line[i] && ft_isdigit(line[i]))
			num[j++] = line[i++];
		num[j] = '\0';
		if (j > 0)
			colors_infos(game, idx, num, ++count);
		num[0] = 0;
	}
	
}

void line_parser(char *line, t_game *game)
{
	if (!line)
		return;
	if (ft_strncmp(line, "NO ", 3) == 0)
		take_infos(game, line, "NO");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		take_infos(game, line, "SO");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		take_infos(game, line, "WE");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		take_infos(game, line, "EA");
	else if (ft_strncmp(line, "F ", 2) == 0)
		take_numbers(game, line, "F");
	else if (ft_strncmp(line, "C ", 2) == 0)
		take_numbers(game, line, "C");
}

void file_name_checker(char *file)
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

void parse(t_game *game, int ac, char **av)
{
	int fd;
	char *line;

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
		free(line);
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