/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:18:10 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/02 14:00:06 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>

#define ERROR	-1
#define OK		0

typedef struct s_data	t_data;
typedef	struct s_env	t_env;

struct s_data
{
	char	*str;
	//t_token	token;
	t_data	*suiv;
	int i;
};

struct	s_env
{
	char	*str;
	char	*shrt;
	char	*path;
	t_env	*suiv;
};

int		add_l_env(char *env, t_env *my_env);
t_env	*init_l_env(char **env);
char	*ft_strcopy(char *str);
char	*ft_strcopy_int(char *str, int i);
char	*ft_strcopy_char_e(char *str, char c, int *i);
int		ft_split_env(t_env *env, char c);
int	ft_strlen(char *str);
int	ft_strlen_int(char *str, int i);
int	ft_strlen_char(char *str, char c);
int	ft_strlen_char_i(char *str, char c, int i);
int	ft_strllen(char **str);
t_data	*add_l_arg(void);
char	*ft_strcopy_char_a(char *str, char c, int *i);
t_data	*ft_split_arg(char c, char *src);
t_data	*parsing(char *s);

#endif