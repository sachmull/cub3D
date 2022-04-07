/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:25:02 by sachmull          #+#    #+#             */
/*   Updated: 2022/04/06 20:00:55 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

#include <raycaster.h>

typedef struct s_state	t_state;

int		exit_cub(t_state *state);
void	ft_free_all(t_state *state);

#endif
