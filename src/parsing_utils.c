
#include "../include/scop.h"

int count_lines(char *file_name, t_scop *scop)
{
	int fd;
	char	*line;
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error(MES2);

	scop->vertices_amount = 0;
	scop->faces_amount = 0;
	scop->lines = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'v')
			(scop->vertices_amount)++;
		else if (line[0] == 'f')
			(scop->faces_amount)++;
		(scop->lines)++;
		free(line);
	}

	printf("lines =  %d\n", scop->lines);
	printf("vertex =  %d\n", scop->vertices_amount);
	printf("faces =  %d\n", scop->faces_amount);
	close(fd);
	return (0);
}

int get_data(char *file_name, t_scop *scop)
{
	int fd;
	char	*line;
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error(MES2);

	scop->vertices_amount = 0;
	scop->faces_amount = 0;
	scop->lines = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'v')
			(scop->vertices_amount)++;
		else if (line[0] == 'f')
			(scop->faces_amount)++;
		(scop->lines)++;
		free(line);
	}

	printf("lines =  %d\n", scop->lines);
	printf("vertex =  %d\n", scop->vertices_amount);
	printf("faces =  %d\n", scop->faces_amount);
	close(fd);
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