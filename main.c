/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:38:32 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/10 11:19:10 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	char	*s;
	int		fd;

	// printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	// char *a = (char *)malloc(2);
	// a++;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
	if (ac == 3)
	{
		// char *a = "";
		// a++;
		// a[100] = 1;
		fprintf(stderr, "%s - BUFFER_SIZE: %d\n", av[0], BUFFER_SIZE);
	}
	return (0);
}
