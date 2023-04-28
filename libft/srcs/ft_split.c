/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:06:07 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/14 18:59:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_line(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			size++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (size);
}

static char	*ft_splitdup(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (end > start)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

static char	**ft_count_words(char **dst, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	pos;

	pos = 0;
	start = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == ft_strlen(s))
				dst[pos++] = ft_splitdup(s, start, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			start = i;
		}
	}
	dst[pos] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (!s)
		return (0);
	dst = (char **)malloc(sizeof(char *) * (ft_count_line(s, c) + 1));
	if (!dst)
		return (0);
	ft_count_words(dst, s, c);
	return (dst);
}
