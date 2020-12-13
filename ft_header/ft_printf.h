#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	the_list
{
	long long int	type;
	int				width;
	int				dot;
	int				precison;
	int				minus;
	int				zero;
	int				hex;
	int				p;
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
int			ft_width(int j, int len, new_list *list);

int			ft_dec_type(va_list argptr, new_list *list, char *s);
int			ft_prec(int j, int len, new_list *list);
int			ft_dec_neg(int j, int len, new_list *list, int elem);
int			ft_with_len(long long int j);
int			ft_one(int j, int len, new_list *list);
int			ft_two(int j, int len, new_list *list);

int			ft_str_type(va_list argptr, new_list *list);
int			ft_write_wid(int j, new_list *list);
int			ft_write_prec(int j, char *str, new_list *list);
int			ft_str_one(int j, int save, char *str, new_list *list);
int			ft_str_two(int j, int save, char *str, new_list *list);

int			ft_hex_type(va_list argptr, new_list *list, char *s);
int			ft_dec_hex_neg(int j, int len, new_list *list, int elem);
int			ft_hex_prec(int j, int len, new_list *list);
int			ft_xputnbr(int xx, int f, int j);
int			ft_hex_one(int j, int len, new_list *list);
int			ft_hex_two(int j, int len, new_list *list);

int			ft_ptr_type(va_list argptr, new_list *list);
int			ft_dec_ptr_neg(int j, int len, new_list *list, int elem);
int			ft_ptr_prec(int j, int len, new_list *list);
int			ft_pputnbr(long long int xx, int f, int j, new_list *list);
int			ft_ptr_one(int j, int len, new_list *list);
int			ft_ptr_two(int j, int len, new_list *list);

int			ft_prc_type(new_list *list);

#endif