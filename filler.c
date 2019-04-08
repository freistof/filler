/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 13:15:20 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 13:15:21 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	The first steps is to read the current state of the board from the standard input.
** 	See file readinput.c
*/

int			main(void)
{
	t_info 	*coor;

	coor = malloc(sizeof(t_info) * 1);
	readinput(coor);
	return (0);
}
