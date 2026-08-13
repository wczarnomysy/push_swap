#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//*SUBSTR*

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_strcpy(char *s2, const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = (char)s1[i];
		i++;
	}
	s2[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*res;

	size = ft_strlen(s);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

/*SPLIT*/

static void	ft_free(char **res, size_t j)
{
	while (0 < j)
	{
		j--;
		free(res[j]);
	}
	free(res);
	return ;
}

static	size_t	ft_countwords(const char *s, char c)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (j);
}

static char	*get_word(char const *s, char c, size_t *i)
{
	size_t	start;

	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (j < words)
	{
		res[j] = get_word(s, c, &i);
		if (!res[j])
			return (ft_free(res, j), NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}

/*
void make_simple(void)
{

}
void make_medium(void)
{

}
void make_complex(void)
{

}
void make_adaptive(void)
{

}
*/

int	flag_detector(char *s, int flag)
{
	if(strncmp(s, "--simple", 20) == 0 && (flag == 1 || flag == 0))
		return (1);
	else if(strncmp(s, "--medium", 20) == 0 && (flag == 2 || flag == 0))
		return (2);
	else if(strncmp(s, "--complex", 20) == 0 && (flag == 3 || flag == 0))
		return (3);
	else if(strncmp(s, "--adaptative", 20) == 0 && (flag == 4 || flag == 0))
		return (4);
	return (0);
}

int	is_bench(char *s)
{
	if(strncmp(s, "--bench", 20) == 0)
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}


/*ATOI*/

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		exit (EXIT_FAILURE);
	return (result);
}

t_node	*ft_lstlast(t_node *list)
{
	if(!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	t_node	*last;

	if(!new || !list)
		return ;
	if (!*list)
	{
		*list = new;
		new->prev = NULL;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new;
	new->prev = last;
}

t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if(!new)
		return (free(new), NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	assign_index(t_node **list)
{
	int	index;
	t_node *current;
	t_node *tmp;

	tmp = *list;
	while(tmp)
	{
		index = 1;
		current = *list;
		while (current)
		{
			if (tmp->value > current->value)
			{
				index++;
			}
			current = current->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
	return ;
}

float disorder_check(t_node *list)
{
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (list && list->next)
	{
		if (list->value > list->next->value)
			mistakes++;
		
		list = list->next;
		total_pairs++;
	}
	if (list->next == NULL && list->prev->value > list->value)
		mistakes++;
	total_pairs++;
	printf("Total pairs -> %d\nMistakes -> %d\n", total_pairs, mistakes);
	return (((float)mistakes / (float)total_pairs));
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if(s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while(s[i] <= '9' && s[i] >= '0')
		i++;
	if ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
		return (0);
	return (1);
}

int	has_duplicate(t_node *list, int value)
{
	while (list)
	{
		if (list->value == value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	main (int argc, char *argv[])
{
	int	i;
	int j;
	long value;
	int	flag_type;
	float disorder;
	char **arguments;
	t_node	*tmp;
	t_node	*new;
	t_node	*list;

	i = 1;
	new = NULL;
	list = NULL;

	/*CREAMOS EL STACK A COMPROBANDO SI LOS ARGUMENTOS DADOS SON VALIDOS O NO,
	  TENIENDO EN CUENTA LAS FLAGS*/

	while (i < argc)
	{
		arguments = ft_split(argv[i], ' ');
		j = 0;
		while (arguments[j])
		{
			if (flag_detector(arguments[j], flag_type) != 0 || is_bench(arguments[j]) != 0)
			{
				flag_type = flag_detector(arguments[j], flag_type);
				j++;
			}
			else
			{
				if(is_valid(arguments[j]) == 0)
					return (printf("ERROR NOT VALID"), 0);
				value = ft_atol(arguments[j]);
				if (has_duplicate(list, value) == 0)
					return (printf("ERROR"), 0);
				new = ft_lstnew(value);
				ft_lstadd_back(&list, new);
				printf("%d\n", new->value);
				j++;
			}
		}
		i++;
	}

	printf("La flag es la %d\n", flag_type);

	/*VOLVEMOS A LA CABEZA DEL STACK PARA ASIGNAR LOS INDEX*/

	while (list && list->prev)
		list = list->prev;
	
	assign_index(&list);

	tmp = list;

	while (tmp)
	{
		printf("El indice del valor %d es -> %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}

	/*CHECKEAMOS EL INDICE DE DESORDEN DEL STACK*/

	disorder = disorder_check(list);

	printf("%f", disorder);

	/*
	if (flag_type == 1)
		make_simple;
	else if (flag_type == 2)
		make_medium;
	else if (flag_type == 3)
		make_complex;
	else if (flag_type == 4)
		make_adaptative;
	*/

	return (0);
}