/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_try2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nde-wild <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 19:27:01 by nde-wild      #+#    #+#                 */
/*   Updated: 2019/02/17 12:47:13 by nde-wild      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_createsave(char *buf, char *str, char **line, int ret)
{
	char	*save;

	*line = ft_strsub(str, 0, linelen(str, '\n'));
	if (str[0] == '\0' && ret == 0)
		save = NULL;
	else
		save = ft_strdup(&buf[linelen(buf, '\n')] + 1);
	free(buf);
	if (str)
		free(str);
	return (save);
}

static char		*ft_makestr(const int fd, char *save, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*temp;
	int		ret;

	str = ft_strdup(save);
	ret = ft_strlen(str);
	if (str[linelen(str, '\n')] == '\n')
		return (ft_createsave(save, str, line, ret));
	free(save);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		temp = ft_strdup(str);
		free(str);
		buf[ret] = '\0';
		str = ft_strjoin(temp, buf);
		free(temp);
		if (str[linelen(str, '\n')] == '\n')
			return (ft_createsave(ft_strdup(buf), str, line, ret));
		ft_strclr(buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ft_createsave(ft_strnew(1), str, line, ret));
}

static void		addtolst(t_list **list, t_list **head)
{
	*list = *head;
	ft_lstadd(list, ft_lstnew("\0", 1));
	*head = *list;
}

static char		*fd_checker(const int fd, char *save)
{
	static t_list	*list;
	t_list			*head;

	if (!list)
	{
		list = ft_lstnew("\0", 1);
		list->content_size = fd;
	}
	head = list;
	while (fd != (int)list->content_size && list->next != NULL)
		list = list->next;
	if (fd != (int)list->content_size && list->next == NULL)
	{
		addtolst(&list, &head);
		list->content_size = fd;
	}
	if (save == NULL)
		save = ft_strdup(list->content);
	else
	{
		free(list->content);
		list->content = save;
	}
	list = head;
	return (save);
}

int				get_next_line(const int fd, char **line)
{
	char			*save;

	save = NULL;
	if (fd == -1 || read(fd, save, 0) == -1)
		return (-1);
	save = fd_checker(fd, save);
	save = ft_makestr(fd, save, line);
	if (save == NULL)
	{
		if (read(fd, save, BUFF_SIZE) == 0)
		{
			free(save);
			return (0);
		}
	}
	save = fd_checker(fd, save);
	return (1);
}
