/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:01:27 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 12:12:59 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	exit_cub(t_state *state)
{
	(void)state;
	exit(0);
}

// void	go(t_state *state, t_vec2 dir)
// {
// 	const double	new_x = state->player.pos.x + STEP_SIZE * dir.x;
// 	const double	new_y = state->player.pos.y + STEP_SIZE * dir.y;

// 	if (new_x > 0 && new_x < state->map->map_width && new_y > 0 && new_y < state->map->map_height && state->map->map[(int)new_y][(int)new_x] == '0')
// 	{
// 		state->player.pos.x = new_x;
// 		state->player.pos.y = new_y;
// 	}
// }

// void	rotate(t_state *state, int dir)
// {
// 	const double	olddirx = state->player.dir.x;
// 	const double	oldplanex = state->player.plane.x;

// 	state->player.dir.x = olddirx * cos(dir * ROTATION_SPEED) - state->player.dir.y * sin(dir * ROTATION_SPEED);
// 	state->player.dir.y = olddirx * sin(dir * ROTATION_SPEED) + state->player.dir.y * cos(dir * ROTATION_SPEED);
// 	state->player.plane.x = oldplanex * cos(dir * ROTATION_SPEED) - state->player.plane.y * sin(dir * ROTATION_SPEED);
// 	state->player.plane.y = oldplanex * sin(dir * ROTATION_SPEED) + state->player.plane.y * cos(dir * ROTATION_SPEED);
// }

int	key_down(int kc, t_state *state)
{
	if (kc == LEFT_KC)
		state->pressed[LEFT] = 1;
	else if (kc == RIGHT_KC)
		state->pressed[RIGHT] = 1;
	else if (kc == W_KC)
		state->pressed[W] = 1;
	else if (kc == A_KC)
		state->pressed[A] = 1;
	else if (kc == S_KC)
		state->pressed[S] = 1;
	else if (kc == D_KC)
		state->pressed[D] = 1;
	else if (kc == ESC_KC)
		exit_cub(state);
	// if (keycode == LEFT)
	// 	rotate(state, -1);
	// else if (keycode == RIGHT)
	// 	rotate(state, 1);
	// else if (keycode == W)
	// 	go(state, state->player.dir);
	// else if (keycode == S)
	// 	go(state, s_multiplication(state->player.dir, -1));
	// else if (keycode == A)
	// 	go(state, perpendicular_vec2(state->player.dir, CLOCKWISE));
	// else if (keycode == D)
	// 	go(state, perpendicular_vec2(state->player.dir, COUNTER_CLOCKWISE));
	// else if (keycode == ESC)
	// 	exit_cub(state);
	return (0);
}

int	key_up(int kc, t_state *state)
{
	if (kc == LEFT_KC)
		state->pressed[LEFT] = 0;
	else if (kc == RIGHT_KC)
		state->pressed[RIGHT] = 0;
	else if (kc == W_KC)
		state->pressed[W] = 0;
	else if (kc == A_KC)
		state->pressed[A] = 0;
	else if (kc == S_KC)
		state->pressed[S] = 0;
	else if (kc == D_KC)
		state->pressed[D] = 0;
	else if (kc == ESC_KC)
		exit_cub(state);
	return (0);
}
