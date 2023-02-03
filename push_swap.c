/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:57:58 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/03 18:12:49 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			ft_error();
		i++;
	}			
}

static int	is_equal(void *content, void *data)
{
	return (*(int *)content == *(int *)data);
}

static int	check_stack(int argc, char *argv[], t_stack *stack)
{
	long int	temp;
	int			*content;

	while (argc)
	{
		ft_check(argv[argc - 1]);
		temp = ft_atol(argv[argc-- - 1]);
		if (temp > MAX_INT || temp < MIN_INT)
			ft_error();
		content = (int *) malloc(sizeof(*content));
		if (!content)
			return (0);
		*content = (int)temp;
		if (stack->head && ft_lstfind(stack->head, content, is_equal))
			ft_error();
		stack_push(stack, content);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	if (argc == 1)
		return (0);
	check_stack(argc - 1, &argv[1], &a);
	if (!is_sorted(a.head))
	{
		if (a.size < 4)
			sort_small(&a, &b);
		if (a.size < 6)
			sort_mid(&a, &b);
		else
			sort_big(&a, &b);
	}
	ft_lstclear(&a.head, free);
	return (0);
}
