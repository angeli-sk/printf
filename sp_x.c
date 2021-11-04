/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_x.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 08:39:01 by akramp         #+#    #+#                */
/*   Updated: 2020/02/17 09:18:19 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printnum_x(t_printf *t_s, unsigned int n, int p_w)
{
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
	if (t_s->negative == -2)
	{
		write(1, "8", 1);
		t_s->ret++;
	}
}

static void	numlen_x(t_printf *t_s, unsigned int n)
{
	if (n == 0 && (t_s->prec_w != 0 || t_s->precision == 0))
		t_s->numlen = 1;
	while (n > 0)
	{
		n = n / 16;
		t_s->numlen++;
	}
}

void		sp_x(t_printf *t_s, unsigned int n)
{
	int w;
	int	p_w;
	int i;

	w = t_s->width;
	p_w = (int)t_s->prec_w;
	i = 0;
	numlen_x(t_s, n);
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		printnum_x(t_s, n, p_w);
		printspace(t_s, w, p_w);
	}
	else
	{
		printspace(t_s, w, p_w);
		printnum_x(t_s, n, p_w);
	}
}
