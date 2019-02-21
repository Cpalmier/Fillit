/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:32 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/28 15:12:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_config	*open_file(char *file, t_config *config)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((config = read_file(&fd, config)) == 0)
		return (NULL);
	return (config);
}

t_config	*read_file(int *fd, t_config *config)
{
	char	*buff;
	int		i;
	t_tris	*tris;
	int		last_read;
	int		now_read;

	i = 0;
	last_read = -1;
	buff = ft_strnew(21);
	while ((now_read = read(*fd, buff, 21)))
	{
		last_read = now_read;
		tris = create_tris(buff, i);
		if (tris == NULL)
			return (NULL);
		config->nbr_piece = i + 1;
		config->list_tris[i] = *tris;
		i++;
	}
	if (last_read != 20 || now_read != 0)
		return (NULL);
	return (config);
}
