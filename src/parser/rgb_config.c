/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:15:26 by khammers          #+#    #+#             */
/*   Updated: 2022/04/08 19:31:13 by khammers         ###   ########.fr       */
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
	if (ft_arrlen(temp) != 3)
	{
		ft_putstr_fd("Error\nNo valid RGB input\n", 1);
		return (-1);
	}
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
		if (parse_rgb_info(state, i, &k) == -1)
			return (-1);
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

int	rgb_config(t_state *state)
{
	if (get_rgb(state) != 0)
		return (-1);
	transform_rgb(state);
	return (0);
}
