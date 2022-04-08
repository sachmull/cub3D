/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:27 by khammers          #+#    #+#             */
/*   Updated: 2022/04/08 22:45:20 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Checks if there are any characters found in line which are not map
characters. If so, the start of the map has not bee n found. */
static int	check_characters(char *line)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != 'D')
			return (1);
		i++;
	}
	return (0);
}

static char	**get_token(char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	if (token == NULL || ft_arrlen(token) != 2)
	{
		ft_free_strarray(&token);
		return (NULL);
	}
	return (token);
}

static int	get_pos(t_state *state, char *line, char *temp, int i)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)) != 0)
	{
		if (state->map->path_text[0] != NULL)
			return (-1);
		state->map->path_text[0] = ft_strdup(temp);
		state->map->id_pos[0] = i;
		// state->map->pos_idf++;
	}
	if (ft_strnstr(line, "EA", ft_strlen(line)) != 0)
	{
		if (state->map->path_text[1] != NULL)
			return (-1);
		state->map->path_text[1] = ft_strdup(temp);
		state->map->id_pos[1] = i;
		// state->map->pos_idf++;
	}
	if (ft_strnstr(line, "SO", ft_strlen(line)) != 0)
	{
		if (state->map->path_text[2] != NULL)
			return (-1);
		state->map->path_text[2] = ft_strdup(temp);
		state->map->id_pos[2] = i;
		// state->map->pos_idf++;
	}
	if (ft_strnstr(line, "WE", ft_strlen(line)) != 0)
	{
		if (state->map->path_text[3] != NULL)
			return (-1);
		state->map->path_text[3] = ft_strdup(temp);
		state->map->id_pos[3] = i;
		// state->map->pos_idf++;
	}
	if (ft_strnstr(line, "C", ft_strlen(line)) != 0)
	{
		if (state->map->colours[0] != NULL)
			return (-1);
		state->map->colours[0] = ft_strdup(temp);
		state->map->id_pos[4] = i;
		// state->map->pos_idf++;
	}
	if (ft_strnstr(line, "F", ft_strlen(line)) != 0)
	{
		if (state->map->colours[1] != NULL)
			return (-1);
		state->map->colours[1] = ft_strdup(temp);
		state->map->id_pos[5] = i;
		// state->map->pos_idf++;
	}
	return (0);
}

/* Checks every line for identifiers, cuts newline characters at the end
of string and saves texture path as well as rgb value in 2D arrays. */
static int	get_rgb_spawning(t_state *state, char *line, int i)
{
	char	**token;
	char	*temp;
	int		ret;

	ret = 0;
	temp = NULL;
	token = get_token(line);
	if (token == NULL)
		return (1);
	temp = ft_strtrim(token[1], "\n");
	ret = get_pos(state, line, temp, i);
	ft_free_strarray(&token);
	ft_free_string(&temp);
	if (ret == -1)
	{
		ft_putstr_fd("Error\nToo many identifiers\n", 1);
		return (-1);
	}
	return (0);
}

/* Reads *.cub file and checks for spawning and colour identifiers as well
as the start of the map. */
static int	get_identifiers(t_state *state, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = 0;
	if (open_cub_file(file, &fd) == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (get_rgb_spawning(state, line, i) == -1)
			exit_cub(state);
		if (state->map->pos_map == -5 && line[0] != '\n' \
			&& check_characters(line) == 0)
			state->map->pos_map = i;
		ft_free_string(&line);
		i++;
	}
	ft_free_string(&line);
	close(fd);
	return (0);
}

static void	init_id_pos(t_state *state)
{
	int	i;

	i = 0;
	while (i != 6)
	{
		state->map->id_pos[i] = -1;
		i++;
	}
}

static int	check_id_pos(t_state *state)
{
	int	i;

	i = 0;
	while (i != 6)
	{
		if (state->map->id_pos[i] == -1 || \
			state->map->id_pos[i] > state->map->pos_map)
			return (-1);
		i++;
	}
	return (0);
}

int	parse_identifiers(t_state *state, char *file)
{
	init_id_pos(state);
	if (get_identifiers(state, file) != 0)
		return (-1);
	if (check_id_pos(state) == -1)
	{
		ft_putstr_fd("Error\nInvalid indentifier\n", 1);
		return (-1);
	}
	if (rgb_config(state) != 0)
		return (-1);
	return (0);
}




// /* Checks for right strlen of path and colour array, right range of RGV values
// and a valid path for texture paths. */
// int	check_identifiers(t_state *state)
// {
// 	if (!(state->map->path_text[0]) || !(state->map->path_text[1])
// 		|| !(state->map->path_text[2]) || !(state->map->path_text[3])
// 		|| (!(state->map->colours[0])) || (!(state->map->colours[1])))
// 		return (-1);
// 	if (ft_strnstr(state->map->path_text[0], "NO",			//do not search for NO in path
// 			ft_strlen(state->map->path_text[0])) == NULL && \
// 			ft_strnstr(state->map->path_text[1], "EA",
// 			ft_strlen(state->map->path_text[1])) == NULL && \
// 			ft_strnstr(state->map->path_text[2], "SO",
// 			ft_strlen(state->map->path_text[2])) == NULL && \
// 			ft_strnstr(state->map->path_text[3], "WE",
// 			ft_strlen(state->map->path_text[3])) == NULL && \
// 			ft_strnstr(state->map->path_text[3], "WE",
// 			ft_strlen(state->map->path_text[3])) == NULL && \
// 			ft_strchr(state->map->colours[0], 'C') == NULL && \
// 			ft_strchr(state->map->colours[1], 'F') == NULL && \
// 			(ft_arrlen(state->map->path_text) != 4 || \
// 			ft_arrlen(state->map->colours) != 2 \
// 			|| state->map->pos_map == -5))
// 		return (-1);
// 	return (0);
// }
