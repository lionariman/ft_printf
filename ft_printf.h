#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>// PRINTF
# include <unistd.h>
# include "libft/libft.h"

typedef struct	the_list
{
	int			type;
	int			width;
	int			dot;
	int			precison;
	int			minus;
	int			zero;
}				new_list;

int			ft_printf(const char *string, ...);
char		*ft_parser(char *format, va_list argptr, new_list *list);
char		*ft_flag_num(char *s, new_list *list);
char		*ft_flag_dot(char *s, va_list argptr, new_list *list);
char		*ft_flag_minus(char *s, new_list *list);
new_list	list_flag_type(void);
int			ft_processor(char *s, va_list argptr, new_list *list);
int			ft_char_type(va_list argptr, new_list *list);
int			ft_dec_type(va_list argptr, new_list *list);
int			ft_istype(char *c);

#endif