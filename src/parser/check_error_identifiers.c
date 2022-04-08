/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_identifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:08:35 by khammers          #+#    #+#             */
/*   Updated: 2022/04/08 16:06:33 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Transforms rgb values from char to int and checks their range. */
static int	parse_rgb_info(t_state *state, int i, int *k)
{
	int		j;
	char	**temp;

	j = 0;
	temp = ft_split(state->map->colours[i], ',');
	if (temp == NULL)
		return (-1);
	while (temp[j])
	{
		state->map->rgb[*k] = ft_atoi(temp[j++]);
		if (state->map->rgb[*k] < 0 || state->map->rgb[*k] > 255)
		{
			ft_putstr_fd("Error\nRGB value out of range\n", 1);
			return (-1);
		}
		(*k)++;
	}
	ft_free_strarray(&temp);
	return (0);
}

/* Saves the rgb value if correct within struct state. */
static int	get_rgb(t_state *state)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (state->map->colours[i])
	{
		parse_rgb_info(state, i, &k);
		i++;
	}
	return (0);
}

/* Transforms rgb values into one int using bitshifting. */
static void	transform_rgb(t_state *state )
{
	state->map->ceiling = ((state->map->rgb[0] & 0xff) << 16) + \
		((state->map->rgb[1] & 0xff) << 8) + (state->map->rgb[2] & 0xff);
	state->map->floor = ((state->map->rgb[3] & 0xff) << 16) + \
		((state->map->rgb[4] & 0xff) << 8) + (state->map->rgb[5] & 0xff);
}

int	ft_strcmp_new(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i])
	{
		if (i + 1 == n)
			break ;
		if (s1[i + 1] == '\0' || s2[i + 1] == '\0')
			return ((unsigned char)s1[i + 1] - (unsigned char)s2[i + 1]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* Checks for right strlen of path and colour array, right range of RGV values
and a valid path for texture paths. */
int	check_identifiers(t_state *state)
{
	if (ft_strnstr(state->map->path_text[0], "NO",
			ft_strlen(state->map->path_text[0])) == NULL && \
			ft_strnstr(state->map->path_text[1], "EA",
			ft_strlen(state->map->path_text[1])) == NULL && \
			ft_strnstr(state->map->path_text[2], "SO",
			ft_strlen(state->map->path_text[2])) == NULL && \
			ft_strnstr(state->map->path_text[3], "WE",
			ft_strlen(state->map->path_text[3])) == NULL && \
			ft_strnstr(state->map->path_text[3], "WE",
			ft_strlen(state->map->path_text[3])) == NULL && \
			ft_strchr(state->map->colours[0], 'C') == NULL && \
			ft_strchr(state->map->colours[1], 'F') == NULL && \
			(ft_arrlen(state->map->path_text) != 4 || \
			ft_arrlen(state->map->colours) != 2 \
			|| state->map->pos_map == -5))
	{
		ft_putstr_fd("Error\nInvalid identifiers found\n", 1);
		return (-1);
	}
	if (get_rgb(state) != 0)
		return (-1);
	transform_rgb(state);
	return (0);
}
