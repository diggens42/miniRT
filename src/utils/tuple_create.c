/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:31:25 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 16:56:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_tuple	new_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;
	
	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;

	return (tuple);
}

t_tuple	new_point(double x, double y, double z)
{
	return (new_tuple(x, y, z, 1.0));
}

t_tuple	new_vector(double x, double y, double z)
{
	return (new_tuple(x, y, z, 0.0));
}
