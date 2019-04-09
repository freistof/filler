/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 13:23:59 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 13:23:59 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h> // remove
# include <fcntl.h> // remove ?

//# define FD STDIN_FILENO
# define FD 3

typedef struct 				s_filler
{
	char					player;
	int						x;
	int						y;
	char					*map;
	char					*piece;
}							t_filler;	

char						*get_map(char *line);

#endif
