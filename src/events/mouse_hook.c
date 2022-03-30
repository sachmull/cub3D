/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:18:16 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 17:55:10 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	mouse_hook(int x, int y, t_state *state)
{
	(void)y;
	if (x < state->mouse_x)
		state->player.a -= ROTATION_SPEED;
	else if (x > state->mouse_x)
		state->player.a += ROTATION_SPEED;
	state->mouse_x = x;
	return (0);
}
