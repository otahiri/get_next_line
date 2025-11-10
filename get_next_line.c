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

size_t	ft_strlen_new_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	*tmp;
	char	*buffer;
	char	*leftover;
	int		error_value;

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = 
	if (!tmp)
		return (NULL);
	error_value = read(fd, tmp, BUFFER_SIZE);
	if (error_value < 0)
		return (NULL);
	while (!ft_strchr(tmp, '\n'))
	{
		ft_strjoin(buffer, tmp);
		error_value = read(fd, tmp, BUFFER_SIZE);
	}
	res = ft_substr(buffer, 0, ft_strlen_new_line(buffer) + 1);
	leftover = ft_strdup(buffer + ft_strlen_new_line(buffer) + 1);
	free(tmp);
	return (res);
}

int main()
{
	char *res;
	int i = 0;
	while (i < 187)
	{
		res = get_next_line(open("text.txt", O_RDONLY));
		printf("%s", res);
		i++;
	}
}
