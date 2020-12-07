#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
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
int			ft_istype(char *c);

int			ft_dec_type(va_list argptr, new_list *list);
int			ft_width(int j, int len, new_list *list);
int			ft_prec(int j, int len, new_list *list);
int			ft_dec_neg(int j, int len, new_list *list, int elem);
int			ft_with_len(int j);

int			ft_one(int j, int len, new_list *list);
int			ft_two(int j, int len, new_list *list);
int			ft_dec_0_0(int j, int len, new_list *list);
int			ft_dec_0_1(int j, int len, new_list *list);
int			ft_dec_0_2(int j, int len, new_list *list);
int			ft_dec_1_0(int j, int len, new_list *list);
int			ft_dec_1_1(int j, int len, new_list *list);
int			ft_dec_1_2(int j, int len, new_list *list);

int			ft_str_type(va_list argptr, new_list *list);

#endif