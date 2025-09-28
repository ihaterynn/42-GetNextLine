/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:44:54 by ryachan           #+#    #+#             */
/*   Updated: 2025/07/07 08:44:54 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int	i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strdup(const char *s)
{
    int	i;
    char *new;

    i = 0;
    if (!s)
        return (NULL);
    new = (char *)malloc(ft_strlen(s) + 1);
    if (!new)
		return (NULL);
    while (s[i] != '\0')
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    int     i;
    char    *res;

    if (!s1 || !s2)
        return (NULL);
    res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    i = 0;
    if (!res)
        return (NULL);
    while (s1[i] != '\0')
    {
        res[i] = s1[i];
        i++;
    }
    while (*s2 != '\0')
    {
        res[i] = *s2++;
        i++;
    }
    res[i] = '\0';
    return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	if (!s)
		return (NULL);
	cc = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
    char    *ptr;
    size_t  i;

    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < (count * size))
        ptr[i++] = 0;
    return (ptr);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *str;

    i = 0;
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);
    while (i < len && s[start + i] != '\0')
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}