/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:59:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/12/16 09:22:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# include <math.h>
# include <stdio.h>

# ifndef M_PI_2
#  define M_PI	3.14159265358979323846	/* pi */
#  define M_PI_2	1.57079632679489661923	/* pi/2 */
# endif

/* Structures */
typedef struct s_point			t_point;
typedef enum e_axis				t_axis;

enum e_axis
{
	X_AXIS = 11,
	Y_AXIS,
	Z_AXIS
};

struct s_point
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_bbox
{
	t_point			bbmax;
	t_point			bbmin;
	t_point			vertices[8];
}	t_bbox;

/* Conversions */

t_point			vec_to_radian(t_point angle_val);
double			to_radian(double angle);
double			to_degrees(double angle);
void			calculate_angles(t_point vector, t_point *angles);
void			get_polar_angles(
					t_point c, t_point p, double *hangle, double *vangle);
t_point			sphere_point_polar(double vangle, double hangle);

double			remap(double value, double vars[]);
t_point			invert(t_point vector);

/* Point struct functions */
t_point			create_point(double x, double y, double z);
int				vector_compare(t_point vector_1, t_point vector_2);
t_point			mid_point(t_point vector_1, t_point vector_2);

/* Vectors operations */
t_point			reflect_onplane(t_point incident, t_point normal);
t_point			to_first_octant(t_point vector);
t_point			random_bounce(t_point vector);
t_point			random_vector(void);
t_point			vector_multiply(t_point a, double val);
t_point			vectors_divide(t_point a, t_point b);
t_point			vectors_sum(t_point a, t_point b);
t_point			vectors_res(t_point a, t_point b);
t_point			vectors_sum_escalar(t_point a, double val);
t_point			vectors_res_escalar(t_point a, double val);
t_point			cross_product(t_point a, t_point b);
double			dot_product(t_point a, t_point b);
double			norm_dot(t_point a, t_point b);
t_point			cross_product(t_point a, t_point b);
double			vector_length(t_point vector);
t_point			normalize(t_point vector);
double			distance(t_point p1, t_point p2);

/* Double operations */
void			restrict_double(double *var, double val_min, double val_max);
double			max(double array[], int size);
double			min(double array[], int size);

#endif