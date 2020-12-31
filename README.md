PRINTF Project

Project Overview

PRINTF is a 42 Project that aims to mimic libc printf function

Basics, requested from subject:

A) parsing for flags, field_width, precision, length_modifier.
B) parsing for conversion specifier.
C) displaying UTF-8 characters. (%C and %S).
D) computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
E) displaying signed numbers (%d %D %i).
F) displaying pointer address (%p).
Bonus:

A) At 140% of libc printf speed thanks to buffer addition and functions' optimization.
B) Handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf).
C) All flags stored on only 14 bits.
D) wildcard_length_modifier (%*) : replaces precision and field_width with parameter in va_list ap.
E) print_len with %n (refer to ft_printf.c : *va_arg(ap, int *) = p->len;).
F) displaying errno with %m.
G) colors with '%s' and then for example PF_BLUE.
H) %f and %F to handle double and float numbers.
I) %a and %A to handle hexadecimal double numbers (rather pointless...).
J) Also returns the string only with ft_sprintf.
