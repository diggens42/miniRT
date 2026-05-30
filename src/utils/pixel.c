/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 19:06:41 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/30 19:21:03 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static double	clamp(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

uint32_t	rgb_to_pixel(t_rgb color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (uint8_t)(clamp(color.r, 0.0, 1.0) * 255);
	g = (uint8_t)(clamp(color.g, 0.0, 1.0) * 255);
	b = (uint8_t)(clamp(color.b, 0.0, 1.0) * 255);
	return (((uint32_t)r << 24)
		| ((uint32_t)g << 16)
		| ((uint32_t)b << 8)
		| 0xFF);
}
