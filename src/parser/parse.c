/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:09:54 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 12:56:09 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_result	parse(t_state *state, char *file)
{
	int		fd;
	char	*line;

	ft_bzero(&state->textures, sizeof(t_textures));
	if (!check_extension(file, ".cub") || !check_access(file))
		return (ERR);
	fd = open(file, O_RDONLY);
	line = ft_next_line(fd);
	while (parse_texture(state, line))
	{
		free(line);
		line = ft_next_line(fd);
	}
	while (parse_map(state, line))
	{
		free(line);
		line = ft_next_line(fd);
	}
	if (!close(fd) && !parse_map(state, line))
	{
		free(line);
		return (ERR);
	}
	free(line);
	return (OK);
}
