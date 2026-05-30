/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:25 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 17:57:47 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//** creates tuple (w = 1 is point, w = 0 is vec) */
t_tuple	new_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

/** creates point (w = 1.0) for coordinates */
t_tuple	new_point(double x, double y, double z)
{
	return (new_tuple(x, y, z, 1.0));
}

/** creates vector (w = 0.0) for directions */
t_tuple	new_vec(double x, double y, double z)
{
	return (new_tuple(x, y, z, 0.0));
}
