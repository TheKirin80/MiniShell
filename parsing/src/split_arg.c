/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/09 11:55:34 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcopy_char_a(char *str, char c, int *i)
{
	int		len;
	char	*cpy;
	int		j;

	while(str[(*i)] == ' ')
			(*i)++;
	j = *i;
	len = ft_strlen_char_i(str, c, j);
	j = 0;
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while(str[(*i)] != '\0' && str[(*i)] != c)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
	printf("Original : %s\n Indice de debut %i\n valeur de la copy : %s\n", str, *i, cpy);
	return (cpy);
}

t_data	*ft_split_arg(char c, char *src)
{
	int	i;
	t_data	*slot;
	//t_data	*flow;
	t_data	*data = NULL;

	if (!data)
		data = add_l_arg();
	slot = data;
	i = 0;
	while (src[i] != '\0')
	{
		while(slot->suiv != NULL)
			slot = slot->suiv;
		slot->str = ft_strcopy_char_a(src, c, &i);
		if (slot->str == NULL)
			return (NULL);
		if (src[i] != '\0')
			slot->suiv = add_l_arg();
	}
	return (data);
}
