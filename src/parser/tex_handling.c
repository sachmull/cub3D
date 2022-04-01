/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:23 by khammers          #+#    #+#             */
/*   Updated: 2022/04/01 16:14:13 by sachmull         ###   ########.fr       */
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
		state->tex[i] = ft_calloc(1, sizeof(t_img));
		// if (state->img_tex[i] = NULL)
		// {
		// 	ft_putstr_fd("Error\nMemory allocation failed\n", 1);
		// 	return (-1);
		// }
		
		// state->tex[i]->img = mlx_xpm_file_to_image(state->mlx, state->map->path_text[0], \
		// 	&(state->tex[i]->width), &(state->tex[i]->height));
		state->tex[i] = mu_new_xpm_img(state->mlx, state->map->path_text[i]);
		
		// if (state->img_tex[i])
		// {
		// 	ft_putstr_fd("Error\nXPM file could not be put to image\n", 1);
		// 	return (-1);
		// }
		i++;
	}
	return (0);
}
