/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playgame.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 16:39:16 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/09 16:39:16 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		get_player(char *input)
{
	if (input[0] == '$')
	{
		if (input[10] == '2')
			return ('X');
		return ('O');
	}
	if (input[6] == 'O')
		return ('X');
	return ('O');
}

void			play_game(char *read)
{
	char	player;

	player = get_player(read);
	printf("%c\n", player);
}
