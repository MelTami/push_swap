/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:13 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 17:59:42 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	print_stack(t_stack	*stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	temp = stack->head;
	while (temp)
	{
		ft_printf("|%d|\n", *(int *)temp->content);
		temp = temp->next;
	}
}

void	*get_max(t_list *list)
{
	void	*max;

	if (!list)
		return (NULL);
	max = list->content;
	while (list)
	{
		if (*(int *)list->content > *(int *)max)
			max = list->content;
		list = list->next;
	}
	return (max);
}

void	*get_min(t_list *list)
{
	void	*min;

	if (!list)
		return (NULL);
	min = list->content;
	while (list)
	{
		if (*(int *)list->content < *(int *)min)
			min = list->content;
		list = list->next;
	}
	return (min);
}
