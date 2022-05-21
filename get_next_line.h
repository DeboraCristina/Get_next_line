/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:28:18 by desilva           #+#    #+#             */
/*   Updated: 2022/05/22 01:28:20 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

// utils
int		ft_strlen(const char *s);

char	*ft_strjoin(char const *str01, char const *str02);

char	*ft_strchr(const char *s, int c);

void	ft_bzero(void *s, size_t n);

#endif
