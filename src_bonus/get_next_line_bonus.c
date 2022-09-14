/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 06:22:25 by matcardo          #+#    #+#             */
/*   Updated: 2022/09/14 15:58:28 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*target;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	target = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	ft_strlcpy(target, s1, len_s1 + 1);
	ft_strlcat(target, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (target);
}

char	*ft_strdup2(char *src)
{
	size_t	len;
	char	*target;

	len = ft_strlen(src);
	target = (char *)malloc((len + 1) * sizeof(char));
	*(target + len) = '\0';
	while (len-- > 0)
		*(target + len) = *(src + len);
	return (target);
}

char	*get_line(int fd, char *backup, size_t buffer_size)
{
	char	*line;
	char	*buffer;
	int		line_lenght;

	if (backup)
		line = ft_strdup2(backup);
	else
		line = ft_strdup2("");
	buffer = malloc((buffer_size + 1) * sizeof(char));
	line_lenght = 1;
	while (!ft_strchr(line, '\n') && line_lenght)
	{
		line_lenght = read(fd, buffer, buffer_size);
		if (line_lenght < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[line_lenght] = '\0';
		line = ft_strjoin2(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*take_backup(char *line, char *old_backup)
{
	char	*backup;
	char	*end;

	free(old_backup);
	end = ft_strchr(line, '\n');
	if (!end)
		return (NULL);
	backup = ft_strdup2(end + 1);
	*(end + 1) = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, backup, BUFFER_SIZE);
	if (!line)
	{
		free(backup);
		return (NULL);
	}
	backup = take_backup(line, backup);
	if (!*line)
	{
		free(backup);
		free(line);
		return (NULL);
	}
	return (line);
}
