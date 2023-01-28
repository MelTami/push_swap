/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:57:58 by mvavasso          #+#    #+#             */
/*   Updated: 2023/01/28 01:17:55 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_stack(int argc, char *argv[], t_stack *stack)
{
	long int	temp;
	int			content;

	if (argc == 1)
		exit(EXIT_FAILURE);
	while (argc)
	{
		ft_check(argv[argc - 1]);
		temp = ft_atol(argv[argc-- - 1]);
		if (temp > MAX_INT || temp < MIN_INT)
			ft_error();
		content = (int *) malloc(sizeof(*content));
		if (!content)
			ft_error();
		*content = (int)temp;
		
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	check_stack(argc, argv, &a);
	return (0);
}
