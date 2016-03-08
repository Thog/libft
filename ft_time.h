#ifndef FT_TIME_H
# define FT_TIME_H

#include <time.h>

typedef struct			s_date
{
	char				*raw_data;
	char				*day;
	char				*month;
	char				*day_of_month;
	char				*time;
	char				*year;
}						t_date;

t_date					*ft_date(time_t *time);

#endif
