/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:48:40 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/09 10:42:41 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_new_line(const char *s);
size_t	find_nl(const char *s);
char	*read_from_fd(int fd, char *left_over);
void	*ft_free(void **ptr);
char	*find_next_nl(char *buffer, int fd, char *temp_buffer);

#endif
