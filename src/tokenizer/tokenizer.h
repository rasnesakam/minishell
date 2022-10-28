/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:26:00 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 17:14:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H

# define TOKENIZER_H

# include "token.h"
# include "tokenize_state.h"

// Tokenizes the given string. Returns a pointer array of tokens.
// The strings inside the tokens will not be heap allocated. They
// will only be a pointer to parts in the given string. For example:
//
// 	Token 2 (SPACE)  Token 2 (QUOTE_OPEN) Token 5 (QUOTE_CLOSE)
//
// echo      "Hello    $USER"
// |  |       |       | |  |
// Token 1    Token 3  Token 4
t_token	**tokenize(const char *str);

t_token	*tokenize_single(const char **str, t_state *state);

// Frees the token structs and the tokens pointer.
void	free_tokens(t_token **tokens);

#endif
