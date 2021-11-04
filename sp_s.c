/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_s.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 20:08:03 by akramp         #+#    #+#                */
/*   Updated: 2020/02/20 12:23:49 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printfstr_else(int i, t_printf *t_s, unsigned char *n, int p_w)
{
	if (t_s->prec_w == 0 && t_s->precision != 0)
		return ;
	while (n[i] != '\0')
	{
		if (i >= p_w)
			return ;
		write(1, &n[i], 1);
		i++;
		t_s->ret++;
	}
	return ;
}

static void		printstr(t_printf *t_s, unsigned char *n, int p_w)
{
	int i;

	i = 0;
	if (t_s->prec_w == 0 && t_s->precision != 0)
		return ;
	if (p_w == 0)
		p_w = t_s->numlen;
	if (t_s->precision != 0 && p_w < (int)t_s->width)
	{
		if (p_w < t_s->numlen)
			t_s->numlen = p_w;
		while (n[i] != '\0' && i < t_s->numlen)
		{
			write(1, &n[i], 1);
			i++;
			t_s->ret++;
		}
	}
	else
		printfstr_else(i, t_s, n, p_w);
}

static void		printspace_s(t_printf *t_s, int w, int p_w)
{
	char	output;
	int		temp;

	output = ' ';
	temp = t_s->numlen;
	if (p_w > w && t_s->numlen > w)
		return ;
	if (p_w < t_s->numlen && t_s->precision != 0)
		t_s->numlen = p_w;
	if (t_s->numlen >= w)
		return ;
	if (w > t_s->numlen)
		w = w - t_s->numlen;
	while (w > 0)
	{
		if (flagcheck(t_s) == 2)
			output = '0';
		write(1, &output, 1);
		t_s->ret++;
		w--;
	}
	t_s->numlen = temp;
}

void			sp_s(t_printf *t_s, unsigned char *n)
{
	int w;
	int	p_w;
	int i;

	w = t_s->width;
	p_w = (int)t_s->prec_w;
	i = 0;
	if (n == 0)
		n = (unsigned char *)"(null)";
	t_s->numlen = ft_strlen((const char *)n);
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		printstr(t_s, n, p_w);
		printspace_s(t_s, w, p_w);
	}
	else
	{
		printspace_s(t_s, w, p_w);
		printstr(t_s, n, p_w);
	}
}
