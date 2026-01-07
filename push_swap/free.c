/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <carmenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:26:21 by carmenga          #+#    #+#             */
/*   Updated: 2026/01/07 10:26:22 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_stack *stackA)
{
	t_stack	*temp;

	while (stackA)
	{
		temp = stackA;
		stackA = stackA->next;
		free(temp);
	}
}

void	freesplit(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
