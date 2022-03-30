/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachmull <sachmull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:29 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/18 12:43:29 by sachmull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_result	parse_texture(t_state *state, char *line)
{
	if (!line)
		return (ERR);
	else if (is_empty(line))
		return (OK);
	else if (is_side(line))
		return (parse_side(state, line));
	else if (is_abs(line))
		return (parse_abs(state, line));
	else
		return (ERR);
}
