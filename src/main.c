/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:09 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 19:52:30 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycaster.h>
#include <time.h>

t_state	get_state(void)
{
	char	**map;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3D");

	map = malloc(7 * sizeof(char *));
	map[0] = ft_strdup("1111111111111");
	map[1] = ft_strdup("1000001000001");
	map[2] = ft_strdup("1000000000001");
	map[3] = ft_strdup("1000001100001");
	map[4] = ft_strdup("1000000011001");
	map[5] = ft_strdup("1000000001001");
	map[6] = ft_strdup("1111111111111");
	return ((t_state)
	{
		.mlx = mlx,
		.win = win,
		.img = mu_new_img(mlx, WIN_W, WIN_H),
		.buffer = mu_new_img(mlx, WIN_W, WIN_H),
		.mouse_x = 0,
		.map = map,
		.player = (t_player)
		{
			.pos = (t_vec2){.x = 1.5, .y = 1.5},
			.dir = (t_vec2){.x = 1, .y = 0},
			.planex = 0,
			.planey = 0.66,
			.a = 0,
			.fov = M_PI / 3
		}
	});
}

int	render(t_state *state)
{
	// TIME DIFF
	struct timespec tstart = {0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC,  &tstart);
	// ---------
	// step_by_step(state);
	// dda(state);
	// permadi(state);
	cgtutor(state);
	// TIME DIFF
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("FPS %.5f\n", 
		1 / 
		(((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec)));
	// ---------
	return (1);
}

int	main(void)
{
	t_state	state;

	state = get_state();
	mlx_loop_hook(state.mlx, render, &state);
	mlx_hook(state.win, KEY_DOWN, 0, key_hook, &state);
	mlx_hook(state.win, DESTROY, 0, exit_cub, &state);
	//mlx_hook(state.win, MOUSE_MOVE, 0, mouse_hook, &state);
	//mlx_mouse_hide(state.mlx, state.win);
	mlx_loop(state.mlx);
	return (EXIT_SUCCESS);
}
