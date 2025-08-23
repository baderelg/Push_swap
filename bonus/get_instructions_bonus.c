/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:33:54 by baelgadi          #+#    #+#             */
/*   Updated: 2025/08/22 21:19:49 by baelgadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	append_char(char **dst, int *len, char c)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(*len + 2);
	if (!tmp)
		return (0);
	i = 0;
	while (i < *len)
	{
		tmp[i] = (*dst)[i];
		i++;
	}
	tmp[i++] = c;
	tmp[i] = '\0';
	free(*dst);
	*dst = tmp;
	*len += 1;
	return (1);
}

char	*get_next_instruction(int fd)
{
	char	buf;
	char	*line;
	int		len;
	ssize_t	bytes_read;

	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	len = 0;
	while (1)
	{
		bytes_read = read(fd, &buf, 1);
		if (bytes_read <= 0)
			break ;
		if (buf == '\0')
			return (free(line), NULL);
		if (!append_char(&line, &len, buf))
			return (free(line), NULL);
		if (buf == '\n')
			return (line);
	}
	if (len == 0)
		return (free(line), NULL);
	return (line);
}
