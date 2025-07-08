/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:34:45 by ryachan           #+#    #+#             */
/*   Updated: 2025/07/07 08:34:45 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char    *get_next_line(int fd);
char    *read_line(int fd, char **stash);
char    *extract_line(char *stash);
char    *clear_buffer(char *stash);

// utils
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);

# endif
