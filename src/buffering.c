/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <lberezyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:54:59 by lberezyn          #+#    #+#             */
/*   Updated: 2018/11/25 15:55:08 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void fill_buffers(t_scop *scop, t_sdl *s)
{

}

// void	create_buffers(t_env *env, int mode)
// {
// 	glGenBuffers(1, &env->buffer.vbo);
// 	glGenBuffers(1, &env->buffer.ebo);
// 	glGenVertexArrays(1, &env->buffer.vao);
// 	glBindVertexArray(env->buffer.vao);
// 	glBindBuffer(GL_ARRAY_BUFFER, env->buffer.vbo);
// 	glBufferData(GL_ARRAY_BUFFER, env->model.size_vertices,
// 		env->model.vertices, mode);
// 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->buffer.ebo);
// 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, env->model.size_indices,
// 		env->model.indices, mode);
// 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
// 		(GLvoid*)0);
// 	glEnableVertexAttribArray(0);
// 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
// 		(GLvoid*)(3 * sizeof(GLfloat)));
// 	glEnableVertexAttribArray(1);
// 	create_texture(env);
// }