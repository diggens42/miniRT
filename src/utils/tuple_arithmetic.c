/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:55:47 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 17:51:38 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/** add two tuples
 *  point + vec = point
 *  vec + vec   = vec */
t_tuple	add(t_tuple a, t_tuple b)
{
	return (new_tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

/** subtract two tuples
 *  point - point = vec
 *  point - vec   = point */
t_tuple	subtract(t_tuple a, t_tuple b)
{
	return (new_tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

/** negate tuple (flips direction) */
t_tuple	negate(t_tuple a)
{
	return (new_tuple(-a.x, -a.y, -a.z, -a.w));
}

/** scales tuple with scalar */
t_tuple	multiply(t_tuple a, double scalar)
{
	return (new_tuple(a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar));
}

/** divides tuple with scalar */
t_tuple	divide(t_tuple a, double scalar)
{
	return (multiply(a, 1.0 / scalar));
}
