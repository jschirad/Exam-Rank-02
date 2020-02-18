/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:42 by jschirad          #+#    #+#             */
/*   Updated: 2020/01/14 16:11:20 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$*/

void	ft_inter(char *s1, char *s2)
{
	char	str[256];
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (str[(unsigned int)s2[i]] == 0)
			str[(unsigned int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		if (str[(unsigned int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			str[(unsigned int)s1[i]] = 2;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
