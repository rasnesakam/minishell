/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:56:39 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 14:16:06 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashing.h"
#include "libft.h"
#include <unistd.h>

t_hash	hashcode(void *data, size_t len)
{
	char	*cdata;
	size_t	index;
	t_hash	code;

	cdata = (char *) data;
	index = 0;
	code = 0;
	while (index < len)
	{
		code += (t_hash)(cdata[index] * (index + 1));
		index++;
	}
	return (code);
}

// TODO: Make this faster
t_hash	hashcode_str(const char *str)
{
	return (hashcode((void *)str, ft_strlen(str)));
}
