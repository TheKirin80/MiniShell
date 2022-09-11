/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:44:59 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 13:00:07 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data*	add_l_arg(void)
{
	t_data	*slot;

	slot = malloc(1 * sizeof(t_data));
	if (slot == NULL)
		return (NULL);
	slot->suiv = NULL;
	slot->str = NULL;
	return (slot);
}

int		ft_comp_esp_split(char src)
{
	if (src == '\'')
		return (1);
	else if (src == '\"')
		return (2);
	else
	{
		return (0);
	}
}

void	ft_quote_case(char *str, char *cpy, int *i, char c)
{
	int	j;

	j = 0;
	while(str[(*i)] != '\0' && str[(*i)] != c)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
	(*i)++;
}

void	ft_space_case(char *str, char *cpy, int *i, char *c)
{
	int	j;

	j = 0;
	while(str[(*i)] != '\0' && ft_compare(str[(*i)], c) != OK)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
}

char	*ft_strcopy_esp_split(char *str, int *i, char *c)
{
	int 	choice;
	int		len;
	char	*cpy;

	while(str[(*i)] == ' ')
			(*i)++;
	choice = ft_comp_esp_split(str[(*i)]);
	len = ft_strlen_char_i(str, c[choice], (*i));
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	if (c[choice] == '\'' || c[choice] == '\"')
	{	
		(*i)++;
		ft_quote_case(str, cpy, i, c[choice]);
	}
	else
	{
		ft_space_case(str, cpy, i, c);
	}
	return (cpy);
}