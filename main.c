#include "minishell.h"

char *lsh_read_line(void)
{
	char *inpt;
	inpt = readline(" ");
    add_history(inpt);
    printf("%s", inpt);
    printf("\n");
	return (inpt);
}

int lsh_execute(char **args)
{
	
	return (0);
}

char* ft_realloc(char *gen)
{
	size_t i;
	char *dest;

	i = ft_strlen(gen);
	dest = (char*)malloc(sizeof(char) * (i + 1));
	dest = ft_strdup(gen);
//	free(gen);
	return (dest);
}

void  ft_char_parsing(char **line, t_list **tmp, char **gen)
{
	int i = 0;
//	t_list *arr = NULL;

//	ft_memset(*gen, 1, sizeof(*gen));
	while ((*gen)[i] != '\0')
	{
		printf("LEN\n");
		i++;
	}
	while (**line != ' ' &&  **line != '\0' && **line != '\'')
	{
		if (*(*line) != '\'')
		{
			*gen = ft_realloc(*gen);
			(*gen)[i] = **line;
			i++;
		}
		printf("CHAR\n");
		(*line)++;
	}
//	printf("LINE1 %p %p %p\n",*tmp, (*tmp)->prev, (*tmp)->next);
}

void ft_quote_parsing(char **line, t_list **tmp, char **gen)
{
	int i = 0;

	(*line)++;
	printf("'%s'\n", *gen);
	i = ft_strlen(*gen);
	printf("LEN %d\n", i);
	printf("QUOTE %s %d\n", *gen, i);
	while (**line!= '\0' && **line != '\'')
	{
		*gen = ft_realloc(*gen);
		if (**line != '\'')
			(*gen)[i] = **line;
		(*line)++;
		i++;
		printf("QOU\n");
	}
	(*line)++;
}
/*
void ft_path_parsing(char **line, char **gen, char **envp)
{
	char *path;

	path = (char *)malloc(sizeof(char) * 1);
	ft_memset(gen, 0, sizeof(gen));
	while (*line != ' ' && *line != '\0' && *line != 

}
	*/

void ft_line_parsing(char *line,char **envp)
{
	char* gen;
	char* fin;
	int i = 0;
	t_list *tmp = NULL;
	t_list *arr = NULL;

	while (*line != '\0') {
		gen = (char*)malloc(sizeof(char) * 1);
		ft_memset(gen, 0, sizeof(gen));
		while (*line != ' ' && *line != '\0')
		{
			printf("SIZE1 %zu\n", ft_strlen(gen));
			printf("SIZE2 %zu\n", ft_strlen(gen));
			fin = gen;
			if (*line != ' ' && *line != '\"' && *line != '\'')
				ft_char_parsing(&line, &tmp, &gen);
			if (*line == '\'')
				ft_quote_parsing(&line, &tmp, &gen);
			if (*line == '$')
				ft_path_parsing(&line, &gen, envp);
			printf("P\n");
		}
		printf("GENLINE %s\n", gen);
		if (ft_strlen(gen) != 0)
		{
			printf("NEW_LIST\n");
			arr = ft_lstnew(gen, tmp);
			tmp = arr;
			arr = arr->next;
		}
	//	printf("LINE1 %p %p %p\n",tmp, (tmp)->prev, (tmp)->next);
		printf("C '%c'\n", *line);
	//	free(gen);
		while (*line == ' ')
			line++;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while (tmp != NULL)
	{
		printf("LIST %s\n", tmp->arg);
		tmp = tmp->prev;
	}
}

void lsh_loop(char **envp)
{
	char *line;
	char **args;
	int status = 1;

	while (status) {
		printf(" > ");
		line = lsh_read_line();
		ft_line_parsing(line, envp);
	//	args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
	//	free(args);
	}
}

int main(int argc, char **argv, char **envp)
{
	lsh_loop(envp);
	return EXIT_SUCCESS;
/*	char *inpt;

        int i = 0;

        while ( i < 10 )
        {
                inpt = readline("Enter text: ");
                add_history(inpt);
                printf("%s", inpt);
                printf("\n");
                ++i;
        }*/

     //   return 0;
}
