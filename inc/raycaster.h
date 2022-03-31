/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:25:35 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/31 14:54:04 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <mlx.h>
# include <stdlib.h>
# include <mlx_utility.h>
# include <libft.h>
# include <events.h>
# include <rendering.h>
# include <stdio.h>
# include <math.h>
# include <vec2.h>

# define PI 3.14159265359
# define WIN_W 2048
# define WIN_H 1024

// place holder, should replaced with variables holding the actual calues
# define MAP_H 4	//state->map->map_height
# define MAP_W 13	//state->map->map_width

typedef enum e_result {ERR, OK}	t_result;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	double	planex;
	double	planey;
	// not used, left for compilation reasons
	double	a;
	double	fov;
}				t_player;

# define TEXTURE_IDENTIFIERS {"NO", "EA", "SO", "WE", "F", "C"}

# define ABSOLUTE_IDENTIFIERS {"F", "C"}
typedef enum e_absolutes {F, C, ABS_COUNT}	t_abs;

# define SIDE_IDENTIFIERS {"NO", "EA", "SO", "WE"}
typedef enum e_side {NORTH, EAST, SOUTH, WEST, SIDE_COUNT} t_side;

typedef struct s_textures
{
	t_img	sides[SIDE_COUNT];
	int		abs[ABS_COUNT];
}				t_textures;

typedef struct s_map
{
	int			map_height;
	int			map_width;
	int			pos_map;
	char		**map;
	char		**path_text;
	char		**colours;
	int			rgb[6];
} t_map;

typedef struct	s_tex
{
	void	*tex;
	int		width;
	int		height;
} t_tex;
typedef struct s_state
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		buffer;
	int			mouse_x;
	t_player	player;
	t_textures	textures;


	struct s_map	*map;						//added Kathi
	int		ceiling;
	int		floor;
	t_tex	*tex[4];
}				t_state;

#endif
