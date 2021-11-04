/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_fill.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 15:11:16 by akramp         #+#    #+#                */
/*   Updated: 2020/02/20 12:00:37 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ngtv(t_printf *t_s, int n)
{
	if (n == -2147483648)
	{
		n = 214748364;
		t_s->negative = -2;
	}
	if (n < 0)
	{
		t_s->negative = -1;
		n = n * -1;
	}
	return (n);
}

int		ft_check_flag(t_printf *t_s, char *s, int i)
{
	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			t_s->flags[0] = (int)s[i];
		if (s[i] == '-')
			t_s->flags[1] = (int)s[i];
		i++;
	}
	return (i);
}

int		ft_check_prec(t_printf *t_s, char *s, int i, va_list argp)
{
	int tempp;

	tempp = 0;
	if (s[i] == '.')
	{
		i++;
		t_s->precision = '.';
		while (s[i] >= '0' && s[i] <= '9')
		{
			t_s->prec_w = (t_s->prec_w * 10) + (s[i] - '0');
			i++;
		}
		if (s[i] == '*')
		{
			t_s->prec_w = va_arg(argp, int);
			tempp = t_s->prec_w;
			if (tempp < 0)
			{
				t_s->prec_w = 0;
				t_s->precision = 0;
			}
			i++;
		}
	}
	return (i);
}

int		ft_check_width(t_printf *t_s, char *s, int i, va_list argp)
{
	int tempw;

	tempw = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		t_s->width = t_s->width * 10;
		t_s->width = t_s->width + (s[i] - '0');
		i++;
	}
	if (s[i] == '*')
	{
		t_s->width = va_arg(argp, int);
		tempw = t_s->width;
		if (tempw < 0)
		{
			t_s->flags[1] = '-';
			t_s->width = (t_s->width * -1);
		}
		i++;
	}
	return (i);
}

int		ft_check_specifier(t_printf *t_s, char *s, int i)
{
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' || s[i] == 'i'
		|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == '%')
	{
		t_s->specifier = s[i];
		i++;
	}
	return (i);
}
