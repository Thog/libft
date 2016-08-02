#include "ft_vector.h"

t_vec3d			*alloc_vec3d(void)
{
	return (ft_memalloc(sizeof(t_vec3d)));
}

t_vec3d			*new_vec3d(double x, double y, double z)
{
	t_vec3d	*res;

	if ((res = alloc_vec3d()))
	{
		res->x = x;
		res->y = y;
		res->z = z;
	}
	return (res);
}

t_vec3d			*dup_vec3d(t_vec3d *src)
{
	t_vec3d	*res;

	res = NULL;
	if (src)
		res = new_vec3d(src->x, src->y, src->z);
	return (res);
}

t_vec3d			*normalize_vec3d(t_vec3d *src)
{
	double	len;
	double	len_invert;

	len = dot_vec3d(src, src);
	if (len > 0)
	{
		len_invert = 1 / sqrt(len);
		src->x *= len_invert;
		src->y *= len_invert;
		src->z *= len_invert;
	}
	return (src);
}
