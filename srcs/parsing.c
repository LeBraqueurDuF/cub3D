/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:49:47 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/05 19:07:48 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	process_map_line(t_game *game, char *line);
void		parse_pass1(t_game *game, char *file);
static void	fill_map_line(t_game *game, char *line, int row);
void		parse_pass2(t_game *game, char *file);

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
    game->map.height += 1;
    while (line[i] && line[i] != '\n')
    {
        if (!ft_strchr("01NSEW ", line[i]))
        {
            ft_putendl_fd("Error: invalid character in map", 2);
            exit(EXIT_FAILURE);
        }
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

static int  skip_spaces(char *line)
{
    int i;

    i = 0;
    while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
        i++;
    return (i);
}

void line_parser(char *line, t_game *game)
{
    int start;

    if (!line)
        return ;
    start = skip_spaces(line);
    if (ft_strncmp(line + start, "NO ", 3) == 0)
        take_infos(game, line + start, "NO");
    else if (ft_strncmp(line + start, "SO ", 3) == 0)
        take_infos(game, line + start, "SO");
    else if (ft_strncmp(line + start, "WE ", 3) == 0)
        take_infos(game, line + start, "WE");
    else if (ft_strncmp(line + start, "EA ", 3) == 0)
        take_infos(game, line + start, "EA");
    else if (ft_strncmp(line + start, "F ", 2) == 0)
        take_numbers(game, line + start, "F");
    else if (ft_strncmp(line + start, "C ", 2) == 0)
        take_numbers(game, line + start, "C");
}

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
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			game->player.pos_x = i + 0.5;
			game->player.pos_y = row + 0.5;
			game->player.dir = line[i];
		}
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
