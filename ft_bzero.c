#include "minishell.h"

void	ft_bzero(char *s, size_t n)
{
	unsigned char	*mas;

	mas = (unsigned char *)s;
	if (n--)
		*mas++ = '0';
	while (n--)
		*mas++ = '\0';
}
