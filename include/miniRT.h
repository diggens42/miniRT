/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:06:41 by mtravez           #+#    #+#             */
/*   Updated: 2026/05/30 18:12:22 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h> // sinc, cos, sqrt
# include <stdio.h> // printf, perror
# include <string.h> // strerror
# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // open, close, read, write
# include <fcntl.h> // open, close, read, write
# include <sys/time.h> // gettimeofday
# define WIN_H 750
# define WIN_W 1024

typedef enum e_shape_type {
	SPHERE,
	CYLINDER,
	PLANE
}	t_shape_type;

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

typedef struct s_alight {
	double	ratio;
	t_rgb	rgb;
}	t_alight;

typedef struct	s_camera {
	t_tuple	coor;	// x, y, z coordinates of the viewpoint
	t_tuple	vec;	// 3D normalized orientation vector, in the range [-1,1] for each x, y, z axis
	double	fov;	// Field of view
}	t_camera;

typedef struct s_light
{
	t_tuple	coor;
	double	lb_ratio;
	t_rgb	rgb;
}	t_light;

typedef struct s_shape
{
	t_shape_type	s_type;
	t_tuple			coor;
	t_tuple			vect;
	t_rgb			rgb;
	double			diameter;
	double			height;
}	t_shape;

typedef struct s_rt {
	t_alight	alight;
	t_light		light;
	t_camera	cam;
	t_list		*shapes;
}	t_rt;

// functions

// utils/tuple_create.c
t_tuple	new_tuple(double x, double y, double z, double w);
t_tuple	new_point(double x, double y, double z);
t_tuple	new_vec(double x, double y, double z);

// utils/tuple_arithmetics.c
t_tuple	add(t_tuple a, t_tuple b);
t_tuple	subtract(t_tuple a, t_tuple b);
t_tuple	negate(t_tuple a);
t_tuple	multiply(t_tuple a, double scalar);
t_tuple	divide(t_tuple a, double scalar);

//utils/tuple_vec_ops.c
double	magnitude(t_tuple vec);
t_tuple	normalize(t_tuple vec);
double	dot(t_tuple vec_a, t_tuple vec_b);
t_tuple	cross(t_tuple vec_a, t_tuple vec_b);

void	hardcode_data(t_rt *rt);
void	free_shape_lst(t_rt *rt);


#endif