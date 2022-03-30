/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:01:44 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/24 14:55:50 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <raycaster.h>

typedef struct s_state t_state;

// Keycodes
# define W 13
# define A 0
# define S 1
# define D 2

# define LEFT 123
# define RIGHT 124

# define ESC 53

// Movement speed
# define ROTATION_SPEED 0.1
# define STEP_SIZE 0.3

// Events
# define KEY_DOWN 2
# define DESTROY 17
# define MOUSE_MOVE 6

// key_hook.c
int	key_hook(int keycode, t_state *state);
int	exit_cub(t_state *state);

// mouse_hook.c
int	mouse_hook(int x, int y, t_state *state);

#endif
