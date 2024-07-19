/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:30:40 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/19 06:47:56 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	newstr = malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

// int	main()
// {
// 	char	*newstr = ft_strjoin("je fais ", "des tests!");
// 	printf("%s\n", newstr);
// 	free(newstr);
// 	return (0);
// }
