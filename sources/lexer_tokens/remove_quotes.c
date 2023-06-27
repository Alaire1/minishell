/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:38:02 by cmenke            #+#    #+#             */
/*   Updated: 2023/06/24 20:02:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_strlen_without_quotes(char *cmd_line)
{
	char	quote;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			quote = '\"';
			if (cmd_line[i] == '\'')
				quote = '\'';
			while (cmd_line[++i] && cmd_line[i] != quote)
					count++;
			if (cmd_line[i] && cmd_line[i] == quote)
				i++;
		}
		if (cmd_line[i] && cmd_line[i] != '\'' && cmd_line[i] != '\"')
		{
			i++;
			count++;
		}
	}
	return (count);
}

static void	ft_copy_element_without_quotes(char *cmd_line, char *new_line)
{
	char	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			quote = '\"';
			if (cmd_line[i] == '\'')
				quote = '\'';
			while (cmd_line[++i] && cmd_line[i] != quote)
					new_line[j++] = cmd_line[i];
			if (cmd_line[i] && cmd_line[i] == quote)
				i++;
		}
		if (cmd_line[i] && cmd_line[i] != '\'' && cmd_line[i] != '\"')
			new_line[j++] = cmd_line[i++];
	}
	new_line[j] = '\0';
}

bool	ft_remove_quotes_from_elements(t_tokens *token)
{
	int		counter;
	char	*new_line;

	counter = ft_strlen_without_quotes(token->token);
	new_line = malloc((counter + 1) * sizeof(char));
	if (!new_line)
	{
		perror("malloc - remove quotes from elements");
		return (false);
	}
	ft_copy_element_without_quotes(token->token, new_line);
	free(token->token);
	token->token = new_line;
	printf("token->token: %s\n", token->token);
	return (true);
}