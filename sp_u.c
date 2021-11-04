/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_u.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 08:19:43 by akramp         #+#    #+#                */
/*   Updated: 2020/02/20 11:54:58 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printspace_u(t_printf *t_s, unsigned int w, unsigned int p_w)
{
	char output;

	output = ' ';
	if (p_w > w || ((unsigned int)t_s->numlen >= w && flagcheck(t_s) == 0)
	|| (p_w < (unsigned int)t_s->numlen && w < (unsigned int)t_s->numlen))
		return ;
	w = w - t_s->numlen;
	if (t_s->width == 0)
		w = 0;
	if (t_s->precision != 0 && p_w > (unsigned int)t_s->numlen)
		w = w - (p_w - t_s->numlen);
	while (w > 0)
	{
		if (flagcheck(t_s) == 2 && t_s->precision == 0)
			output = '0';
		write(1, &output, 1);
		t_s->ret++;
		w--;
	}
}

static void	printnum_u(t_printf *t_s, unsigned int n, unsigned int p_w)
{
	if (t_s->precision != 0 && t_s->numlen <= (int)p_w)
	{
		p_w = p_w - t_s->numlen;
		if (t_s->prec_w == 0)
			p_w = 0;
		while (p_w > 0)
		{
			write(1, "0", 1);
			t_s->ret++;
			p_w--;
		}
	}
	if (t_s->prec_w == 0 && n == 0 && t_s->precision != 0)
		return ;
	ft_unsignedputnbr_fd(n, 1, t_s);
}

static void	numlen_u(t_printf *t_s, unsigned int n)
{
	if (n == 0 && (t_s->prec_w != 0 || t_s->precision == 0))
		t_s->numlen = 1;
	while (n > 0)
	{
		n = n / 10;
		t_s->numlen++;
	}
}

void		sp_u(t_printf *t_s, unsigned int n)
{
	unsigned int w;
	unsigned int p_w;
	unsigned int i;

	w = t_s->width;
	p_w = t_s->prec_w;
	i = 0;
	numlen_u(t_s, n);
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		printnum_u(t_s, n, p_w);
		printspace_u(t_s, w, p_w);
	}
	else
	{
		printspace_u(t_s, w, p_w);
		printnum_u(t_s, n, p_w);
	}
}
