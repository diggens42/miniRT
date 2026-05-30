/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_vec_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:05:19 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 18:04:14 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/** returns len of vec 
 *  sqrt(x² + y² + z² + w²) */
double	magnitude(t_tuple vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y
			+ vec.z * vec.z + vec.w * vec.w));
}

/** returns vec scaled to len = 1 (unit vec, same direction) */
t_tuple	normalize(t_tuple vec)
{
	double	mag;

	mag = magnitude(vec);
	return (new_tuple(vec.x / mag, vec.y / mag, vec.z / mag, vec.w / mag));
}

/** dot product - measures alignment between two vecs
 *  > 0 same direction
 *  < 0 opposite direction
 *    0 perpendicular */
double	dot(t_tuple vec_a, t_tuple vec_b)
{
	return (vec_a.x * vec_b.x + vec_a.y * vec_b.y
		+ vec_a.z * vec_b.z + vec_a.w * vec_b.w);
}

/** cross product - returns vec perpendicular to both inputs (right-hand rule) */
t_tuple	cross(t_tuple vec_a, t_tuple vec_b)
{
	return (new_vec(vec_a.y * vec_b.z - vec_a.z * vec_b.y,
			vec_a.z * vec_b.x - vec_a.x * vec_b.z,
			vec_a.x * vec_b.y - vec_a.y * vec_b.x));
}
