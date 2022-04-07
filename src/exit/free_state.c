/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:34:53 by khammers          #+#    #+#             */
/*   Updated: 2022/04/07 17:21:24 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit.h>

/* Frees memory area allocated to the game's images. */
static void	free_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (state->tex[i]->img)
			mlx_destroy_image(state->mlx, state->tex[i]->img);
		if (state->tex[i])
		{
			free(state->tex[i]);
			state->tex[i] = NULL;
		}
		i++;
	}
	//abort with this free
	// free(&state->tex);
}

/* Frees memory area used to save gamefield in 2D array. */
static void	free_map(t_state *state)
{
	int	y;

	y = 0;
	while (y < state->map->map_height)
	{
		if (state->map->map[y] != NULL)
		{
			free (state->map->map[y]);
			state->map->map[y] = NULL;
		}
		y++;
	}
	if (state->map->map != NULL)
	{
		free (state->map->map);
		state->map->map = NULL;
	}
}

static void	free_colours_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (state->map->colours[i])
		{
			free(state->map->colours[i]);
			state->map->colours[i] = NULL;
		}
		i++;
	}
	if (state->map->colours)
	{
		free(state->map->colours);
		state->map->colours = NULL;
	}
	ft_free_strarray(&state->map->path_text);
}

void	free_state(t_state *state)
{
	free_colours_textures(state);
	free_map(state);
	free_textures(state);
	if (state->map)
	{
		free(state->map);
		state->map = NULL;
	}
}
