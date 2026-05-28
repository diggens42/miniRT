/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:06:41 by mtravez           #+#    #+#             */
/*   Updated: 2026/05/28 16:59:39 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# define WIN_H 750
# define WIN_W 1024

typedef enum e_shape {
	SPHERE,
	CYLINDER,
	PLANE
}	t_shape;

typedef struct s_tuple {
	double	x;
	double	y;
	double	z;
	double	w; 
}	t_tuple;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
}	t_coor;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_alight {
	double	ratio;
	t_rgb	*rgb;
}	t_alight;

typedef struct	s_camera {
	t_coor	*coor;	// x, y, z coordinates of the viewpoint
	t_vect	*vect;	// 3D normalized orientation vector, in the range [-1,1] for each x, y, z axis
	double	fov;	// Field of view
}	t_camera;

typedef struct s_light
{
	t_coor	*coor;
	double	lb_ratio;
	t_rgb	*rgb;
}	t_light;

typedef struct s_shape
{
	t_shape	shape;
	t_coor	*coor;
	t_rgb	*rgb;
	double	diameter;
	double	height;
};


#endif