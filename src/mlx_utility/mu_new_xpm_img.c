/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mu_new_xpm_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:01:15 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/30 13:24:51 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utility.h>

t_img	mu_new_xpm_img(void *mlx_ptr, char *filepath)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, filepath, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
