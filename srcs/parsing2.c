/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:49:47 by sesquier          #+#    #+#             */
/*   Updated: 2026/04/29 18:54:26 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	process_map_line(t_game *game, char *line);
void		parse_pass1(t_game *game, char *file);
static void	fill_map_line(t_game *game, char *line, int row);
void		parse_pass2(t_game *game, char *file);

// void parse(t_game *game, int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		ft_putendl_fd("Error: usage is ./cub3d <map.cub>", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	file_name_checker(av[1]);
// 	parse_pass1(game, av[1]);
// 	check_config_complete(game);
// 	check_player(game);
// 	alloc_map(game);
// 	parse_pass2(game, av[1]);
// 	check_map_closed(game);
// 	debug_game(game);
// }

void parse(t_game *game, int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl_fd("Error: usage is ./cub3d <map.cub>", 2);
        exit(EXIT_FAILURE);
    }
    file_name_checker(av[1]);
    parse_pass1(game, av[1]);
    // printf("pass1 done\n");
    check_config_complete(game);
    // printf("config ok\n");
    check_player(game);
    // printf("player ok\n");
    alloc_map(game);
    // printf("alloc ok\n");
    parse_pass2(game, av[1]);
    // printf("pass2 done\n");
    check_map_closed(game);
    // printf("map closed ok\n");
    debug_game(game);
}

static void process_map_line(t_game *game, char *line)
{
	int i;

	i = 0;
    // printf("process_map_line BEFORE: height=%d\n", game->map.height);
    game->map.height += 1;
    // printf("process_map_line AFTER: height=%d\n", game->map.height);
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr("NSEW", line[i]))
		{
			if (game->player.dir != 0)
			{
				ft_putendl_fd("Error: multiple players in map", 2);
				exit(EXIT_FAILURE);
			}
			game->player.dir = line[i];
		}
		i++;
	}
	if (i > game->map.width)
		game->map.width = i;
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
}

// void parse_pass1(t_game *game, char *file)
// {
// 	int fd;
// 	char *line;
// 	bool map_started;

// 	map_started = false;
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		err_incorrect_file(file);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (!map_started && is_map_line(line))
// 			map_started = true;
// 		if (map_started)
// 			process_map_line(game, line);
// 		else
// 			line_parser(line, game);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }

void parse_pass1(t_game *game, char *file)
{
    int fd;
    char *line;
    bool map_started;

    map_started = false;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        err_incorrect_file(file);
    line = get_next_line(fd);
    while (line)
    {
        // printf("LINE: [%s] map_started=%d is_map=%d\n", 
            // line, map_started, is_map_line(line));
        if (!map_started && is_map_line(line))
            map_started = true;
        if (map_started)
            process_map_line(game, line);
        else
            line_parser(line, game);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

static void fill_map_line(t_game *game, char *line, int row)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		game->map.grid[row][i] = line[i];
		i++;
	}
}

void parse_pass2(t_game *game, char *file)
{
	int fd;
	char *line;
	bool map_started;
	int row;

	map_started = false;
	row = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_incorrect_file(file);
	line = get_next_line(fd);
	while (line)
	{
		if (!map_started && is_map_line(line))
			map_started = true;
		if (map_started)
		{
			fill_map_line(game, line, row);
			row++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
