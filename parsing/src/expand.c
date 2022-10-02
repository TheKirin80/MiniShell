/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:22:14 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/02 15:55:06 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*dollar_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '$';
	ret[1] = '\0';
	free(exp[i]);
	return ret;
}

char	*n_found_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '\0';
	free(exp[i]);
	return (ret);
}

char	*switch_env_case(char **exp, char **env, int j, int i)
{
	int		k;

	k = 0;
	while (env[i][k] != '=')
		k++;
	k++;
	free(exp[j]);
	return (ft_strcopy_int(env[i], &k));
}

char	*modif_exp(char **exp, int j, char **env)
{
	int i;

	//printf("je suis ici\n");
	while (exp[j] != NULL)
	{
		i = 0;
		if (exp[j][0] == '$' && exp[j][1] == '\0')
			exp[j] = dollar_case(exp, j);
		else if (exp[j][0] == '$')
		{
			i = ft_strstrcmp(env, exp[j]);
			if (i == ERROR)
				exp[j] = n_found_case(exp, j);
			else
				exp[j] = switch_env_case(exp, env, j, i);
		}
		j++;
	}
	return (ft_strjoin(exp));
}

int		ft_strstrlen(char **str)
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

char	**add_one_str(char **exp, char *str)
{
	char	**cpy;
	int		i;	
	
	i = 0;
	cpy = malloc ((ft_strstrlen(exp) + 2) * sizeof(char *));
	while (exp != NULL && exp[i] != NULL)
	{
		cpy[i] = exp[i];
		i++;
	}
	cpy[i] = str;
	i++;
	cpy[i] = NULL;
	free(exp);
	return (cpy);
}

int		found_split(char *s, int dollar, int j, int i)
{
	if (dollar == 0)
	{
		if (s[i] == '$')
			return (FOUND);
	}
	else
	{
		if (j + 1 == i && (ft_num(s[i]) == FOUND || (s[i] == '?')))
			return (SPEC);
		else if (ft_maj(s[i]) == N_FOUND && ft_min(s[i]) == N_FOUND
			&& ft_num(s[i]) == N_FOUND)
			return (FOUND);
	}
	return (N_FOUND);
}

void	change_dollar(char **exp, int *dollar)
{
	int	i;

	i = 0;
	while (exp[i] != NULL)
		i++;
	i--;
	if (exp[i][0] == '$')
		(*dollar) = 1;
	else
		(*dollar) = 0;
}

char	**ft_split_exp(char *str)
{
	char	**exp;
	int		i;
	int 	j;
	int		dollar;
	
	exp = NULL;
	i = 0;
	j = 0;
	dollar = 0;
	while (str[i] != '\0')
	{
		if (found_split(str, dollar, j, i) == FOUND)
		{
			exp = add_one_str(exp, ft_strcopy_i_j(str, j, i));
			j = i;
			change_dollar(exp, &dollar);
		}
		i++;
	}
	exp = add_one_str(exp, ft_strcopy_i_j(str, j, i));	
	return (exp);
}

void	ft_expand(t_data *data, char **env)
{
	char	**exp;
	int		i;
	
	i = 0;
	exp = ft_split_exp(data->str);
	printer(exp);
	free(data->str);
	data->str = modif_exp(exp , i, env);
}
