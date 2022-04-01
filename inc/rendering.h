/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:08 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 14:44:49 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <raycaster.h>
# include <vec2.h>

# define SCALE_W ((WIN_W / 5) / state->map->map_width)
# define SCALE_H ((WIN_H / 5) / state->map->map_height)

typedef struct s_state	t_state;

void	cgtutor(t_state *state);
void	draw_minimap(t_state *state);

#endif
