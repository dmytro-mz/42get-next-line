/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:38:32 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/07 18:58:18 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		fd;

	printf("%d\n", BUFFER_SIZE);
	fd = 0;
	// int fd = open("text.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
		printf("%s", s);
	close(fd);
	return (0);
}
