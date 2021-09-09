/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleonia <cleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:33:31 by cleonia           #+#    #+#             */
/*   Updated: 2021/09/05 13:33:32 by cleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

int	gnl_free(char **s, int i)
{
	if (*s != NULL)
		free (*s);
	*s = NULL;
	return (i);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0' && *str != '\n')
	{
		i++;
		str++;
	}
	return (i);
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*object;

	object = malloc(count * size);
	if (object == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		object[i] = 0;
		i++;
	}
	return (object);
}
