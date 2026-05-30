/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_vector_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:05:19 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 17:22:17 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

double	magnitude(t_tuple vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y 
		+ vec.z * vec.z + vec.w * vec.w));
}

t_tuple	normalize(t_tuple vec)
{
	double	mag;

	mag = magnitude(vec);
	return (new_tuple(vec.x / mag, vec.y / mag, vec.z / mag, vec.w / mag));
}

double	dot(t_tuple vec_a, t_tuple vec_b)
{
	return (vec_a.x * vec_b.x + vec_a.y * vec_b.y
		+ vec_a.z * vec_b.z + vec_a.w * vec_b.w);
}

t_tuple	cross(t_tuple vec_a, t_tuple vec_b)
{
	return (new_vec(vec_a.y * vec_b.z - vec_a.z * vec_b.y,
				vec_a.z * vec_b.x - vec_a.x * vec_b.z,
				vec_a.x * vec_b.y - vec_a.y * vec_b.x));
}