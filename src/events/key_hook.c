/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:01:27 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/31 16:23:18 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	exit_cub(t_state *state)
{
	(void)state;
	exit(0);
}

void	go(t_state *state, t_vec2 dir)
{
	const double	new_x = state->player.pos.x + STEP_SIZE * dir.x;
	const double	new_y = state->player.pos.y + STEP_SIZE * dir.y;

	if (new_x > 0 && new_x < MAP_W && new_y > 0 && new_y < MAP_H && state->map->map[(int)new_y][(int)new_x] == '0')
	{
		state->player.pos.x = new_x;
		state->player.pos.y = new_y;
	}
}

void	rotate(t_state *state, int dir)
{
	const double	olddirx = state->player.dir.x;
	const double	oldplanex = state->player.planex;

	state->player.dir.x = olddirx * cos(dir * ROTATION_SPEED) - state->player.dir.y * sin(dir * ROTATION_SPEED);
	state->player.dir.y = olddirx * sin(dir * ROTATION_SPEED) + state->player.dir.y * cos(dir * ROTATION_SPEED);
	state->player.planex = oldplanex * cos(dir * ROTATION_SPEED) - state->player.planey * sin(dir * ROTATION_SPEED);
	state->player.planey = oldplanex * sin(dir * ROTATION_SPEED) + state->player.planey * cos(dir * ROTATION_SPEED);
}

int	key_hook(int keycode, t_state *state)
{
	if (keycode == LEFT)
		rotate(state, -1);
	else if (keycode == RIGHT)
		rotate(state, 1);
	else if (keycode == W)
		go(state, state->player.dir);
	else if (keycode == S)
		go(state, s_multiplication(state->player.dir, -1));
	else if (keycode == A)
		go(state, perpendicular_vec2(state->player.dir, CLOCKWISE));
	else if (keycode == D)
		go(state, perpendicular_vec2(state->player.dir, COUNTER_CLOCKWISE));
	else if (keycode == ESC)
		exit_cub(state);
	return (0);
}
