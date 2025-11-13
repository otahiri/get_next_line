/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:59:59 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/13 16:06:31 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*read_initial(int fd, char **left_over)
{
	char	*buffer;
	int		read_res;

	if (!*left_over || !**left_over)
	{
		if (*left_over)
			ft_free((void **)left_over);
		buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_res = read(fd, buffer,
				(size_t)BUFFER_SIZE);
		if (read_res <= 0)
			return (ft_free((void **)&buffer));
		buffer[read_res] = 0;
	}
	else
	{
		buffer = ft_strdup(*left_over);
		ft_free((void **)left_over);
	}
	return (buffer);
}

void	*ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*read_till_nl(int fd, char *buffer)
{
	char	*temp_buffer;
	int		read_res;

	temp_buffer = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		temp_buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!temp_buffer)
			return (NULL);
		read_res = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_res < 0)
			return (ft_free((void **)&temp_buffer));
		temp_buffer[read_res] = 0;
		if (read_res == 0)
			return (ft_strjoin(buffer, temp_buffer));
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*left_over[1024];
	char		*result;
	char		*buffer;
	int			end;

	end = 0;
	if (fd > 1024)
		return (NULL);
	buffer = read_initial(fd, &left_over[fd]);
	if (!buffer)
		return (NULL);
	buffer = read_till_nl(fd, buffer);
	if (!buffer)
		return (NULL);
	while (buffer[end] && buffer[end] != '\n')
		end++;
	if (buffer[end] == '\n')
		end++;
	result = ft_substr(buffer, 0, end);
	if (!result)
		return (ft_free((void **)&buffer));
	left_over[fd] = ft_strdup(buffer + end);
	ft_free((void **)&buffer);
	return (result);
}
