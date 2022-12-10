/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:42 by emakas            #+#    #+#             */
/*   Updated: 2022/12/10 14:46:29 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_utils.h"
#include "wildcard.h"
#include "libft.h"
#include "error.h"


static int strncmp2(const char *str, const char *search, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{ // m, a
		if (search[index] != '?') // ADD RECORRECTIONS AFTER PULL
		{
			if ((str[index] != search[index] && search[index] != ESC_WILDCARD_CHAR && search[index] != ESC_QUESTION_CHAR)
					|| (str[index] != '*'  && search[index] == ESC_WILDCARD_CHAR)
					|| (str[index] != '?'  && search[index] == ESC_QUESTION_CHAR))
				return (str[index] - search[index]);
		}
		index++;
	}
	return (0);
}

static char *strnstr2(const char *str, const char *search, size_t n)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(search);
	while (index < n)
	{
		if (str[index] == search[0])
			if (strncmp2(&str[index], search, len) == 0)
				return ((char *) &str[index]);
		index++;
	}
	return (NULL);
}

/*
 * Checks is str contains all the strings `contains`
 * in order in it.
 */
static bool	check_inside(char *str, char **contains)
{
	char	*candidate;
	int		index;

	candidate = str;
	index = 0;
	while (contains[index] != NULL && *candidate)
	{
		candidate = strnstr2(candidate, contains[index], ft_strlen(candidate));
		if (candidate == NULL)
			return (false);
		candidate += ft_strlen(contains[index]);
		index++;
	}
	return (true);
}

/*
 * Checks if the start and end of the str work with pattern
 */
static int	check_edges(char *str, char *pattern)
{
	if (pattern)
	{
		if (check_start(str, pattern) == 0)
			return (0);
		if (check_end(str, pattern) == 0)
			return (0);
	}
	return (1);
}

/*
 * *aaa*bb*cc*
 * aaa
 * bb
 * cc
 */
int	check_match(char *str, char *pattern)
{
	char	**patterns_split;

	patterns_split = ft_split(pattern, '*');
	if (patterns_split == NULL)
		malloc_error();
	if (check_edges(str, pattern))
	{
		if (check_inside(str, patterns_split))
			return (1);
	}
	return (0);
}
