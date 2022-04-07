/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:24:21 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 15:48:44 by sachmull         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < 4)
		free(state->map->path_text[i++]);
	free(state->map->path_text);
	state->map->path_text = NULL;
	free(state->map->colours);
	state->map->colours = NULL;
	// free_colours(state);
	// free_path_text(state);
	free_map(state);
	free_textures(state);
	if (state->map)
	{
		free(state->map);
		state->map = NULL;
	}
}

void	free_mlx(t_state *state)
{
	mlx_destroy_image(state->mlx, state->img.img);
	mlx_destroy_window(state->mlx, state->win);
	free(state->mlx);
}

int	exit_cub(t_state *state)
{
	ft_free_all(state);
	free_mlx(state);
	exit(0);
}