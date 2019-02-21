/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:56:42 by mpasquie          #+#    #+#             */
/*   Updated: 2017/12/06 13:56:48 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

short			ft_is_putable(char **grid, t_coord *start, t_tris *piece)
{
	short	i;

	i = 0;
	while (4 - i)
	{
		if (!(grid[start->y + (piece->coord[i]).y])
			|| !(grid[start->y + (piece->coord[i]).y]
				[start->x + (piece->coord[i]).x]))
			return (0);
		if (((start->y + piece->coord[i].y >= 0)
			|| (start->x + piece->coord[i].x >= 0))
			&& (grid[start->y + (piece->coord[i]).y]
				[start->x + (piece->coord[i]).x] != '.'))
			return (0);
		i++;
	}
	return (i);
}

void			ft_put_piece(char **grid, t_coord *start, t_tris *piece)
{
	short	i;

	i = 0;
	while (4 - i)
	{
		grid[start->y + (piece->coord[i]).y]
			[start->x + (piece->coord[i]).x] = piece->name;
		i++;
	}
}

t_coord			*ft_new_point(int x, int y)
{
	t_coord		*ret;

	ret = (t_coord*)malloc(sizeof(t_coord));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_coord			*ft_next_point(t_coord *start, char **grid)
{
	t_coord		*ret;
	short		i;
	short		j;

	ret = ft_new_point(-1, -1);
	i = start->y;
	j = start->x + 1;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
			{
				ret->x = j;
				ret->y = i;
				return (ret);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}
