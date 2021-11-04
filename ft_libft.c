/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libft.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:44:11 by akramp         #+#    #+#                */
/*   Updated: 2020/02/11 20:41:19 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsignedputnbr_fd(unsigned int n, int fd, t_printf *t_s)
{
	if (n >= 10)
		ft_unsignedputnbr_fd(n / 10, fd, t_s);
	ft_putchar_fd((n % 10) + '0', fd, t_s);
}

void	putnbrbase(unsigned long n, int fd, int bse, t_printf *t_s)
{
	if (n >= (unsigned long)bse)
		putnbrbase((unsigned long)(n / bse), fd, bse, t_s);
	if (n % (unsigned long)bse >= 10)
	{
		if (t_s->specifier == 'X')
			ft_putchar_fd((n % (unsigned long)bse) + 55, fd, t_s);
		else
			ft_putchar_fd((n % (unsigned long)bse) + 87, fd, t_s);
	}
	else
		ft_putchar_fd((n % (unsigned long)bse) + '0', fd, t_s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d == 0 && s == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;

	if (src == 0)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = dstsize - 1;
	if (srclen < dstsize)
		dstlen = srclen;
	ft_memcpy(dst, src, dstlen);
	dst[dstlen] = '\0';
	return (srclen);
}
