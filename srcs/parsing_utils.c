/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:50:31 by sesquier          #+#    #+#             */
/*   Updated: 2026/05/05 19:51:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool    is_map_line(char *line)
{
    int i;
    int has_content;

    i = 0;
    has_content = 0;
    while (line[i] && line[i] != '\n')
    {
        if (!ft_strchr("01NSEW ", line[i]))
            return (false);
        if (ft_strchr("01NSEW", line[i]))
            has_content = 1;
        i++;
    }
    return (has_content == 1);
}

void    put_infos(t_game *game, char *idx, char *infos)
{
    if (ft_strncmp(idx, "NO", 2) == 0)
    {
		game->north.path = infos;
		free(infos);
	}
    else if (ft_strncmp(idx, "SO", 2) == 0)
    {
		game->south.path = infos;
		free(infos);
	}
    else if (ft_strncmp(idx, "WE", 2) == 0)
    {
		game->west.path = infos;
		free(infos);
	}
    else if (ft_strncmp(idx, "EA", 2) == 0)
    {
		game->east.path = infos;
		free(infos);
	}
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
    // printf("take_infos: idx=%s infos=[%s] j=%d\n", idx, infos, j);
	put_infos(game, idx, ft_strdup(infos));
}

// void    check_config_complete(t_game *game)
// {
// 	if (!game->north.path || !game->south.path
// 		|| !game->west.path || !game->east.path)
// 	{
// 		ft_putendl_fd("Error: missing texture path", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (game->floor_color[0] == -1 || game->ceil_color[0] == -1)
// 	{
// 		ft_putendl_fd("Error: missing floor or ceiling color", 2);
// 		exit(EXIT_FAILURE);
// 	}
// }

void    check_config_complete(t_game *game)
{
    if (!game->north.path || !game->south.path
        || !game->west.path || !game->east.path)
    {
        ft_putendl_fd("Error: missing texture path", 2);
        exit(EXIT_FAILURE);
    }
    if (game->floor_color[0] == -1 || game->floor_color[1] == -1
        || game->floor_color[2] == -1)
    {
        ft_putendl_fd("Error: missing or invalid floor color", 2);
        exit(EXIT_FAILURE);
    }
    if (game->ceil_color[0] == -1 || game->ceil_color[1] == -1
        || game->ceil_color[2] == -1)
    {
        ft_putendl_fd("Error: missing or invalid ceiling color", 2);
        exit(EXIT_FAILURE);
    }
}

void    check_player(t_game *game)
{
	if (game->player.dir == 0)
	{
		ft_putendl_fd("Error: no player found in map", 2);
		exit(EXIT_FAILURE);
	}
}

void    alloc_map(t_game *game)
{
	int i;

	// printf("alloc_map: height=%d width=%d\n", game->map.height, game->map.width);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
	{
		ft_putendl_fd("Error: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[i])
		{
			ft_putendl_fd("Error: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		ft_memset(game->map.grid[i], ' ', game->map.width);
		game->map.grid[i][game->map.width] = '\0';
		i++;
	}
	game->map.grid[game->map.height] = NULL;
}

static void    flood_fill(char **grid, int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
	{
		ft_putendl_fd("Error: map is not closed", 2);
		exit(EXIT_FAILURE);
	}
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	if (grid[y][x] == ' ')
	{
		ft_putendl_fd("Error: map is not closed", 2);
		exit(EXIT_FAILURE);
	}
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y, width, height);
	flood_fill(grid, x - 1, y, width, height);
	flood_fill(grid, x, y + 1, width, height);
	flood_fill(grid, x, y - 1, width, height);
}

void    check_map_closed(t_game *game)
{
	int     x;
	int     y;
	char    **grid_copy;
	int     i;

	grid_copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!grid_copy)
	{
		ft_putendl_fd("Error: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->map.height)
	{
		grid_copy[i] = ft_strdup(game->map.grid[i]);
		i++;
	}
	grid_copy[game->map.height] = NULL;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (ft_strchr("NSEW", grid_copy[y][x]))
			{
				flood_fill(grid_copy, x, y, game->map.width, game->map.height);
				i = 0;
				while (grid_copy[i])
					free(grid_copy[i++]);
				free(grid_copy);
				return ;
			}
			x++;
		}
		y++;
	}
}

void    colors_infos(t_game *game, char *idx, char *num, int count)
{
    int n;

    n = ft_atoi(num);
    if (n < 0 || n > 255)
    {
        ft_putendl_fd("Error: RGB value out of range [0-255]", 2);
        exit(EXIT_FAILURE);
    }
    if (idx[0] == 'F')
        game->floor_color[count] = n;
    else if (idx[0] == 'C')
        game->ceil_color[count] = n;
}

// static bool	check_colors(t_game *game)
// {
// 	int	count;

// 	count = 0;
// 	while (game->ceil_color[count])
// 	{
// 		if (game->ceil_color[count] == -1)
// 			return (false);
// 		count++;
// 	}
// 	count = 0;
// 	while (game->floor_color[count])
// 	{
// 		if (game->floor_color[count] == -1)
// 			return (false);
// 		count++;
// 	}
// 	return (true);
// }

// void    take_numbers(t_game *game, char *line, char *idx)
// {
//     int     i;
//     int     j;
//     int     count;
//     char    num[4];

//     i = 0;
//     count = 0;
//     while (line[i] && line[i] != '\n' && !ft_isdigit(line[i])
//         && line[i] != '-')
//         i++;
//     while (line[i] && line[i] != '\n' && count < 3)
//     {
//         if (!ft_isdigit(line[i]) && line[i] != ',' && ft_isalpha(line[i]))
//         {
//             ft_putendl_fd("Error: invalid character in color", 2);
//             exit(EXIT_FAILURE);
//         }
//         j = 0;
//         while (line[i] && ft_isdigit(line[i]) && j < 3)
//             num[j++] = line[i++];
//         num[j] = '\0';
//         if (j > 0)
//             colors_infos(game, idx, num, count++);
//         while (line[i] && (line[i] == ',' || line[i] == ' '))
//             i++;
//     }
// 	if (!check_colors(game))
// 	{
//         ft_putendl_fd("Error: invalid character in color", 2);
//         exit(EXIT_FAILURE);
//     }	
// }

void    take_numbers(t_game *game, char *line, char *idx)
{
    int     i;
    int     j;
    int     count;
    char    num[4];

    i = 0;
    count = 0;
    while (line[i] && line[i] != '\n' && line[i] != ' '
        && line[i] != idx[0])
        i++;
    if (line[i] == idx[0])
        i++;
    while (line[i] && line[i] != '\n' && count < 3)
    {
        while (line[i] == ' ' || line[i] == ',')
            i++;
        if (!line[i] || line[i] == '\n')
            break ;
        if (!ft_isdigit(line[i]))
        {
            ft_putendl_fd("Error: invalid character in RGB value", 2);
            exit(EXIT_FAILURE);
        }
        j = 0;
        while (line[i] && ft_isdigit(line[i]) && j < 3)
            num[j++] = line[i++];
        num[j] = '\0';
        if (j > 0)
            colors_infos(game, idx, num, count++);
        if (line[i] && line[i] != '\n' && line[i] != ','
            && line[i] != ' ')
        {
            ft_putendl_fd("Error: invalid character in RGB value", 2);
            exit(EXIT_FAILURE);
        }
    }
}
