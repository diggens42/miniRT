/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:04:50 by mtravez           #+#    #+#             */
/*   Updated: 2026/05/28 17:43:24 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int     check_type(char *file)
{
    char    *typ;
    
    typ = ".rt";
    if (ft_strrchr(file, '.') && ft_strncmp(ft_strrchr(file, '.'), typ, ft_strlen(typ) + 1))
    {
        return (1);
    }
    return (0);
}

void    init_rt(t_rt *rt)
{
    rt->alight = malloc(sizeof(t_alight) + 1);
}

t_rt    *parse(char *file)
{
    int     fd;
    char    *line;
    char    **args;
    int i;
    t_rt    *rt;
    
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    
    while (line)
    {
        args = ft_strtrim(line, " ");
        i = 0;
        while (i < ft_strarray_len(args))
        {
            
        }
    }
}

t_rt    *parse_line(char **args)
{
    
}

