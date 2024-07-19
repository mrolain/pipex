/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:33:17 by mrolain           #+#    #+#             */
/*   Updated: 2024/07/19 02:38:54 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>

int	main(int argc, char ** argv)
{
	(void)argc;
	printf("your string is %d", ft_strlen(argv[1]));
	printf(" char long.\n");
	return (0);
}*/

/*GOOD*/
