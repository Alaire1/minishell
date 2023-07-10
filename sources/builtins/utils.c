/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:28:05 by wmoughar          #+#    #+#             */
/*   Updated: 2023/07/10 17:57:01 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	free_env(t_env *env)
{
	t_env *tmp;

	while (env)
	{
		free(env->name);
		free(env->value);
		tmp = env;
		free(tmp);
		env = env->next;
	}
}