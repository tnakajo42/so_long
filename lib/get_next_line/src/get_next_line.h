/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:09:35 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/17 22:12:36 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_next_line_sub(char **str_line, char **str_buff);
char	*get_next_line_with_n(char **str_line, char **str_buff, int fb);
void	ft_str_free(char **str);
int		ft_str_len(char *str);
int		ft_str_char(char *str, int c);
char	*ft_str_dup_b(char *str, int c);
char	*ft_str_dup_a(char *str, int c);
char	*ft_str_cat(char *str_line, char *str_buff);
void	ft_str_cat_sub(char *dest, char *src, int start);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

#endif