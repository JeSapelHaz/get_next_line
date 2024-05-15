/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:00 by hbutt             #+#    #+#             */
/*   Updated: 2024/05/15 15:43:28 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// #include <unistd.h>
// #include <stdlib.h>

// char	*get_next_line(int fd);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_not_nl_static(char *str);
char	*ft_strjoingnl(char *str1, char *str2);
char	*ft_free_all(char **str1);

#endif