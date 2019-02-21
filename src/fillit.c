/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:15 by cpalmier          #+#    #+#             */
/*   Updated: 2017/12/06 13:31:55 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	fillit(int *argc, char **argv)
{
	t_config	*config;

	config = init_config();
	if (*argc == 2)
	{
		if ((config = open_file(argv[1], config)) != NULL)
		{
			algo(config);
			ft_print_grid(config->grid);
			return ;
		}
	}
	ft_putstr("error\n");
}
