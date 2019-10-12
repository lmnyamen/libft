/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmnyamen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:27:57 by lmnyamen          #+#    #+#             */
/*   Updated: 2019/06/27 14:56:28 by lmnyamen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			w_cnt(char const *s, char c)
{
	int		n;
	int		w;

	n = 0;
	w = 0;
	while (s[n])
	{
		while (s[n] == c && s[n])
			n++;
		while (s[n] != c && s[n])
			n++;
		if (s[n] == '\0')
			return (w);
		w++;
	}
	return (w);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		r;
	int		i;
	int		j;

	i = 0;
	r = 0;
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (w_cnt(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0' || r == w_cnt(s, c) + 1)
			break ;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		arr[r] = ft_strnew(j + 1);
		arr[r] = ft_strsub(s, i, j);
		i += j;
		r++;
	}
	arr[r] = NULL;
	return (arr);
}
