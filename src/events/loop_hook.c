/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:49:42 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 14:46:04 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	loop_hook(t_state *state)
{
	struct timespec tstart = {0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC,  &tstart);

	movement(state);
	cgtutor(state);
	draw_minimap(state);

	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("FPS %.5f\n",
		1 /
		(((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec)));

	return (0);
}
