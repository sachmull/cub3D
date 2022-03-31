/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:09 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/31 14:17:53 by khammers         ###   ########.fr       */
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
	// char	**map;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3D");

	// map = malloc(4 * sizeof(char *));
	// map[0] = ft_strdup("1111111111111");
	// map[1] = ft_strdup("1000000000001");
	// map[2] = ft_strdup("1000100011001");
	// map[3] = ft_strdup("1111111111111");
	return ((t_state)
	{
		.mlx = mlx,
		.win = win,
		.img = mu_new_img(mlx, WIN_W, WIN_H),
		.buffer = mu_new_img(mlx, WIN_W, WIN_H),
		.mouse_x = 0,
		// .map = map,						//.map = state->map->map;			KATHII
		.player = (t_player)
		{
			.pos = (t_vec2){.x = 10.5, .y = 1.5},
			.dir = (t_vec2){.x = -1, .y = 0},
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

int	main(int argc, char **argv)
{
	t_state	state;

	state = get_state();
	init_state(&state);					//added Kathi
	if (init_state(&state) != 0)
		return (1);
	if (check_args(argc, argv) == -1)
		return (1);
	if (parsing(&state, argv) == -1)
		return (1);

	mlx_loop_hook(state.mlx, render, &state);
	mlx_hook(state.win, KEY_DOWN, 0, key_hook, &state);
	mlx_hook(state.win, DESTROY, 0, exit_cub, &state);
	//mlx_hook(state.win, MOUSE_MOVE, 0, mouse_hook, &state);
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