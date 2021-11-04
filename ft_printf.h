/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 14:33:51 by akramp         #+#    #+#                */
/*   Updated: 2020/02/20 12:23:54 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_printf
{
	int				flags[2];
	unsigned int	width;
	int				precision;
	unsigned int	prec_w;
	int				numlen;
	int				specifier;
	int				negative;
	int				ret;
}					t_printf;

int					ft_printf(const char *s, ...);
int					ft_check_specifier(t_printf	*t_s, char *s, int i);
int					ft_check_width(t_printf	*t_s, char *s, int i, va_list argp);
int					ft_check_prec(t_printf	*t_s, char *s, int i, va_list argp);
int					ft_check_flag(t_printf	*t_s, char *s, int i);
int					ft_ngtv(t_printf *t_s, int n);
void				printspace(t_printf	*t_s, int w, int p_w);
int					flagcheck(t_printf *t_s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				putnbrbase(unsigned long n, int fd, int bse, t_printf *t_s);
void				ft_unsignedputnbr_fd(unsigned int n, int fd, t_printf *t_s);
size_t				ft_strlen(const char *str);
void				ft_putchar_fd(char c, int fd, t_printf *t_s);
int					ft_atoi(const char *str);
void				sp_d_i(t_printf	*t_s, int n);
void				sp_u(t_printf *t_s, unsigned int n);
void				sp_c(t_printf *t_s, char c);
void				sp_s(t_printf *t_s, unsigned char *n);
void				sp_p(t_printf *t_s, unsigned long n);
void				sp_x(t_printf *t_s, unsigned int n);

#endif
