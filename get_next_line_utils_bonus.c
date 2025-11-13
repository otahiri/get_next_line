/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:11:31 by otahiri-          #+#    #+#             */
/*   Updated: 2025/11/10 10:19:07 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	while (i <= size)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	end;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > ft_strlen(s))
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	end = start + len;
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res_str;
	size_t	len;
	size_t	temp_len;
	size_t	total_len;

	if (!s1)
		return (ft_strdup(s2));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	len = 0;
	temp_len = 0;
	res_str = malloc(sizeof(char) * (total_len + 1));
	if (!res_str)
		return (NULL);
	while (s1[temp_len])
		res_str[len++] = s1[temp_len++];
	temp_len = 0;
	while (len < total_len)
		res_str[len++] = s2[temp_len++];
	res_str[len] = '\0';
	ft_free((void **)&s1);
	ft_free((void **)&s2);
	return (res_str);
}
