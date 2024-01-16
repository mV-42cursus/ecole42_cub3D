/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:32:07 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:13:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_nodes(t_data *data)
{
	t_node	*p;

	while (data->map_src)
	{
		p = NULL;
		p = data->map_src;
		data->map_src = data->map_src->next;
		free(p->content);
		free(p);
	}
}
