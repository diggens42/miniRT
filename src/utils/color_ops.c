/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:42:04 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 19:21:33 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_rgb	new_rgb(double r, double g, double b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_rgb	rgb_add(t_rgb color_a, t_rgb color_b)
{
	return (new_rgb(color_a.r + color_b.r,
			color_a.g + color_b.g,
			color_a.b + color_b.b));
}

t_rgb	rgb_subtract(t_rgb color_a, t_rgb color_b)
{
	return (new_rgb(color_a.r - color_b.r,
			color_a.g - color_b.g,
			color_a.b - color_b.b));
}

t_rgb	rgb_multiply(t_rgb color_a, double scalar)
{
	return (new_rgb(color_a.r * scalar,
			color_a.g * scalar,
			color_a.b * scalar));
}

t_rgb	rgb_hadamard(t_rgb color_a, t_rgb color_b)
{
	return (new_rgb(color_a.r * color_b.r,
			color_a.g * color_b.g,
			color_a.b * color_b.b));
}
