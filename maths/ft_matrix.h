#ifndef FT_MATRIX_H
#define FT_MATRIX_H
# include "ft_string.h"
# include <stdlib.h>

typedef struct s_matrix
{
	size_t		row_length;
	size_t		colum_length;
	double		**mem;
}				t_matrix;

t_matrix		*alloc_matrix(size_t row_length, size_t colum_length);
t_matrix		*dup_matrix(t_matrix *src);
void			del_matrix(t_matrix *matrix);
t_matrix		*cross_matrix(t_matrix *a, t_matrix *b);
#endif
