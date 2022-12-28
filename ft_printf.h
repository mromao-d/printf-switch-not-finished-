#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_print                       
{                        
	va_list	args;		/*  arg to print out */
	int	wdt;			/* width */
	int	prc;			/* precision */
	int	zero;			/* zero padding */
	int	pnt;			/* . */
	int	dash;			/* - */
	int	sign;			/* pos or neg number */
	int	tl;				/* total_length (return value) */
	int	is_zero;		/* is number zero */
	int	perc;			/* % */
	int	sp;				/* space flag ' ' */
}    t_print;
#endif