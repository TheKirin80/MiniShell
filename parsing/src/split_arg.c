/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/11/04 16:40:46 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_data	*ft_quot_esp_split(char *src)
{
	int		i;
	t_data	*slot;
	t_data	*data;

	data = add_l_arg();
	slot = data;
	i = 0;
	while (slot && src[i] != '\0')
	{
		while (slot->suiv != NULL)
			slot = slot->suiv;
		slot->str = ft_strcopy_esp_split(slot, src, &i, " \'\"");
		if (slot->str == NULL)
			return (gest_error(ERR_SPLIT, data), NULL);
		while (src[i] == ' ')
			i++;
		if (src[i] != '\0')
		{
			slot->suiv = add_l_arg();
			if (slot->suiv == NULL)
				return (gest_error(ERR_SPLIT, data), NULL);
		}
	}
	return (data);
}

t_data	*ft_pipe_redir(t_data *data)
{
	t_data	*slot;
	t_data	*save;

	slot = data;
	while (slot != NULL)
	{
		if (slot->token == DEFAULT && ft_compare_str(slot->str, "<|>") == FOUND)
			ft_select_split(slot);
		if (slot == NULL)
		{	
			printf("je suis la\n");
			return (gest_error(ERR_SPLIT, data), NULL);
		}
		slot = slot->suiv;
	}
	slot = data;
	clean_list(slot);
	if (data->str != NULL && data->token == 0 && data->str[0] == '\0')
	{
		save = data->suiv;
		del_l_arg(data);
		data = save;
	}
	return (data);
}

t_data	*ft_search_expand(t_data *data, char **env)
{
	t_data	*slot;

	slot = data;
	while (slot != NULL)
	{
		if (slot->token != S_QUOTE)
		{
			if (ft_compare_char(slot->str, '$') == FOUND)
			{
				ft_expand(slot, env);
				if (slot->str == NULL)
					return (gest_error(ERR_SPLIT, data), NULL);
			}
		}
		slot = slot->suiv;
	}
	return (data);
}

t_data	*ft_after_expand(t_data	*data)
{
	t_data	*slot;

	slot = data;
	while (slot != NULL)
	{
		if (slot->token != S_QUOTE && slot->token != D_QUOTE)
		{
			if (ft_compare_char(slot->str, ' ') == FOUND)
			{
				ft_split_space(slot);
				if (slot->str == NULL)
					return (gest_error(ERR_SPLIT, data), NULL);
			}
		}
		slot = slot->suiv;
	}
	ft_join_arg(data);
	return (data);
}

t_data	*ft_last_error(t_data *data)
{
	t_data	*slot;

	slot = data;
	while (slot != NULL)
	{
		if (slot->token == PIPE && slot->suiv->token == D_L_REDIR)
			slot = slot->suiv;
		else if (ft_cmp_token(slot) == FOUND
			&& ft_cmp_token(slot->suiv) == FOUND)
		{
			gest_error(ERR_CHECK, data);
			slot = NULL;
		}
		else
			slot = slot->suiv;
	}
	if (data != NULL)
		ft_token(data);
	return (data);
}
