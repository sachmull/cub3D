/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:08:39 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 13:22:31 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_result	is_side(char *line)
{
	const char	side_ident[SIDE_COUNT] = SIDE_IDENTIFIERS;
	char*const	space = ft_strchr(line, ' ');
	size_t		idx;

	if (!space)
		return (ERR);
	*space = '\0';
	idx = 0;
	while (idx < SIDE_COUNT)
	{
		if (!ft_strcmp(side_ident[idx], line))
		{
			*space = ' ';
			return (OK);
		}
		++idx;
	}
	return (ERR);
}

t_result	parse_side(t_state *state, char *line)
{
	const char	side_ident[SIDE_COUNT] = SIDE_IDENTIFIERS;
	char*const	splits = ft_split(line, ' ');
	size_t		idx;

	if (!splits[1] || splits[2] || !check_access(splits[1]))
	{
		free_splits(splits);
		return (ERR);
	}
	idx = 0;
	while (idx < SIDE_COUNT)
	{
		if (!ft_strcmp(side_ident[idx], splits[0]))
			if (!file_to_img(mlx, &state->textures.sides[idx], splits[1]))
			{
				free_splits(splits);
				return (ERR);
			}
		++idx;
	}
	free_splits(splits);
	return (OK);
}
