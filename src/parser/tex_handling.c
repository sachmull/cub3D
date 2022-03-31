/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:23 by khammers          #+#    #+#             */
/*   Updated: 2022/03/31 15:00:22 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/* Allocates memory for each texture (NO, SO, EA, WE)  */
int	load_textures(t_state *state)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		state->tex[i] = ft_calloc(sizeof(t_tex), 1);
		if (!state->tex[i])
		{
			ft_putstr_fd("Error\nMemory allocation failed\n", 1);
			return (-1);
		}
		state->tex[i] = mlx_xpm_file_to_image(state->mlx,
			state->map->path_text[i], &(state->tex[i]->width), &(state->tex[i]->height));
		i++;
	}
	return (0);
}
