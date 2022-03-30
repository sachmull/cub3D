/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:09:50 by khammers          #+#    #+#             */
/*   Updated: 2022/03/31 00:20:35 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/*	Parsing the *.cub map.

	Identifying the height of the map and the width of each row for memory
	allocation. Parsing the content of the map into state->map[][]. */
int	parsing(t_state *state, char **argv)
{
	if (parse_identifiers(state, argv[1]) == -1)
		return (-1);
	if (parse_map(state, argv) != 0)
		return (-1);
	print_map(state);
	if (map_error_check(state) != 0)
		return (-1);
	return (0);
}
