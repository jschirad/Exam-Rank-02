/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:14:46 by jschirad          #+#    #+#             */
/*   Updated: 2020/01/18 17:20:42 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <unistd.h>

void	ft_union(char *s1, char *str)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (str[(unsigned int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			str[(unsigned int)s1[i]] = 1;
		}
		i++;
	}
}

void	ft_check(char *s1, char *s2)
{
	char	str[256];

	ft_union(s1, str);
	ft_union(s2, str);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_check(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
