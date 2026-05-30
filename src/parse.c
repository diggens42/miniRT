/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:56:35 by mtravez           #+#    #+#             */
/*   Updated: 2026/05/30 18:08:33 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	 check_type(char *file)
{
	char	*typ;
		
	typ = ".rt";
	if (ft_strrchr(file, '.') && ft_strncmp(ft_strrchr(file, '.'), typ, ft_strlen(typ) + 1))
	{
		return (1);
	}
	return (0);
}

// void	init_rt(t_rt *rt)
// {
// 	 rt->alight = malloc(sizeof(t_alight) + 1);
// }

// t_rt	*parse(char *file)
// {
// 	 int	 fd;
// 	 char	*line;
// 	 char	**args;
// 	 int i;
// 	 t_rt	*rt;
		
// 	 fd = open(file, O_RDONLY);
// 	 line = get_next_line(fd);
		
// 	 while (line)
// 	 {
// 		 args = ft_strtrim(line, " ");
// 		 i = 0;
// 		 while (i < ft_strarray_len(args))
// 		 {
			
// 		 }
// 	 }
// }

// t_rt	*parse_line(char **args)
// {
		
// }

void	free_shape(void *shape)
{
	if (!shape)
		return;
	free(shape);
}

void	free_shape_lst(t_rt *rt)
{
	ft_lstclear(&rt->shapes, &free_shape);
}

void	hardcode_data(t_rt *rt) {	
	rt->alight.ratio = 0.2;
	rt->alight.rgb.r = 255;
	rt->alight.rgb.g = 255;
	rt->alight.rgb.b = 255;
		
	rt->cam.coor.x = -50.0;
	rt->cam.coor.y = 0.0;
	rt->cam.coor.z = 20.0;
	rt->cam.coor.w = 1.0;
	rt->cam.vect.x = 0.0;
	rt->cam.vect.y = 0.0;
	rt->cam.vect.z = 1.0;
	rt->cam.vect.w = 0.0;
	rt->cam.fov = 70.0;
		
	rt->light.coor.x = -40.0;
	rt->light.coor.y = 0.0;
	rt->light.coor.z = 30.0;
	rt->light.coor.w = 1.0;
	rt->light.lb_ratio = 0.7;
	rt->light.rgb.r = 255;
	rt->light.rgb.g = 255;
	rt->light.rgb.b = 255;

	t_shape *shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return;
	shape->coor.x = 0.0;
	shape->coor.y = 0.0;
	shape->coor.z = 0.0;
	shape->coor.w = 1.0;

	shape->vect.x = 0.0;
	shape->vect.y = 1.0;
	shape->vect.z = 0.0;
	shape->vect.w = 0.0;
		
	shape->rgb.r = 255;
	shape->rgb.g = 0;
	shape->rgb.b = 255;
	
	shape->diameter = 0.0;
	shape->height = 0.0;
	shape->s_type = PLANE;
	
	t_list *head = ft_lstnew(shape);
	rt->shapes = head;
	t_shape *sphere;
	sphere = malloc(sizeof(t_shape));
	if (!sphere)
		return;
	sphere->coor.x = 0.0;
	sphere->coor.y = 0.0;
	sphere->coor.z = 20.0;
	sphere->coor.w = 1.0;

	sphere->vect.x = 0.0;
	sphere->vect.y = 0.0;
	sphere->vect.z = 0.0;
	sphere->vect.w = 0.0;
	
	sphere->rgb.r = 255;
	sphere->rgb.g = 0;
	sphere->rgb.b = 0;
	
	sphere->diameter = 20.0;
	sphere->height = 0.0;
	sphere->s_type = SPHERE;
	
	ft_lstadd_back(&head, ft_lstnew(sphere));
	t_shape *cylinder;
	cylinder = malloc(sizeof(t_shape));
	if (!cylinder)
		return;
	cylinder->coor.x = 50.0;
	cylinder->coor.y = 0.0;
	cylinder->coor.z = 20.6;
	cylinder->coor.w = 1.0;

	cylinder->vect.x = 0.0;
	cylinder->vect.y = 0.0;
	cylinder->vect.z = 1.0;
	cylinder->vect.w = 0.0;
	
	cylinder->rgb.r = 10;
	cylinder->rgb.g = 0;
	cylinder->rgb.b = 255;
	
	cylinder->diameter = 14.2;
	cylinder->height = 21.42;
	cylinder->s_type = CYLINDER;
	
	ft_lstadd_back(&head, ft_lstnew(cylinder));
}
