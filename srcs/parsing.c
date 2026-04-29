/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:01:02 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/29 18:34:29 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_infos(t_game *game, char *idx, char *infos)
{
    if (ft_strncmp(idx, "NO", 2) == 0)
        game->north.path = infos;
    else if (ft_strncmp(idx, "SO", 2) == 0)
        game->south.path = infos;
    else if (ft_strncmp(idx, "WE", 2) == 0)
        game->west.path = infos;
    else if (ft_strncmp(idx, "EA", 2) == 0)
        game->east.path = infos;
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
	while (line[i] && !ft_iswhitespace(line[i]))
   		infos[j++] = line[i++];
	infos[j] = '\0';
	put_infos(game, idx, ft_strdup(infos));
}

void    colors_infos(t_game *game, char *idx, char *num, int count)
{
    int n;

    n = ft_atoi(num);
    if (idx[0] == 'F')
        game->floor_color[count] = n;
    else if (idx[0] == 'C')
        game->ceil_color[count] = n;
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
		else
			i++;
		num[0] = 0;
	}
}

void	take_map(t_game *game, char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	game->map.height += 1;
	while (line)
}

bool is_map_line(char *line)
{
    int i;
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        if (!ft_strchr("01NSEW ", line[i]))
            return (false);
        i++;
    }
    return (i > 0);  // ligne non vide
}

void line_parser(char *line, t_game *game)
{
	bool	map_line;

	map_line = false;
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
	else if ((map_line = is_map_line(line)) == true)
		take_map(game, line);		
}

void    file_name_checker(char *file)
{
    int     i;
    int     dot_count;
    int     dot_pos;

    i = 0;
    dot_count = 0;
    dot_pos = -1;
    while (file[i])
    {
        if (file[i] == '.')
        {
            dot_count++;
            dot_pos = i;
        }
        i++;
    }
    if (dot_count != 1 || ft_strncmp(&file[dot_pos], ".cub", 4) != 0
        || file[dot_pos + 4] != '\0')
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
	parse_pass1(game, av[1]);
	check_config(game);
	check_player(game);
	alloc_map(game);
	parse_pass2(game, av[1]);
	check_map_closed(game);
	debug_game(game);
}

// void parse(t_game *game, int ac, char **av)
// {
// 	int fd;
// 	char *line;

// 	if (ac != 2)
// 	{
// 		ft_putendl_fd("Error: usage is <config_file.cub>", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	file_name_checker(av[1]);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd == -1)
// 		err_incorrect_file(av[1]); // todo
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		line_parser(line, game); // todo
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	debug_game(game);
// }

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