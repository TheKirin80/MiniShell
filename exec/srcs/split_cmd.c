#include "../minishell.h"

char	*fill_string(char *s, int start, int end)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**fill_tab(char *s, int count, char sep)
{
	char	**tab;
	int		i;
	int		start;
	int		end;

	tab = malloc(sizeof(char *) * count + 1);
	end = 0;
	i = 0;
	while (i < count)
	{
		start = end;
		while (s[end] && s[end] != sep)
			end++;
		tab[i] = fill_string(s, start, end);
		while (s[end] == sep)
			end++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**split_cmd(char *s, char sep)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i] && s[i] != sep)
		{
			while (s[i] && s[i] != sep)
				i++;
			count++;
		}
	}
	return (fill_tab(s, count, sep));
}
