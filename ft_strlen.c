#include "minishell.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
	//	printf("%c\n", s[0]);
		return (0);
	}
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
