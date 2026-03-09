/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:15 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/09 12:57:46 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		read_more(const int fd, char **buffer, int *read_res);
int		buffer_update(char **buffer, char **read_str, const int read_res);
void	ft_strmove(char **dest, char **src, const int start, const int end);
int		check_linebreak(const char *str, int *break_pos, const int read_res);
int		get_line(char **str, char **buffer, const int break_pos);
int		clean_buffer(char **buffer, const char *str);
int		init_buffer(char **buffer);
void	free_memory(char **str);

#endif
