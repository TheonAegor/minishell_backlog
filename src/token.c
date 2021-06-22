#include "minishell.h"

t_token	*init_token(int size)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->data = malloc(size+1);
	token->data[0] = 0;
	
	token->type = CHAR_NULL;
	token->next = NULL;
	return (token);
}

void	add_token_front(t_token **last_token, t_token *new_token)
{
	t_token *tmp;

	tmp = *last_token;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_token;
}

void	implement_f_to_all_tokens(t_token **last_token,void (*f)()) 
{
	t_token		*tmp;

	tmp = *last_token;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

t_token	*first_token(t_token *last_token)
{
	t_token		*tmp;

	tmp = last_token;
	while (tmp->next)
		tmp = tmp->next;
	return(tmp);
}