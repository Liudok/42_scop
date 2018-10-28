/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <lberezyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:49:39 by lberezyn          #+#    #+#             */
/*   Updated: 2018/10/28 13:49:41 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCOP_H
# define SCOP_H

#include <stdio.h>

#include "../libft/libft.h"

# define MES1 "Usage : ./scop [obj file] [texture]"
# define MES2 "File opening failed"
# define MES3 "Reading failure"
# define MES4 "Memory allocation failure"
# define MES5 "Invalid scene file"


typedef struct		s_scop
{
	int				vertices_amount;
	int				faces_amount;
	int 			lines;
	char			*str;
	int				width;
	int				heigh;
	int				center_x;
	int				center_y;
	int				move_x;
	int				move_y;
	int				**color;
	int				col_coof;
	double			scale;
	double			depth;
	short			def_scale;
	int				step;
	float			an_x;
	float			an_y;
	float			an_z;
	double			alp;
	double			bet;
	double			gam;
}					t_scop;

int obj_parser(char *file_name, t_scop *scop);
void init_error_messages(void);
void ft_error(char *s);
int count_lines(char *file_name, t_scop *scop);
int get_data(char *file_name, t_scop *scop);

#endif