/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <lberezyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:41:18 by lberezyn          #+#    #+#             */
/*   Updated: 2018/10/28 13:41:20 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

int main(int ac, char **av)
{
	t_scop scop;
	if (ac == 1)
	{
		ft_error(MES2);
		exit (0);
	}
	else
		obj_parser(av[1], &scop);
	return (0);
}

void		ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}