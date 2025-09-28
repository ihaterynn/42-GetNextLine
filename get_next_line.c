/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:41:04 by ryachan           #+#    #+#             */
/*   Updated: 2025/07/07 08:41:04 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(int fd, char **stash)
{
    char    *buffer;
    char    *temp;
    int     bytes;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    if (!*stash)
    {
        *stash = ft_strdup("");
        if (!*stash)
            return (free(buffer), NULL);
    }
    bytes = 1;
    while (!ft_strchr(*stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buffer);
            return (NULL);
        }
        if (bytes == 0)
            break ;
        buffer[bytes] = '\0';
        temp = ft_strjoin(*stash, buffer);
        if (!temp)
        {
            free(buffer);
            return (NULL);
        }
        free(*stash);
        *stash = temp;
    }
    free(buffer);
    if (!*stash || **stash == '\0')
        return (NULL);
    return (*stash);
}

char    *extract_line(char  *stash)
{
    char    *line;
    size_t  count;

    if (!stash)
        return (NULL);
    count = 0;
    while (stash[count] != '\n' && stash[count] != '\0')
        count++;
    if (stash[count] == '\n')
        count++;
    line = ft_substr(stash, 0, count);
    return (line);
}

char    *clear_buffer(char  *stash)
{
    size_t  i;
    size_t  len;
    char    *new_stash;

    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    len = ft_strlen(stash) - i;
    if (len == 0)
    {
        free(stash);
        return (NULL);
    }
    new_stash = ft_substr(stash, i, len);
    free(stash);
    return (new_stash);
}

char    *get_next_line(int fd)
{
    static char    *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_line(fd, &stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    stash = clear_buffer(stash);
    return (line);
}