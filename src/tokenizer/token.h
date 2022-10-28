/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:23:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/26 17:23:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

enum e_token_type
{
	EMPTY,
	WORD,
	SPACE,
	VAR,
	PAREN_OPEN,
	PAREN_CLOSE,
	QUOTE_OPEN,
	QUOTE_CLOSE,
	SQUOTE_OPEN,
	SQUOTE_CLOSE,
};

# define PRINTABLE (WORD)

typedef struct s_token
{
	int					len;
	enum e_token_type	type;
	const char			*str;
}	t_token;

#endif
