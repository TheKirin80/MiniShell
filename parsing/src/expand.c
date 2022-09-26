/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:22:14 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/25 19:03:11 by akefeder         ###   ########.fr       */
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

	while (exp[j] != NULL)
	{
		i = 0;
		if (exp[j][0] == '\0')
			exp[j] = dollar_case(exp, j);
		else
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

void	ft_expand(t_data *data, char **env)
{
	int		len_deb;
	char	**exp;
	int		i;
	int		j;
	
	//len_deb = ft_count_compare(data->str, '$');
	exp = malloc((len_deb + 1) * sizeof(char *));
	i = 0;
	j = 0;
	len_deb = 0;
	if (data->str[i] != '$')
		len_deb = 1;
	while(data->str[i]!= '\0')
	{
		if (data->str[i] == '$')
			i++;
		exp[j] = ft_strcopy_char_i(data->str, '$', &i);
		j++;
	}
	exp[j] = NULL;
	j = len_deb;
	free(data->str);
	data->str = modif_exp(exp , j, env);
}

int		ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
		i++;
	return (i);
}

int		ft_strlen_i_j(char *str, int *i, int *j)
{
	
}

char	*ft_strcopy_i_j(char *str, char *i, int *j)
{
	int		len;
	int		j;
	char	*cpy;

	j = 0;
	len = ft_strlen_i_j(str, *i, *j);
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	while (str[(*i)] != c && str[(*i)] != '\0')
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	**add_one_str(char **exp, char *str)
{
	char	**cpy;
	int		i;	
	
	i = 0;
	cpy = malloc ((ft_strstrlen(str) + 2) * sizeof(char *));
	while (exp[i] != NULL)
	{
		cpy[i] = exp[i];
	}
	cpy[i] = str;
	i++;
	cpy[i] = i++;
	free(exp);
	return (cpy);
}

char	**ft_split_exp(char *str)
{
	char	**exp;
	int		i;
	int		dollar;
	
	exp = NULL;
	i = 0;
	dollar = 0;
	while (str[i] != '\0')
	{
		if (dollar == 0)
			if (str[i] == $)
			{
				exp = add_one_str(exp, )
			}
		if (str[i] ==
	}
}

void	ft_expand(t_data *data, char **env)
{
	char **exp;
	
	exp = ft_split_exp(data->str);
	
	
}

