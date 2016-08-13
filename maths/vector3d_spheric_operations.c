#include "ft_vector.h"

double			spherical_theta(t_vec3d *vector)
{
	return (acos(ft_clamp(vector->z, -1, 1)));
}

double			spherical_phi(t_vec3d *vector)
{
	double		phi;

	phi = atan2(vector->y, vector->x);
	return (phi < 0 ? phi + 2 * M_PI : phi);
}
