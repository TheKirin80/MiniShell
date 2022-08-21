#include "../minishell.h"

int	find_nb_pipe(char *s)
{
	int i = 0;
	int nb = 0;

	while (s && s[i])
	{
		if (s[i] == '|')
			nb++;
		i++;
	}
	return (nb);
}
