/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_expand_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:32:18 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/11 12:49:44 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_split_space(t_data *data)
{
	char	*src;
	t_data	*slot;
	int		i;

	src = data->str;
	i = 0;
	slot = data->suiv;
	data->str = ft_strcopy_char(src, ' ');
	while (src[i] != ' ')
		i++;
	while (src[i] == ' ')
		i++;
	data->suiv = add_l_arg();
	data->suiv->str = ft_strcopy_int(src, &i);
	if (data->follow == 1)
	{
		data->follow = 0;
		data->suiv->follow = 1;
	}
	data->suiv->suiv = slot;
	free(src);
}

char	*ft_strijoin(char *beg, char *end)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(beg) + ft_strlen(end);
	ret = malloc((len + 1) * sizeof(char));
	i = 0;
	while(beg && beg[i]!= '\0')
	{
		ret[i] = beg[i];
		i++;
	}
	j = 0;
	while(end && end[j]!= '\0')
	{
		ret[i] = end[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return(ret);
}

void	ft_join_arg(t_data *data)
{
	t_data	*slot;
	t_data	*save;
	char	*str;

	slot = data;
	save = NULL;
	while (slot != NULL)
	{
		while (slot->follow == 1)
		{
			str = slot->str;
			slot->str = ft_strijoin(slot->str, slot->suiv->str);
			slot->follow = slot->suiv->follow;
			save = slot->suiv->suiv;
			free(str);
			del_l_arg(slot->suiv);
			slot->suiv = save;
		}
		slot = slot->suiv;
	}
}