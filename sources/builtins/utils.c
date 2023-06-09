/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:05 by wmoughar          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:02 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <errno.h>

void	free_env(t_env *env)
{
	while (env)
	{
		free(env->name);
		free(env->value);
		env->next;
	}
	free(env);
}

t_env	*ft_search(t_env *env, char *name)
{
	t_env	*target;
	char	*value;

	target = env;
	if (!target)
		return (NULL);
	while (target && ft_strncmp(target->name, name, ft_strlen(target->name)))
		target = target->next;
	return (target);
}

t_env	*update_value(t_env *env, char *name, char *new_val)
{
	t_env	*tmp;

	tmp = ft_search(env, name);
	if(tmp)
	{
		free(tmp->value);
		tmp->value = ft_strdup(new_val);
	}
	return (tmp);
}

int	cd_error_handler(char *dir)
{
	char	*error = NULL;
	char	*join = NULL;
	char	*buffer = NULL;

	if (chdir(dir) == -1)
	{
		ft_putstr_fd("minishell: ", 1);
		perror(dir);
	}
	buffer = getcwd(buffer, 100);
	free(buffer);
	return (0);
}

int	ft_put_err(char *input, char *message, int code)
{
	ft_putstr_fd("minishell: ", 2);
	if (input)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(message, 2);
	return (code);
}