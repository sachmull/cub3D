/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:24:21 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 14:11:42 by khammers         ###   ########.fr       */
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
		mlx_destroy_image(state->mlx, state->tex[i]->img);
		free(state->tex[i]);
		state->tex[i] = NULL;
		i++;
	}
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
	if (state->map->map != NULL)		//or state->map->map[y]
	{
		free (state->map->map);
		state->map->map = NULL;
	}
}

void	ft_free_all(t_state *state)
{
	// free_colours(state);
	// free_path_text(state);
	free_map(state);
	free_textures(state);
	if (state->map)
	{
		free(state->map);
		state->map = NULL;
	}
	free(state->map->path_text);
	state->map->path_text = NULL;
	free(state->map->colours);
	state->map->colours = NULL;
}

int	exit_cub(t_state *state)
{
	(void)state;
	ft_free_all(state);
	exit(0);
}