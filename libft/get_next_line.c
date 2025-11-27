/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:02:36 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/14 22:40:17 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	leftovers(char **main_line, char **line)
{
	char	*aux;
	int		i;

	i = 0;
	while (main_line[0][i] != '\0' && main_line[0][i] != '\n')
		i++;
	if (main_line[0][i])
		i++;
	*line = ft_substr_gnl(*main_line, 0, i);
	if (main_line[0][i])
	{
		aux = ft_substr_gnl(*main_line, i, (ft_strlen_gnl(*main_line) - i));
		free(*main_line);
		*main_line = aux;
	}
	else
	{
		free(*main_line);
		*main_line = NULL;
	}
}

static char	*cr_main_line(char *main_line, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(main_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(buffer);
			free(main_line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		main_line = ft_strjoin_gnl(main_line, buffer);
		if (!main_line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (main_line);
}

char	*get_next_line(int fd)
{
	static char	*main_line = NULL;
	char		*line;

	line = NULL;
	if (fd == -1)
		return (NULL);
	main_line = cr_main_line(main_line, fd);
	if (main_line == NULL)
		return (NULL);
	leftovers(&main_line, &line);
	return (line);
}
