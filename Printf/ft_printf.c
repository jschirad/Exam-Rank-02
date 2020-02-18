/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:37:30 by jschirad          #+#    #+#             */
/*   Updated: 2020/02/16 19:40:04 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//Primero escribo un contador de caracteres
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

//Segundo escribo un contador de numeros
int		ft_counter(long long num, int base_len)
{
	int	ct;

	ct = 1;
	while(num >= base_len || num <= -base_len)
	{
		num = num / base_len;
		ct++;
	}
	return (ct);
}
//Tercero, escribo un putnumber
void	ft_putnumber(long long num, int base_len, char *base)
{
	if (num >= base_len)
		ft_putnumber(num / base_len, base_len, base);
	write(1, &base[num % base_len], 1);
}
//Cuarto, escribo la funcion principal
int		ft_printf(char *fromat, ...)
{
	va_list		lst;
	char		*s;
	char		*base;
	long		num;
	int			ct = 0, ret = 0, neg = 0, zero = 0, width = 0,
	precision = 0, p_range = 0, space = 0, base_len = 0, pos = 0;

	va_start(lst, fromat);
	while(fromat[pos])
	{
		if (fromat[pos] == '%')
		{
			pos++;
			ct = 0, neg = 0, zero = 0, space = 0, width = 0, precision = 0, p_range = 0;
			//si tengo numeros seguidos del porcentaje
			while(fromat[pos] >= '0' && fromat[pos] <= '9')
			{
				width = width * 10 + (fromat[pos] - 48);
				pos++;
			}
			if (fromat[pos] == '.')
			{
				pos++;
				precision = 1;
				//Si tengo numeros seguido del punto
				while(fromat[pos] >= '0' && fromat[pos] <= '9')
				{
					p_range = p_range * 10 + (fromat[pos] - 48);
					pos++;
				}
			}
			if (fromat[pos] == 's')
			{
				s = va_arg(lst, char *);
				if (!s)
					s = "(null)";
				ct = ft_strlen(s);
			}
			if (fromat[pos] == 'x')
			{
				num = va_arg(lst, unsigned int);
				base = "0123456789abcdef";
				base_len = 16;
				ct = ft_counter(num, base_len);
			}
			if (fromat[pos] == 'd')
			{
				num = va_arg(lst, int);
				base = "0123456789";
				base_len = 10;
				ct = ft_counter(num, base_len);
				if (num < 0)
				{
					num = -num;
					neg = 1;
				}
			}
			if (precision && p_range > ct && fromat[pos] != 's')
				zero = p_range - ct;
			if (precision && p_range < ct && fromat[pos] == 's')
				ct = p_range;
			if (precision && !p_range && (fromat[pos] == 's' || !num))
				ct = 0;
			space = width - zero - ct - neg;
			while(space-- > 0)
			{
				write(1, " ", 1);
				ret++;
			}
			while(zero-- > 0)
			{
				write(1, "0", 1);
				ret++;
			}
			if (neg)
			{
				write(1, "-", 1);
				ret++;
			}
			if (fromat[pos] == 's')
			{
				write(1, s, ct);
			}
			else if (ct)
				ft_putnumber(num, base_len, base);
			ret += ct;
			pos++;
		}
		else
		{
			write(1, &fromat[pos], 1);
			ret++;
			pos++;
		}
	}
	va_end(lst);
	return (ret);
}

int	main()
{
	ft_printf("hola %d", 10);
	return (0);
}
