/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:59:59 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/05 13:30:15 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*res;
	int		read_return;

	res = calloc(BUFFER_SIZE, sizeof(char));
	read_return = read(fd, res, BUFFER_SIZE);
}
