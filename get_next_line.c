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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

size_t	find_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*read_from_fd(int fd, char *left_over)
{
	char	*res;
	int		read_res;

	if (left_over == NULL || *left_over == '\0')
	{
		res = malloc(sizeof(char) * BUFFER_SIZE);
		read_res = read(fd, res, BUFFER_SIZE);
		res[BUFFER_SIZE] = '\0';
	}
	else
		res = ft_strdup(left_over);
	if (read_res <= 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*find_next_nl(char *buffer, int fd, char *temp_buffer)
{
	int		read_res;

	while (ft_strchr(buffer, '\n') == NULL)
	{
		read_res = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(buffer);
			free(temp_buffer);
			return (NULL);
		}
		if (read_res == 0)
			break ;
		buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*temp_buffer;
	char		*buffer;
	char		*res;
	static char	*left_over;
	int			end;

	temp_buffer = read_from_fd(fd, left_over);
	if (!temp_buffer)
		return (NULL);
	buffer = NULL;
	buffer = ft_strjoin(buffer, temp_buffer);
	buffer = find_next_nl(buffer, fd, temp_buffer);
	if (!buffer)
		return (NULL);
	end = find_nl(buffer) + 2;
	left_over = ft_substr(buffer, end, ft_strlen(buffer));
	return (free(temp_buffer), ft_substr(buffer, 0, end));
}

int main()
{
	char *res;
	int i = 0;
	int fd = open("text.txt", O_RDONLY);
	while (i < 10)
	{
		res = get_next_line(fd);
		printf("%s", res);
		i++;
	}
}
