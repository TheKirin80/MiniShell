/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:18:10 by akefeder          #+#    #+#             */
/*   Updated: 2022/09/11 12:12:21 by akefeder         ###   ########.fr       */
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

#define ERROR		-1
#define OK			0
#define CONTINUE	1
#define ERR_CHECK	1
#define ERR_SPLIT	2
#define END			3

typedef struct s_data	t_data;
typedef	struct s_env	t_env;

typedef enum 
{ 
	CMD,
	OPT,
	ARG,
	PIPE,
	S_L_REDIR,
	D_L_REDIR,
	S_R_REDIR,
	D_R_REDIR,
	S_QUOTE,
	D_QUOTE
}	t_token;

struct s_data
{
	char	*str;
	//t_token	token;
	t_data	*suiv;
	//int i;
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
char	*ft_strcopy_esp_split(char *str, int *i, char *c);
t_data	*ft_quot_esp_split(char *src);
t_data	*parsing(char *s);
void	gest_error(int code_err, t_data *data);
int		check_error_parse(char *s);
int		ft_compare(char *src, char *cmp);
#endif