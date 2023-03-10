/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:01:15 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 18:06:30 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		ft_putendl_fd("pa", 1);
		stack_push(a, stack_pop(b));
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		ft_putendl_fd("pb", 1);
		stack_push(b, stack_pop(a));
	}
}
