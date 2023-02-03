/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:29:32 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 20:57:19 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = *(int *)get_min(a->head);
	max = *(int *)get_max(a->head);
	while (!is_sorted(a->head))
	{
		if (*(int *)a->head->content == max
			&& *(int *)a->head->next->content == min)
			ra(a, b);
		else if ((*(int *)a->head->content == min
				&& *(int *)a->head->next->content == max)
			|| (*(int *)a->head->content > *(int *)a->head->next->content))
			sa(a, b);
		else
			rra(a, b);
	}
}

static void	part_mid(t_stack *a, t_stack *b)
{
	int	median;
	int	middle;

	median = stack_median(a);
	middle = a->size / 2;
	while (middle)
	{
		if (*(int *)a->head->content < median)
		{
			middle--;
			pb(a, b);
		}
		else
			ra(a, b);
	}
}

void	sort_mid(t_stack *a, t_stack *b)
{
	part_mid(a, b);
	sort_small(a, b);
	if (is_sorted(b->head))
		sb(a, b);
	while (b->size)
		pa(a, b);
}

static void	index_stack(t_stack *stack)
{
	int		i;
	t_list	*list;
	t_list	*sorted;
	t_list	*temp_sorted;

	sorted = ft_lstdup_int(stack->head);
	ft_lstsort(sorted, 0, stack->size - 1);
	list = stack->head;
	while (list)
	{
		temp_sorted = sorted;
		i = 0;
		while (i < stack->size)
		{
			if (*(int *)list->content == *(int *)temp_sorted->content)
			{
				*(int *)list->content = i;
				break ;
			}
			temp_sorted = temp_sorted->next;
			i++;
		}
		list = list->next;
	}
	ft_lstclear(&sorted, free);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	num;
	int	size;

	index_stack(a);
	size = a->size;
	i = 0;
	while (!is_sorted(a->head))
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)a->head->content;
			if ((num >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
			j++;
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}
