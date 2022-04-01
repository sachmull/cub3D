/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:09 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 13:01:53 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycaster.h>
#include <time.h>
#include <parser.h>

static int	init_state(t_state *state)
{
	state->map = ft_calloc(sizeof(t_map), 1);
	if (state->map == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 1);
		return (-1);
	}
	state->map->map_height = 0;
	state->map->map_width = 0;
	state->map->map = NULL;
	state->map->pos_map = -5;
	state->map->path_text = ft_calloc(sizeof(char *), 5);
	state->map->colours = ft_calloc(sizeof(char *), 4);
	if (state->map->path_text == NULL || state->map->path_text == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 1);
		// ft_free_all(state);
		return (-1);
	}
	state->map->colours[2] = NULL;
	state->map->path_text[4] = NULL;
	return (0);
}

t_state	get_state(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3D");

	return ((t_state)
	{
		.mlx = mlx,
		.win = win,
		.img = mu_new_img(mlx, WIN_W, WIN_H),
		.mouse_x = 0,
		.pressed = {0, 0, 0, 0, 0, 0, 0, 0}
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
	// printf("FPS %.5f\n",
	// 	1 /
	// 	(((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
	// 	((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec)));
	// ---------
	return (1);
}

int	main(int argc, char **argv)
{
	t_state	state;

	state = get_state();
	if (init_state(&state) != 0)
		return (1);
	if (check_args(argc, argv) == -1)
		return (1);
	if (parsing(&state, argv) == -1)
		return (1);
	set_player_pos(&state);

	mlx_loop_hook(state.mlx, loop_hook, &state);
	mlx_hook(state.win, KEY_DOWN, 0, key_down, &state);
	mlx_hook(state.win, KEY_UP, 0, key_up, &state);
	mlx_hook(state.win, DESTROY, 0, exit_cub, &state);
	mlx_hook(state.win, MOUSE_DOWN, 0, mouse_down, &state);
	mlx_hook(state.win, MOUSE_UP, 0, mouse_up, &state);
	mlx_hook(state.win, MOUSE_MOVE, 0, mouse_move, &state);
	//mlx_mouse_hide(state.mlx, state.win);
	mlx_loop(state.mlx);
	// ft_free_all(&state);			//added Kathi
	return (EXIT_SUCCESS);
}



/* // void	ft_free_all(t_state *state)
// {
// 	free_colours(state);
// 	free_path_text(state);
// 	free_map(state);
// } */