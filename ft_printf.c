/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 14:30:55 by akramp         #+#    #+#                */
/*   Updated: 2020/02/17 09:50:30 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_struct_fill(t_printf *t_s, char *s, int i, va_list argp)
{
	i = ft_check_flag(t_s, s, i);
	i = ft_check_width(t_s, s, i, argp);
	i = ft_check_prec(t_s, s, i, argp);
	i = ft_check_specifier(t_s, s, i);
	return (i);
}

static void	ft_clear_struct(t_printf *t_s)
{
	t_s->flags[0] = 0;
	t_s->flags[1] = 0;
	t_s->precision = 0;
	t_s->specifier = 0;
	t_s->width = 0;
	t_s->prec_w = 0;
	t_s->negative = 1;
	t_s->numlen = 0;
}

static void	ft_specifier(t_printf *t_s, va_list argp)
{
	if (t_s->specifier == 'c')
		sp_c(t_s, va_arg(argp, int));
	if (t_s->specifier == 's')
		sp_s(t_s, va_arg(argp, unsigned char *));
	if (t_s->specifier == 'p')
		sp_p(t_s, va_arg(argp, unsigned long));
	if (t_s->specifier == 'd' || t_s->specifier == 'i')
		sp_d_i(t_s, va_arg(argp, int));
	if (t_s->specifier == 'u')
		sp_u(t_s, va_arg(argp, unsigned int));
	if (t_s->specifier == 'x')
		sp_x(t_s, va_arg(argp, unsigned int));
	if (t_s->specifier == 'X')
		sp_x(t_s, va_arg(argp, unsigned int));
	if (t_s->specifier == '%')
		sp_c(t_s, '%');
}

int			ft_printf(const char *s, ...)
{
	t_printf	t_s;
	int			i;
	va_list		argp;

	i = 0;
	va_start(argp, s);
	t_s.ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_clear_struct(&t_s);
			i = ft_struct_fill(&t_s, (char *)s, i, argp);
			ft_specifier(&t_s, argp);
		}
		else
		{
			write(1, &s[i], 1);
			t_s.ret++;
			i++;
		}
	}
	va_end(argp);
	return (t_s.ret);
}
