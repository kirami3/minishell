#ifndef MINISHELL_H
#define MINISHELL_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	char	*arg;
	struct s_list *next;
	struct s_list *prev;
}				t_list;

size_t ft_strlen(char *s);
char	*ft_strdup(char *src);
t_list	*ft_lstnew(char *content, t_list *prev);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);

#endif
