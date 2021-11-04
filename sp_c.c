/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sp_c.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 19:14:43 by akramp         #+#    #+#                */
/*   Updated: 2020/02/23 13:22:29 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printspace_c(t_printf *t_s, int w)
{
	char	output;

	output = ' ';
	while (w > 1)
	{
		if (flagcheck(t_s) == 2)
			output = '0';
		write(1, &output, 1);
		t_s->ret++;
		w--;
	}
}

void			sp_c(t_printf *t_s, char c)
{
	int w;
	int	p_w;
	int i;

	w = t_s->width;
	p_w = (int)t_s->prec_w;
	i = 0;
	t_s->numlen = 1;
	if (flagcheck(t_s) == 1 || t_s->flags[1] == '-')
	{
		t_s->ret++;
		write(1, &c, 1);
		printspace_c(t_s, w);
	}
	else
	{
		printspace_c(t_s, w);
		t_s->ret++;
		write(1, &c, 1);
	}
}
