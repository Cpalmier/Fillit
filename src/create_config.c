/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:41:08 by cpalmier          #+#    #+#             */
/*   Updated: 2017/11/27 17:41:09 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_config	*init_config(void)
{
	t_config	*config;

	config = (t_config*)malloc(sizeof(t_config));
	return (config);
}
