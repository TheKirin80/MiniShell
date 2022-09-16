/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/17 00:18:31 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*ft_quot_esp_split(char *src)
{
	int	i;
	t_data	*slot;
	t_data	*data = NULL;

	if (!data)
		data = add_l_arg();
	slot = data;
	i = 0;
	while (src[i] != '\0')
	{
		while(slot->suiv != NULL)
			slot = slot->suiv;
		slot->str = ft_strcopy_esp_split(slot, src, &i, " \'\"");
		if (slot->str == NULL)
			return (NULL);
		while(src[i] == ' ')
			i++;
		if (src[i] != '\0')
			slot->suiv = add_l_arg();
	}
	return (data);
}

void	ft_pipe_redir(t_data *data)
{
	t_data	*slot;

	slot = data;
	while (slot != NULL)
	{
		if (slot->token == DEFAULT && ft_compare_str(slot->str, "<|>") == FOUND)
		{
			printf("j'ai detecte\n");
			ft_select_split(slot);
		}
		printf("dans pipe redr slot->token = %i ; slot->str = |%s|\n", slot->token, slot->str);
		slot = slot->suiv;
	}
}