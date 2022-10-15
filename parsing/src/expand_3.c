/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:22:36 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/15 14:27:53 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
		i++;
	return (i);
}

char	*ft_strcopy_i_j(char *str, int i, int j)
{
	int		len;
	int		k;
	char	*cpy;

	k = 0;
	len = j - i;
	cpy = malloc ((len + 2) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while (i < j && str[i] != '\0')
	{
		cpy[k] = str[i];
		i++;
		k++;
	}
	cpy[k] = '\0';
	return (cpy);
}

char	**ft_split_exp(char *str)
{
	char	**exp;
	int		cpt[3];
	int		dollar;

	exp = NULL;
	cpt[0] = 0;
	cpt[1] = 0;
	cpt[2] = 0;
	dollar = 0;
	while (str[cpt[0]] != '\0')
	{
		cpt[2] = found_split(str, dollar, cpt[1], cpt[0]);
		if (cpt[2] == FOUND || cpt[2] == SPEC)
		{
			exp = select_found(cpt, &dollar, exp, str);
		}
		(cpt[0])++;
	}
	exp = add_one_str(exp, ft_strcopy_i_j(str, cpt[1], cpt[0]));
	return (exp);
}