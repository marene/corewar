/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libimage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:16:59 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 15:17:00 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIMAGE_H
# define LIBIMAGE_H

# include <mlx.h>
# include "libft.h"

# ifndef FT_MLX_PTR
#  include "ft_mlx.h"
# endif

# ifndef NO_GLOBAL

#  define MLX_PTR g_mlx_ptr

# endif
# ifdef NO_GLOBAL

#  define MLX_PTR (*(mlx_ptr_singelton__()))

void				**mlx_ptr_singelton__(void);

# endif

# ifndef ABS
#  define ABS(X) ((X) > 0 ? (X) : -(X))
# endif

# define SET_T_COLOR(c, r, g, b) (c.red = r, c.green = g, c.blue = b)
# define IMG_PIXEL_PUT(S, C, X ,Y) (((t_surface *)(S))->pix[(Y)][(X)] = (C))

# define C_BLUE(X) ((X) & 0xff)
# define C_GREEN(X) (((X) & 0xff00) >> 8)
# define C_RED(X) (((X) & 0xff0000) >> 16)

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_cpoint
{
	int				x;
	int				y;
	unsigned int	color;
}					t_cpoint;

typedef t_point		t_line[2];
typedef t_cpoint	t_cline[2];

typedef struct		s_vect
{
	t_line			line;
	double			x;
	double			y;
	int				iter;
}					t_vect;

typedef struct		s_cvect
{
	t_cline			line;
	double			x;
	double			y;
	t_color			color;
	int				iter;
}					t_cvect;

typedef struct		s_surface
{
	int				h;
	int				w;
	void			*img;
	unsigned int	**pix;
}					t_surface;

typedef struct		s_win
{
	t_surface		screen;
	void			*win_ptr;
}					t_win;

int					img_init(void);

t_cvect				getcvect(t_cpoint p1, t_cpoint p2);
t_vect				getvect(t_point p1, t_point p2);

void				img_delsurface(t_surface *surface);
void				img_delwin(t_win *win);

t_win				*img_newwin(int w, int h, const char *name);
t_surface			*img_newsurface(int w, int h);
void				img_pixel_put(void *surface
						, unsigned int color, int x, int y);

t_cpoint			setcpoint(int x, int y, unsigned int color);
t_point				setpoint(int x, int y);

void				set_cline(t_cline line, t_cpoint p1, t_cpoint p2);
void				set_line(t_line line, t_point p1, t_point p2);

void				img_drawcline(void *surface, t_cpoint p1, t_cpoint p2);
void				img_drawctriangle(void *surface, t_cpoint p1
						, t_cpoint p2, t_cpoint p3);

int					img_win_put(t_win *win);

#endif
