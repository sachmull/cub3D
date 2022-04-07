/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:09 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/07 18:26:21 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycaster.h>
#include <time.h>
#include <parser.h>

static void	init_state(t_state *state)
{
	state->map = ft_calloc(sizeof(t_map), 1);
	if (state->map == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 1);
		exit_cub(state);
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
		exit_cub(state);
	}
	state->map->colours[2] = NULL;
	state->map->path_text[4] = NULL;
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


int	main(int argc, char **argv)
{
	t_state	state;

	state = get_state();
	init_state(&state);
	if (check_args(argc, argv) == -1)
		exit_cub(&state);
	if (parsing(&state, argv) == -1)
		exit_cub(&state);
	set_player_pos(&state);
	mlx_loop_hook(state.mlx, loop_hook, &state);
	mlx_hook(state.win, KEY_DOWN, 0, key_down, &state);
	mlx_hook(state.win, KEY_UP, 0, key_up, &state);
	mlx_hook(state.win, DESTROY, 0, exit_cub, &state);
	mlx_hook(state.win, MOUSE_DOWN, 0, mouse_down, &state);
	mlx_hook(state.win, MOUSE_UP, 0, mouse_up, &state);
	mlx_hook(state.win, MOUSE_MOVE, 0, mouse_move, &state);
	mlx_loop(state.mlx);
	return (EXIT_SUCCESS);
}
