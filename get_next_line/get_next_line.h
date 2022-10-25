/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:22 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/25 13:53:16 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/*
 * Global variables
 */
#define END_OF_LINE '\n'
#define END_OF_FILE '\0'

char	*get_next_line(int fd);
/*
 * Utils
*/
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *s, size_t n);
#endif
