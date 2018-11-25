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
# include "SDL.h"
# include "SDL_opengl.h"
#include "../libft/libft.h"

# define MES1 "Usage : ./scop [obj file] [texture]"
# define MES2 "File opening failed"
# define MES3 "Reading failure"
# define MES4 "Memory allocation failure"
# define MES5 "Invalid scene file"

typedef struct		s_sdl
{
	SDL_Window		*win;
	int 			win_w;
	int 			win_h;
	u_int			*pixels;
	SDL_Renderer*	renderer;
	SDL_Surface*	surf;
	SDL_Texture*	canvas;
}					t_sdl;

typedef struct		s_vertex
{
	float 			vertex[3];
	float 			normals[3];
	float 			texture_coords[3];
}					t_vertex;

typedef struct		s_indices
{
	int 			index;
	float 			normals[3];
	float 			texture_coords[3];
} 					t_indices;

typedef struct		s_scop
{
	int				vertices_amount;
	int				faces_amount;
	int 			lines;
	struct s_vertex *vertices;
	struct s_indices *indices;
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
int 			sdl_init_everything(t_sdl *s);
void	run_ui(t_sdl *s);
void 	fill_buffers(t_scop *scop, t_sdl *s);

#endif