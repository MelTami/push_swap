/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:18:11 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 18:03:13 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_push(t_stack *stack, void *content)
{
	t_list	*head;

	head = ft_lstnew(content);
	head->next = stack->head;
	stack->head = head;
	stack->size++;
}

void	*stack_pop(t_stack *stack)
{
	t_list	*head;
	void	*content;

	if (!stack->head)
		return (NULL);
	head = stack->head;
	content = head->content;
	stack->head = head->next;
	stack->size--;
	free(head);
	return (content);
}

void	stack_shift(t_stack *stack, void *content)
{
	t_list	*last;

	last = ft_lstlast(stack->head);
	last->next = ft_lstnew(content);
	stack->size++;
}

void	*stack_unshift(t_stack *stack)
{
	t_list	*last;
	t_list	*before;
	void	*content;

	if (!stack->head)
		return (NULL);
	last = ft_lstlast(stack->head);
	content = last->content;
	if (stack->size > 1)
	{
		before = ft_lstat(stack->head, stack->size - 2);
		before->next = NULL;
	}
	stack->size--;
	free(last);
	return (content);
}

int	stack_median(t_stack *stack)
{
	t_list	*dup;
	t_list	*temp;
	int		middle;
	int		median;

	dup = ft_lstdup_int(stack->head);
	middle = stack->size / 2;
	ft_lstsort(dup, 0, stack->size - 1);
	temp = dup;
	while (middle--)
		temp = temp->next;
	median = *(int *)temp->content;
	ft_lstclear(&dup, free);
	return (median);
}
