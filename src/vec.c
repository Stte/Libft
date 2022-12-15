/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:48:37 by tspoof            #+#    #+#             */
/*   Updated: 2022/12/14 23:58:18 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

// Appends src memory to end of dst memory.
// Resizes the dst memory if needed.
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	alloc_size_min;
	int		ret;

	if (!dst || !src)
		return (-1);
	ret = 1;
	alloc_size_min = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size * 2 < alloc_size_min)
		ret = vec_resize(dst, dst->len + src->len);
	else if (dst->alloc_size < alloc_size_min)
		ret = vec_resize(dst, dst->len * 2);
	if (ret == -1)
		return (-1);
	ft_memcpy(&dst->memory[dst->elem_size*dst->len],
			src->memory,
			src->len * src->alloc_size);
	dst->len = dst->len + src->len;
	return (1);
}

void	vec_free(t_vec *src)
{
	if (!src || src->alloc_size == 0)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->elem_size = 0;
	src->alloc_size = 0;
	src->len = 0;
}

int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || !len || !elem_size)
		return (-1);
	if (!vec_new(dst, len, elem_size))
		return (-1);
	ft_memcpy(dst->memory, src, dst->alloc_size);
	dst->len = len;
	return (1);
}

// Allocates init_len * elem_size bytes of memory to dst *memory.
int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if (!dst || elem_size == 0)
		return (-1);
	dst->elem_size = elem_size;
	dst->alloc_size = elem_size * init_len;
	dst->len = 0;
	if (dst->alloc_size == 0)
		return (-1);
	dst->memory = malloc(dst->alloc_size);
	if(!dst->memory)
		return (-1);
	return (1);
}
// Takes in a vector and a pointer to an element
// to be pushed to the end of the vector.
int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	if (dst->len * dst->elem_size + dst->elem_size > dst->alloc_size)
		if(!vec_resize(dst, dst->len * 2))
			return (-1);
	ft_memcpy(&dst->memory[dst->len * dst->elem_size], src, dst->elem_size);
	dst->len++;
	return (1);
}

// Allocates target_len * elem_size amout of memory and copies memory from the
// src to that
int	vec_resize(t_vec *src, size_t target_len)
{
	t_vec	dst;

	if (!src || !target_len)
		return (-1);
	vec_new(&dst, target_len, src->elem_size);
	if (!dst.memory)
		return (-1);
	ft_memcpy(dst.memory, src->memory, src->len * src->elem_size);
	dst.len = src->len;
	vec_free(src);
	*src = dst;
	return (1);
}
