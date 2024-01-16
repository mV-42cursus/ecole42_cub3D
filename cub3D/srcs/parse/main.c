/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:07 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:25:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_data	*data;
	int		fd;

	data = NULL;
	fd = 0;
	if (ac != 2)
		ft_exit("Error\nInvalid number of arguments.", 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit("Error\nopen Error", 1);
	data = ft_calloc_exit(1, sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	ft_memset(data, 0, sizeof(data));
	if (wrong_format(av[1]))
		ft_exit("Error\nInvalid file format", 1);
	parse(data, av[1]);
	return (0);
}
