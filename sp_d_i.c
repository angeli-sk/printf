/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_d_i.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 15:11:50 by akramp         #+#    #+#                */
/*   Updated: 2020/02/20 13:22:09 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flagcheck(t_printf *t_s)
{
	int x;
	int pcheck;

	x = 0;
	pcheck = 0;
	while (x < 2)
	{
		if (t_s->flags[x] == '-')
			pcheck = 1;
		if (t_s->flags[x] == '0')
			pcheck = 2;
		x++;
	}
	return (pcheck);
}

void		printspace(t_printf *t_s, int w, int p_w)
{
	char output;

	output = ' ';
	if (p_w > w || (t_s->numlen >= w && flagcheck(t_s) == 0))
		return ;
	w = w - t_s->numlen;
	if (t_s->precision != 0 && p_w > t_s->numlen)
		w = w - (p_w - t_s->numlen);
	if (t_s->negative < 0)
		w--;
	if (w < 0)
		w = 0;
	while (w > 0)
	{
		if (flagcheck(t_s) == 2 && t_s->precision == 0)
			output = '0';
		write(1, &output, 1);
		t_s->ret++;
		w--;
	}
}

static void	printnum(t_printf *t_s, int n, int p_w)
{
	if (t_s->negative < 0 && (flagcheck(t_s) != 2 || t_s->precision != 0))
	{
		write(1, "-", 1);
		t_s->ret++;
	}
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
	ft_unsignedputnbr_fd(n, 1, t_s);
	if (t_s->negative == -2)
	{
		write(1, "8", 1);
		t_s->ret++;
	}
}

static void	numlen(t_printf *t_s, int n)
{
	if ((n == 0 && (t_s->prec_w != 0 || t_s->precision == 0))
		|| t_s->negative == -2)
		t_s->numlen = 1;
	while (n > 0)
	{
		n = n / 10;
		t_s->numlen++;
	}
}

void		sp_d_i(t_printf *t_s, int n)
{
	int w;
	int	p_w;
	int i;

	w = t_s->width;
	p_w = (int)t_s->prec_w;
	i = 0;
	n = ft_ngtv(t_s, n);
	numlen(t_s, n);
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		printnum(t_s, n, p_w);
		printspace(t_s, w, p_w);
	}
	else
	{
		if (flagcheck(t_s) == 2 && t_s->negative < 0 && t_s->precision == 0)
		{
			write(1, "-", 1);
			t_s->ret++;
		}
		printspace(t_s, w, p_w);
		printnum(t_s, n, p_w);
	}
}
