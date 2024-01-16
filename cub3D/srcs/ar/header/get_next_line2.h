/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:55:44 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 13:01:01 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
ssize_t	new_line_index(char *str);
void	fill_stack_zero(char *stack);
size_t	ft_strlen(char *str);
void	ft_strjoin(char **line, char *stack, char **result);
char	*ft_strndup(char *str, size_t n);

#endif