/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:59:59 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/10 10:18:27 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_initial(int fd, char *left_over)
{
	char	*buffer;
	int		read_res;

	if (!left_over || !*left_over)
	{
		if (left_over)
			free(left_over);
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res <= 0)
			return (free(buffer), NULL);
		buffer[read_res] = 0;
	}
	else
	{
		buffer = ft_strdup(left_over);
		free(left_over);
	}
	return (buffer);
}

char	*read_till_nl(int fd, char *buffer)
{
	char	*temp_buffer;
	int		read_res;

	temp_buffer = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp_buffer)
			return (NULL);
		read_res = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[read_res] = 0;
		if (read_res < 0)
			return (free(temp_buffer), NULL);
		else if (read_res == 0)
			return (ft_strjoin(buffer, temp_buffer));
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*result;
	char		*buffer;
	int			end;

	end = 0;
	buffer = read_initial(fd, left_over);
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
		return (free(buffer), NULL);
	left_over = ft_strdup(buffer + end);
	free(buffer);
	return (result);
}
