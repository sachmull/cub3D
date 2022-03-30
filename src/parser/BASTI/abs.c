/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:23:01 by sachmull          #+#    #+#             */
/*   Updated: 2022/03/31 00:08:28 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <parser.h>

t_result	is_abs(char *line)
{
	const char	abs_ident[ABS_COUNT] = ABSOLUTE_IDENTIFIERS;
	char*const	space = ft_strchr(line, ' ');
	size_t		idx;

	if (!space)
		return (ERR);
	*space = '\0';
	idx = 0;
	while (idx < ABS_COUNT)
	{
		if (!ft_stcmp(abs_ident[idx], line))
		{
			*space = ' ';
			return (OK);
		}
		++idx;
	}
	return (ERR);
}
