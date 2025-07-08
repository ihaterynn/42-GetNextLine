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

    bytes = 0;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    if (*stash == NULL)
        *stash = ft_strdup("");
    while (!ft_strchr(*stash, '\n') && bytes >= 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
            break ;
        buffer[bytes] = '\0';
        temp = ft_strjoin(*stash, buffer);
        free(*stash);
        *stash = temp;
    }
    free(buffer);
    if (bytes <= 0)
    {
        if (*stash && **stash != '\0') 
        return (extract_line(*stash));
    }
    return (extract_line(*stash));
}

char    *extract_line(char  *stash)
{
    char    *line;
    size_t  count;

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

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    len = 0;
    len = ft_strlen(stash) - i;
    if (len == 0)
        return (NULL);
    return (ft_substr(stash, i, len));
}

char    *get_next_line(int fd)
{
    static char    *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = read_line(fd, &stash);
    if (!line)
        return (NULL);
    stash = clear_buffer(stash);
    return (line);
}