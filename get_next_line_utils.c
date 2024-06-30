/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siligh <siligh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:05:39 by siligh            #+#    #+#             */
/*   Updated: 2024/06/30 16:08:57 by siligh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	tot_len;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tot_len = len1 + len2;
	res = (char *)malloc(sizeof(char) * tot_len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, tot_len + 1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = 0;
	str1 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
