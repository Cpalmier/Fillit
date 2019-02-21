/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:11 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/27 17:41:12 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_tris	*init_tris(char name)
{
	t_tris	*tris;
	t_coord	*coord;
	int		i;

	i = -1;
	tris = (t_tris*)malloc(sizeof(t_tris));
	tris->name = name + 65;
	while (++i < 4)
	{
		coord = (t_coord*)malloc(sizeof(t_coord));
		coord->x = -1;
		coord->y = -1;
		tris->coord[i] = *coord;
	}
	return (tris);
}

t_tris	*create_tris(char *str, char name)
{
	t_tris	*tris;
	int		i;
	int		nbr;

	i = -1;
	nbr = -1;
	tris = init_tris(name);
	while (++i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (NULL);
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#' && ++nbr < 4)
			create_tris_coord(tris, nbr, i);
		else
			return (NULL);
	}
	if (name != 0 && str[i] != '\n')
		return (NULL);
	return (check_tris(tris));
}

void	create_tris_coord(t_tris *tris, int nbr, int i)
{
	t_coord		point;

	point = *ft_new_point(i % 5, i / 5);
	tris->coord[nbr] = point;
}
