/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <lberezyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:39:31 by lberezyn          #+#    #+#             */
/*   Updated: 2018/10/28 13:39:34 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/scop.h"

int ft_reader(int fd, char **ar)
{
	int		i;
	char	*line;
	int		ret;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ar[i] = ft_strdup(line);
		free(line);
		i++;
	}
	ar[i] = NULL;
	if (ret == -1)
		ft_error(MES3);
	return (0);
}




int obj_parser(char *file_name, t_scop *scop)
{
	//int fd;
	//char	**ar;
	t_sdl s;

	count_lines(file_name, scop);
	scop->vertices = (struct	s_vertex *)malloc(sizeof(struct	s_vertex) * scop->vertices_amount);
	scop->indices = (struct s_indices *)malloc(sizeof(struct s_indices) * (scop->faces_amount * 4 + 1));
	//TODO bzero these two arrays
	get_data(file_name, scop);
	// if (!(ar = (char**)malloc(sizeof(char*) * (scop->lines + 1))))
	// 	ft_error(MES4);

	// fd = open(file_name, O_RDONLY);
	// if (fd < 0)
	// 	ft_error(MES2);
	// if (ft_reader(fd, ar))
	// 	ft_error(MES3);

	// printf("ar13 %s\n", ar[41]);
	if (!sdl_init_everything(&s))
		ft_error("Failed SDL initialization");

	//printf("PROVERKA %s\n", file_name);

	fill_buffers(&scop, &s);
	run_ui(&s);
	return (0);
}



// void ft_parser(t_gra *o, char *file_name)
// {
// 	int fd;
// 	t_stringview string;
// 	char *line;
// 	int objs;
// 	int vertex_sphere_1;
// 	int flag;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 		ft_error(MES2);
// 	objs = 0;
// 	vertex_sphere_1 = 0;

// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		string = ft_strsplit_inplace(line, ' ');
// 		char **kek = string.tab;
// 		while (*kek)
// 		{
// 			if (!ft_strcmp("o", *kek))
// 			{
// 				flag = 0;
// 				objs++;
// 			}
// 			if (!ft_strcmp("Sphere", *kek))
// 				flag = 1;
// 			if (flag == 1 && !ft_strcmp("v", *kek))
// 				vertex_sphere_1++;

// 			kek++;
// 		}
// 		ft_stringview_destruct(&string);

// 	}
// 	printf("objs = %i\nvertex_sphere_1 = %i\n", objs,vertex_sphere_1);

// 	close(fd);
// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 		ft_error(MES2);
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		string = ft_strsplit_inplace(line, ' ');
// 		char **kek = string.tab;
// //		printf("start of kek\n");

// 		while (*kek)
// 		{
// 				printf("%s\n", *kek);
// 			kek++;
// 		}
// //		printf("endin of kek\n");
// 		ft_stringview_destruct(&string);

// 	}
// 	close(fd);
// }