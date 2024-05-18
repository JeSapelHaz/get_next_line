/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:14 by hbutt             #+#    #+#             */
/*   Updated: 2024/05/17 21:16:27 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* va renvoyer dest en ayant copié tous les caractères de la stach en param
	jusqu'au '\n' */
static char	*ft_stach_in_line(char *stach)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!stach)
		return (0);
	i = 0;
	while (stach[i] && stach[i] != '\n')
		i++;
	if (stach[i] && stach[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	j = 0;
	while (j < i)
	{
		dest[j] = stach[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/* va renvoyer la string en param en commencant qu'à partir de \n
	dans une nouvelle string */
static char	*ft_stach_wt_line(char *stach)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stach)
		return (ft_free_all(&stach));
	while (stach[i] && stach[i] != '\n')
		i++;
	if (stach[i] && stach[i] == '\n')
		i++;
	j = 0;
	if (!stach[i])
		return (ft_free_all(&stach));
	while (stach[i + j])
		j++;
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (ft_free_all(&stach));
	j = 0;
	while (++j && stach[i + j - 1])
		dest[j - 1] = stach[i + j - 1];
	dest[j - 1] = '\0';
	free(stach);
	return (dest);
}

/* va lire le fichier en lisant BUFFER_SIZE caractères jusqu'à qu'un retour
	à la ligne soit trouvé ou fin du fichier et va faire appel à une autre
	fonction pour join la staching va être renvoyée avec le buffer */
static char	*ft_find_end_line(int fd, char *stach)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_ret;

	read_ret = 1;
	while (ft_no_nl_next(stach) && read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (ft_free_all(&stach));
		buffer[read_ret] = '\0';
		stach = ft_strjoin_gnl(stach, buffer);
	}
	return (stach);
}

/* fonction "principale" qui va appeler toutes les autres fontions et renvoyer
	la prochaine ligne (la première si c'est le premier appel de la fonction) */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stach;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stach)
	{
		stach = malloc(sizeof(char) + 1);
		if (!stach)
			return (ft_free_all(&stach));
		stach[0] = '\0';
	}
	stach = ft_find_end_line(fd, stach);
	line = ft_stach_in_line(stach);
	if (!line)
		return (ft_free_all(&stach));
	stach = ft_stach_wt_line(stach);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	int fd = open("fuckajit.txt", O_RDONLY);
// 	int i = 0;
// 	while(i < 20)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// }