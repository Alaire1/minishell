/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:59:19 by cmenke            #+#    #+#             */
/*   Updated: 2023/07/13 14:36:55 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//If there is a quote it searches for the next quote of the same type.
//If there is not a second quote of the same type this means the ammount of 
//quotes is not equal.
bool	ft_check_equal_quote_amt(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			while (s[++i] && s[i] != '\'')
				;
			if (s[i] != '\'')
				return (ft_putendl_fd(L_RED SQUOTE_ERROR STYLE_DEF, 2), false);
		}
		else if (s[i] == '\"')
		{
			while (s[++i] && s[i] != '\"')
				;
			if (s[i] != '\"')
				return (ft_putendl_fd(L_RED DQUOTE_ERROR STYLE_DEF, 2), false);
		}
		if (s[i])
			i++;
	}
	return (true);
}

bool	ft_search_and_print_syntax_error(t_shell_data *shell_data)
{
	t_list		*temp;
	t_tokens	*token;
	t_tokens	*next_token;

	temp = shell_data->all_tokens;
	while (temp)
	{
		token = (t_tokens *)temp->content;
		if (temp->next)
			next_token = (t_tokens *)temp->next->content;
		else
			next_token = NULL;
		if (ft_check_for_syntax_error(token, next_token))
			return (false);
		temp = temp->next;
	}
	return (true);
}

bool	ft_check_for_syntax_error(t_tokens *token, t_tokens *next_token)
{
	if (token->type == syntax_error)
	{
		printf("found syntax error in token: %s\n", token->token);
		return (true);
	}
	else if (ft_is_operator(token->type) && (!next_token || ft_is_operator(next_token->type)))
	{
		if (token->type == pipe_operator && !next_token)
		{
			printf("found a pipe at the end, start reading\n");
		}
		else if (token->type == pipe_operator && next_token)
		{
			printf("found a pipe, next token just needs to exist\n");
			return (false);
		}
		else
		{
			printf("found syntax error in token: %s\n", token->token);
			return (true);
		}
	}
	return (false);
}

bool	ft_is_operator(char token_type)
{
	if (token_type >= 1 && token_type <= 6)
		return (true);
	return (false);
}