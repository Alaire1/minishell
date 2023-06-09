/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:38:04 by wmoughar          #+#    #+#             */
/*   Updated: 2023/07/10 16:29:37 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

//env
t_env	*ft_create_node(char *name, char *value);
void	print_env(t_env *envp);
t_env	*store_env(char **env);

//export
void	export(t_env *envp);
t_env	*sort_env(t_env *env);
void	ft_check_name(t_env *env);
void	ft_check_name_start(char *s);
int		ft_check_duplicate(t_env *env, char *name, char *new_name);
t_env	*add_to_list(t_env *head, char *var);
t_env	*find_and_replace(t_env *env, t_env *new);

//unset
t_env	*remove_from_list(t_env *head, char *name);

//free
void	free_split(char **arr);
void	free_env(t_env *env);

//pwd
int		ft_pwd(void);

//exit
void	ft_exit(void);

#endif