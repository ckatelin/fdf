/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:30:28 by kcorie            #+#    #+#             */
/*   Updated: 2019/07/18 17:08:29 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_get_line(char **arr, char **line, int fd, int result)
{
	char		*tmp;
	int			i;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0')
		i++;
	if (arr[fd][i] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, i);
		tmp = ft_strdup(arr[fd] + i + 1);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else if (arr[fd][i] == '\0')
	{
		if (result == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			result;
	static char	*array[10240];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (array[fd] == NULL)
		array[fd] = ft_strnew(0);
	while (ft_strchr(array[fd], '\n') == NULL)
	{
		result = read(fd, buff, BUFF_SIZE);
		buff[result] = '\0';
		if (result == 0)
			break ;
		tmp = ft_strjoin((array[fd]), buff);
		free(array[fd]);
		array[fd] = tmp;
	}
	if (result < 0)
		return (-1);
	else if (!result && (!array[fd] || !array[fd][0]))
		return (0);
	return (ft_get_line(array, line, fd, result));
}
