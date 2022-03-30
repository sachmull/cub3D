/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:04:57 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 13:15:13 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <libft.h>
# include <raycaster.h>

t_result	parse(t_state *state, char *file);

// utility.c
t_result	check_extension(char *file, char *ext);
t_result	check_access(char *file);
t_result	is_empty(char *line);
void		free_splits(char **splitted);
t_result	file_to_img(void *mlx, t_img *dst, char *path);

#endif
