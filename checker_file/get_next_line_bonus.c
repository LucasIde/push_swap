/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:24 by lide              #+#    #+#             */
/*   Updated: 2022/03/21 16:56:18 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*s3;

	if (!s1)
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!s3)
			return (NULL);
		while (s2[++i])
			s3[i] = s2[i];
	}
	else
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s3)
			free(s1);
		if (!s3)
			return (NULL);
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[++j])
			s3[i++] = s2[j];
		free(s1);
	}
	s3[i] = 0;
	return (s3);
}

char	*ft_read(int fd, char *save)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (1));
	if (!str)
		return (NULL);
	i = 1;
	while (backspace(save) && i)
	{
		i = read(fd, str, 1);
		if (i == -1 || (!save && i == 0))
		{
			free(str);
			return (NULL);
		}
		str[i] = 0;
		save = ft_strjoin(save, str, -1, -1);
		if (!save)
		{
			free(str);
			return (NULL);
		}
	}
	free(str);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			len;

	if (fd < 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	len = ft_find(save);
	line = ft_line(save, len);
	if (!line)
		return (NULL);
	save = ft_save(save, len);
	if (!save)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
