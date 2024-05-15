/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:27 by hbutt             #+#    #+#             */
/*   Updated: 2024/05/15 16:06:42 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// int	ft_verif_nl(char *str)
// {
// 	size_t i;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

#include "get_next_line.h"

/* va liberer la memoire allouee pour la chaine mise en parametre */
char	*ft_free_all(char **str1)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	return (0);
}

/* verifie s'il y a un '\n' dans la chaine de caracteres */
int	ft_not_nl_static(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

/* calcule la longueur de str, et free la string si elle est NULL */
static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		free(str);
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

/* concatene 2 chaines de caracteres en une seule en ayant prealablement allouee 
	dynamiquement la nouvelle chaine */
char	*ft_strjoingnl(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join;

	size = ft_strlen(str1) + ft_strlen(str2);
	if (size == 0)
		return (ft_free_all(&str1));
	join = malloc(sizeof(char) * (size + 1));
	if (!join)
		return (ft_free_all(&str1));
	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i] && j < size)
			join[j++] = str1[i++];
	}
	i = 0;
	while (str2[i] && j < size)
		join[j++] = str2[i++];
	join[j] = '\0';
	free(str1);
	return (join);
}