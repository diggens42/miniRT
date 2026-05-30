/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:56:35 by mtravez           #+#    #+#             */
/*   Updated: 2026/05/30 19:48:55 by mtravez          ###   ########.fr       */
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
	rt->alight.rgb = (t_rgb){255, 255, 255};
		
	rt->cam.coor = (t_tuple){-50.0, 0.0, 20.0, 1.0};
	rt->cam.vec = (t_tuple){0.0, 0.0, 1.0, 0.0};
	rt->cam.fov = 70.0;
		
	rt->light.coor = (t_tuple) {-40.0, 0.0, 30.0, 1.0};
	rt->light.lb_ratio = 0.7;
	rt->light.rgb = (t_rgb){255, 255, 255};

	t_shape *shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return;
	shape->coor = (t_tuple){0.0, 0.0, 0.0, 1.0};
	shape->vec = (t_tuple) {0.0, 1.0, 0.0, 0.0};	
	shape->rgb = (t_rgb){255, 0, 255};
	
	shape->diameter = 0.0;
	shape->height = 0.0;
	shape->s_type = PLANE;
	
	t_list *head = ft_lstnew(shape);
	rt->shapes = head;
	t_shape *sphere;
	sphere = malloc(sizeof(t_shape));
	if (!sphere)
		return;
	sphere->coor = (t_tuple){0.0, 0.0, 20.0, 1.0};
	sphere->vec = (t_tuple) {0.0, 0.0, 0.0, 0.0};
	sphere->rgb = (t_rgb) {255, 0, 0};
	
	sphere->diameter = 20.0;
	sphere->height = 0.0;
	sphere->s_type = SPHERE;
	
	ft_lstadd_back(&head, ft_lstnew(sphere));
	t_shape *cylinder;
	cylinder = malloc(sizeof(t_shape));
	if (!cylinder)
		return;
	cylinder->coor = (t_tuple){50.0, 0.0, 20.6, 1.0};
	cylinder->vec = (t_tuple){0.0, 0.0, 1.0, 0.0};
	cylinder->rgb = (t_rgb){10, 0, 255};
	
	cylinder->diameter = 14.2;
	cylinder->height = 21.42;
	cylinder->s_type = CYLINDER;
	
	ft_lstadd_back(&head, ft_lstnew(cylinder));
}
