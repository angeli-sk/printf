/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_p.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 16:51:55 by akramp         #+#    #+#                */
/*   Updated: 2020/02/21 19:59:00 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printnum_p(t_printf *t_s, unsigned long n, int p_w)
{
	write(1, "0x", 2);
	t_s->ret = t_s->ret + 2;
	if (t_s->precision != 0)
	{
		p_w = p_w - t_s->numlen;
		while (p_w > 0)
		{
			write(1, "0", 1);
			t_s->ret++;
			p_w--;
		}
	}
	if (t_s->prec_w == 0 && n == 0 && t_s->precision != 0)
		return ;
	putnbrbase(n, 1, 16, t_s);
}

static void	numlen_p(t_printf *t_s, unsigned long n)
{
	if (n == 0 && (t_s->prec_w != 0 || t_s->precision == 0))
		t_s->numlen = 1;
	while (n >= 16)
	{
		n = n / 16;
		t_s->numlen++;
	}
	if (n != 0)
		t_s->numlen++;
}

void		sp_p_else(t_printf *t_s, unsigned long n, int w, int p_w)
{
	t_s->numlen = t_s->numlen + 2;
	if (t_s->precision != 0 && t_s->prec_w != 0 && p_w > 2)
		w = w - 2;
	if (p_w == 2 && t_s->numlen == 3)
		w = w - 1;
	printspace(t_s, w, p_w);
	t_s->numlen = t_s->numlen - 2;
	printnum_p(t_s, n, p_w);
}

void		sp_p(t_printf *t_s, unsigned long n)
{
	int w;
	int	p_w;
	int i;

	w = t_s->width;
	p_w = (int)t_s->prec_w;
	i = 0;
	numlen_p(t_s, n);
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		printnum_p(t_s, n, p_w);
		t_s->numlen = t_s->numlen + 2;
		if (t_s->precision != 0 && t_s->prec_w != 0 && p_w > 2)
			w = w - 2;
		printspace(t_s, w, p_w);
	}
	else
		sp_p_else(t_s, n, w, p_w);
}
