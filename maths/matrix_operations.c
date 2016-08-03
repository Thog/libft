#include "ft_matrix.h"

double			get_matrix_entry(t_matrix *matrix, size_t y, size_t x)
{
	if (matrix && matrix->row_length > x && matrix->colum_length > y)
		return (matrix->mem[y][x]);
	return (0.0D);
}

t_matrix		*cross_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		i;
	size_t		j;
	size_t		k;
	double		sum;

	c = NULL;
	// c = (n x p)
	if (a->colum_length == b->row_length &&
		(c = alloc_matrix(a->row_length, a->colum_length)))
	{
		i = 0;
		// n
		while (i < a->row_length)
		{
			j = 0;
			// p
			while (j < b->colum_length)
			{
				sum = 0;
				k = 0;

				// m
				while (k < a->colum_length)
				{
					sum += get_matrix_entry(a, k, i) *
						get_matrix_entry(b, j, k);
					k++;
				}
				c->mem[j][i] = sum;
				j++;
			}
			i++;
		}
	}
	return (c);
}
