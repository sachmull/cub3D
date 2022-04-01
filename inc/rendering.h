/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:08 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/01 17:33:11 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <raycaster.h>
# include <vec2.h>

# define SCALE_W ((WIN_W / 5) / state->map->map_width)
# define SCALE_H ((WIN_H / 5) / state->map->map_height)

typedef struct s_state	t_state;

typedef struct s_dda
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	unsigned int	color;
}				t_dda;

void	cgtutor(t_state *state);
void	draw_minimap(t_state *state);

#endif
