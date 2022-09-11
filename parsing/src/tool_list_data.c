/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 06:44:59 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 12:16:10 by akefeder         ###   ########.fr       */
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

char	*ft_strcopy_esp_split(char *str, int *i, char *c)
{
	int 	choice;
	int		len;
	char	*cpy;
	int		j;

	while(str[(*i)] == ' ')
			(*i)++;
	j = *i;
	choice = ft_comp_esp_split(str[(*i)]);
	len = ft_strlen_char_i(str, c[choice], (*i));
	j = 0;
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	if (c[choice] == '\'' || c[choice] == '\"')
		(*i)++;
	while(str[(*i)] != '\0' && str[(*i)] != c[choice])
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
	//printf("Original : %s\n Indice de debut %i\n valeur de la copy : %s\n", str, *i, cpy);
	return (cpy);
}