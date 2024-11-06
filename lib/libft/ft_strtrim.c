/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strtrim.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:19:18 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:19:21 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
RETURN VALUE
The trimmed string.
NULL if the allocation fails.*/

static	int	ft_check(char s, char const *set)
{
	while (*set)
		if (*set++ == s)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	start;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *set == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_check(s1[start], set))
		start++;
	while (ft_check(s1[end - 1], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start);
	return (str);
}

/*int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("|%s|\n", ft_strtrim(av[1], av[2]));
	}
}*/
