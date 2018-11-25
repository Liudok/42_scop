
#include "../include/scop.h"

float ft_atof(const char* s)
{
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++)
  {
    if (*s == '.')
	{
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9)
	{
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};

struct s_vertex get_vertex(char* s)
{
struct s_vertex vertex;
float first = ft_atof(s);
char *begin = s;
vertex.vertex[0] = first;
while (*s && (*s == ' ' || *s == '\t'))
	s++;
char *next = ft_strchr(s, ' ');
if (next)
	vertex.vertex[1] = ft_atof(next);
while (*next == ' ' || *next == '\t')
	next++;
next = ft_strchr(next, ' ');
if (next)
	vertex.vertex[2] = ft_atof(next);
//printf("vertex  = %f    %f    %f\n", vertex.vertex[0], vertex.vertex[1], vertex.vertex[2]);
s = begin;
return (vertex);
}

void 			get_indices(char* s, t_scop *scop, int *i)
{
	scop->indices[*i].index = ft_atoi(s) - 1;
	++(*i);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	char *next = ft_strchr(s, ' ');
	if (next)
		scop->indices[*i].index = ft_atoi(next) - 1;
	++(*i);
	while (*next == ' ' || *next == '\t')
	next++;
	next = ft_strchr(next, ' ');
	if (next)
		scop->indices[*i].index = ft_atoi(next) - 1;
	printf("index  = %i    %i   %i\n", scop->indices[*i - 2].index, scop->indices[*i - 1].index, scop->indices[*i].index);
	next++;
	next = ft_strchr(next, ' ');
	//printf("next  = %s  \n", next);
	
	
	if (next)
	{
		++(*i);
		scop->indices[*i].index = ft_atoi(next);
	printf("index4  = %i  \n", scop->indices[*i].index);
	
	}
	//++(*i);
}

int         get_data(char *file_name, t_scop *scop)
{
	int     fd;
	char	*line;
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error(MES2);
	int i = -1;
	int j = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			scop->vertices[++i] = get_vertex(++line);
		else if (line[0] == 'f' && line[1] == ' ')
			get_indices(++line, scop, &j);
		// if (line)
		// 	free(line);
	}

	close(fd);
	return (0);
}


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
		if (line[0] == 'v' && line[1] == ' ')
			(scop->vertices_amount)++;
		else if (line[0] == 'f' && line[1] == ' ')
			(scop->faces_amount)++;
		(scop->lines)++;
		free(line);
	}

	printf("lines =  %d\n", scop->lines);
	printf("vertex =  %d\n", scop->vertices_amount);
	printf("faces =  %d\n\n ========== \n\n", scop->faces_amount);
	close(fd);
	return (0);
}
