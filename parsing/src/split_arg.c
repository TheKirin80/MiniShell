/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:53:51 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 12:38:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*ft_select_copy(char *src, int *i)
// {
// 	return (ft_strcopy_char_a(str, ' ', i));
// }

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
		slot->str = ft_strcopy_esp_split(src, &i, " \'\"");
		if (slot->str == NULL)
			return (NULL);
		while(src[i] == ' ')
			i++;
		if (src[i] != '\0')
			slot->suiv = add_l_arg();
	}
	return (data);
}