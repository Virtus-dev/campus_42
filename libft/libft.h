/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:24:01 by arigonza          #+#    #+#             */
/*   Updated: 2022/09/22 13:29:46 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

/*
 * Struct
 */
typedef struct	s_list
{
	void	*content;
	struct	s_list	*next;
}	t_list;

/*
 * Part 1 - Lib functions
 */

/*
 * Memory
 */

void	*ft_memset(void *dest, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);


/*
 * String
 */

size_t	ft_strlen(const char *s);

/*
 * Type
 */

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isalnum(int c);

#endif
