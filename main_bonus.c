/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:38:32 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/10 11:30:14 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

int	main(int ac, char *av[])
{
	char	*s;

	// printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	if (ac != 3)
		raise(0);
	int fd1 = open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);
	int i = 1;
	while (i++)
	{
		if (i % 2 == 0)
			s = get_next_line(fd1);
		else
			s = get_next_line(fd2);
		if (!s)
			break ;
		printf("%s", s);
		free(s);
	}
	close(fd1);
	close(fd2);
	return (0);
}
