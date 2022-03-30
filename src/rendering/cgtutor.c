/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgtutor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:29:40 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 14:40:34 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

void cgtutor(t_state *state)
{
	t_player		*player = &state->player;
	t_img	texture = mu_new_xpm_img(state->mlx, "textures/redbrick.xpm");
	for (int x =0; x < WIN_W; ++x)
	{
        // calculate ray position and direction
		double  camerax = 2 * x / (double)WIN_W - 1;
		double  raydirx = player->dir.x + player->planex * camerax;
        double	raydiry = player->dir.y + player->planey * camerax;

		// which box of the map were in
		int	mapx = (int)player->pos.x;
		int	mapy = (int)player->pos.y;

		// length of ray from current position to next x or y-side
		double	sidedistx;
		double	sidedisty;

		// length of ray from one x or y-side to next x or y-side
		double	deltadistx = (raydirx == 0) ? 1e30 : fabs(1 / raydirx);
		double	deltadisty = (raydiry == 0) ? 1e30 : fabs(1 / raydiry);
		double	perpwalldist;

		// what direction to step in x or y-direction (either +1 or -1)
		int	stepx;
		int	stepy;

		int	hit = 0; // was there a wall hit
		int	side; // was a NS or a EW wall hit

		// calculate step and initial sideDist
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (player->pos.x - mapx) * deltadistx;
		} else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - player->pos.x) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (player->pos.y - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - player->pos.y) * deltadisty;
		}

		/// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			// check if ray has hit a wall
			if (state->map[mapy][mapx] != '0') hit = 1;
		}

		// calculate distance projected on camera direction
		if (side == 0)	perpwalldist = (sidedistx - deltadistx);
		else			perpwalldist = (sidedisty - deltadisty);

		// calculate height of line to draw on screen
		int	lineheight = (int)((double)WIN_H / perpwalldist);

		// calculate lowest and highest pixel to fill in current stripe
		int	drawstart = -lineheight / 2 + WIN_H / 2;
		if (drawstart < 0) drawstart = 0;
		int	drawend = lineheight / 2 + WIN_H / 2;
		if (drawend >= WIN_H) drawend = WIN_H - 1;

		// texturing calculation

		// calculate value of wallX
		double	wallx; // where exactly the wall was hit
		if (side == 0)
			wallx = state->player.pos.y + perpwalldist * raydiry;
		else
			wallx = state->player.pos.x + perpwalldist * raydirx;
		wallx -= floor(wallx);

		// x coordinate on the texture
		int	texx = (int)(wallx * (double)texture.width);
		if (side == 0 && raydirx > 0)
			texx = texture.width - texx - 1;
		if (side == 1 && raydiry < 0)
			texx = texture.width - texx - 1;
		
		// how much to increase the texture coordinate per screen pixel
		double	step = 1.0 * texture.height / lineheight;
		// starting texture coordinate
		double	texPos = (drawstart - WIN_H / 2 + lineheight / 2) * step;
		for (int y = drawstart; y <= drawend; y++)
		{
			// cast the texture coordinate to integer, and mask with (textHeight - 1) in case of overflow
			int	texy = (int)texPos & (texture.height - 1);
			texPos += step;
			(void)texy;
			unsigned int	color = ((unsigned int *)texture.addr)[texture.width * texy + texx];
			// make color darker for y-sides: R, G, and B byte each divided through two with a shift and an and
			if (side == 1)
				color = (color >> 1) & 8355711;
			// printf("%d %d\n", x, y);
			mu_put_pixel(&state->img, x, y, color);
		}

		// draw the pixels of the stripe as a vertical line
		mu_draw_rect(&state->img, mu_new_rect(x, 0, 1, drawstart), 0x000000FF);
		mu_draw_rect(&state->img, mu_new_rect(x, drawend + 1, 1, WIN_H - drawend), 0x000F0F0F);
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
