/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 07:56:12 by arigonza          #+#    #+#             */
/*   Updated: 2023/07/16 17:24:02 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

# include "lib/libft/includes/libft.h"
# include "lib/libft/includes/get_next_line.h"
# include "lib/libft/includes/ft_printf.h"
# include "lib/minilibx-linux/mlx.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_point
{
    int			x;
    int			y;
    int			z;
    int			color;
}				t_point;

typedef struct	s_map
{
    t_point		**points;
    int			width;
    int			height;
    int			z_min;
    int			z_max;
    int			z_range;
}				t_map;

typedef struct	s_mlx
{
    void		*mlx;
    void		*win;
    void		*img;
    char		*data_addr;
    int			bits_per_pixel;
    int			size_line;
    int			endian;
}				t_mlx;

# endif