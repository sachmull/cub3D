/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:24:21 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 18:08:10 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit.h>

void	free_mlx(t_state *state)
{
	mlx_destroy_image(state->mlx, state->img.img);
	mlx_destroy_window(state->mlx, state->win);
	free(state->mlx);
}

int	exit_cub(t_state *state)
{
	free_state(state);
	free_mlx(state);
	exit(0);
}
