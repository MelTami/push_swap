/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:25:56 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 18:03:49 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	void	*first;
	void	*second;

	if (stack->size < 2)
		return ;
	first = stack_pop(stack);
	second = stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size > 1)
	{
		ft_putendl_fd("sa", 1);
		swap(a);
	}
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->size > 1)
	{
		ft_putendl_fd("sb", 1);
		swap(b);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_putendl_fd("ss", 1);
		swap(a);
		swap(b);
	}
}
