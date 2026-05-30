/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:55:47 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 17:26:26 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_tuple	add(t_tuple a, t_tuple b)
{
	return (new_tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	return (new_tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

t_tuple	negate(t_tuple a)
{
	return (new_tuple(-a.x, -a.y, -a.z, -a.w));
}

t_tuple	multiply(t_tuple a, double scalar)
{
	return (new_tuple(a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar));
}

t_tuple	divide(t_tuple a, double scalar)
{
	return (multiply(a, 1.0 / scalar));
}