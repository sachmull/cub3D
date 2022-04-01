/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:12:58 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 17:31:58 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

void	draw_minimap(t_state *state)
{
	int	y;
	int	x;

	y = 0;
	while (y < state->map->map_height)
	{
		x = 0;
		while (x < state->map->map_width)
		{
			if (state->map->map[y][x] == '1')
				mu_draw_rect(&state->img, mu_new_rect(x * SCALE_W, y * SCALE_H,
						SCALE_W, SCALE_H), state->map->floor);
			++x;
		}
		++y;
	}
	mu_draw_rect(&state->img, mu_new_rect(state->player.pos.x * SCALE_W,
			state->player.pos.y * SCALE_H, (double)SCALE_W / 1.5,
			(double)SCALE_H / 2.5), 0x00FFFFFF - state->map->ceiling);
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
