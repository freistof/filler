/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readinput.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 14:10:13 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 14:10:13 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char				*readinput(void)
{
	char	buf[1000 + 1];
	char	*join;
	char	*temp;
	int		fd;
	int		ret;

	ret = 1;
//	fd = open("test", O_RDONLY);
	fd = STDIN_FILENO;
	join = ft_strdup("\0");
	ft_bzero(buf, 100);
	ret = read(fd, buf, 1000);
	buf[ret] = '\0';
	temp = ft_strjoin(join, buf);
	free (join);
	join = temp;
	FILE *fp_out;
	fp_out = fopen("reads", "w+");
	fprintf(fp_out, "%s\n", join);
	return (join);
}
