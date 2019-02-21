/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:23 by cpalmier          #+#    #+#             */
/*   Updated: 2017/12/06 13:35:53 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit target_file\n");
		return (0);
	}
	fillit(&argc, argv);
	return (0);
}
