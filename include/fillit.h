/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:21:14 by mpasquie          #+#    #+#             */
/*   Updated: 2018/04/18 16:15:26 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_coord
{
	short			x;
	short			y;
}					t_coord;

typedef struct		s_tris
{
	char			name;
	t_coord			coord[4];
}					t_tris;

typedef struct		s_config
{
	char			**grid;
	short			min_size;
	char			nbr_piece;
	t_tris			list_tris[26];
}					t_config;

t_config			*open_file(char *file, t_config *config);
t_config			*read_file(int *fd, t_config *config);
void				fillit(int *argc, char **argv);
t_tris				*create_tris(char *str, char name);
void				create_tris_coord(t_tris *tris, int nbr, int i);
t_tris				*check_tris(t_tris *tris);
char				check_tris_form(t_tris *tris);
t_tris				*init_tris(char name);
t_tris				*order_tris(t_tris *tris);
t_config			*init_config();
void				ft_print_grid(char **tab);
char				**ft_new_grid(short nb_piece);
void				ft_del_grid(char ***grid);
void				ft_clean_grid(char **grid, char letter);
void				ft_put_piece(char **grid, t_coord *start, t_tris *piece);
t_coord				*ft_new_point(int x, int y);
short				ft_is_putable(char **grid, t_coord *start, t_tris *piece);
char				**ft_copy_grid(char **grid, short len);
t_coord				*ft_next_point(t_coord *start, char **grid);
char				ft_grid_isfull(char **grid);
int					brain_rec(t_config *config, t_coord *pos,
					char **grid, int iter);
void				algo(t_config *config);

#endif
