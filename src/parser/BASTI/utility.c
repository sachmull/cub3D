/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:29:50 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 13:21:59 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_result	check_extension(char *file, char *ext)
{
	char*const	dot = ft_strrchr(file, '.');

	if (ft_strncmp(dot, ext, ft_strlen(ext) + 1) == 0)
		return (OK);
	return (ERR);
}

t_result	check_access(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ERR);
	close(fd);
	return (OK);
}

t_result	is_empty(char *line)
{
	char	*s;
	size_t	len;

	s = ft_strtrim(line, " \n\t\r\v\f");
	len = ft_strlen(s);
	free(s);
	if (!len)
		return (OK);
	return (ERR);
}

void	free_splits(char **splitted)
{
	size_t	i;

	i = 0;
	while(splitted[i])
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
}

t_result	file_to_img(void *mlx, t_img *dst, char *path)
{
	if (check_extension(path, ".xpm"))
		dst->img = mlx_xpm_file_to_image(mlx, path, dst->width, dst->height);
	else if (check_extension(path, ".png"))
		dst->img = mlx_png_file_to_img(mlx, path, dst->width, dst->height);
	else
		return (ERR);
	if (!dst->img)
		return (ERR);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len, &dst->endian);
	return (OK);
}
