#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"

typedef struct	s_envs
{
	double		max_circles;
	double		circles;
	double		y_m;
	int			jmouse;
	double		x4;
	double		y4;
	int			e;
	double		x3;
	double		x2;
	int			slines;
	double		closer;
	double		temp;
	int			fract;
	double		y1;
	void		*win;
	double		x;
	void		*mlx;
	double		y;
	double		y2;
	int			color;
	double		x1;
	int			bppixel;
	void		*img_ptr;
	double		y3;
	void		*img;
    int         color_value;
}				t_envs;

int				error();
int				button(int button, t_envs *f);
void			sometext(t_envs *f);
int				mouse_env(int mousecode, int i, int j, t_envs *f);
void			mandelbrot_envs(t_envs *f);
int				mouse_julia(int i, int j, t_envs *f);
void			julia_envs(t_envs *f);
void			multimandelbrot(t_envs *f);
void			multijulia(t_envs *f);
void			putpixel(t_envs *f, int i, int j, int color);
void			multithreading(t_envs *f);
void			the_chosen_one(t_envs *f);
void            burningship_envs(t_envs *f);
void            multiburningship(t_envs *f);

#endif
