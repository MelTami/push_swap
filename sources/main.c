/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:57:58 by mvavasso          #+#    #+#             */
/*   Updated: 2023/01/28 00:31:34 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_stack(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else
	{
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]))
				ft_error();
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 3)
		check_stack(argc, argv);
	stack = argv;
	ft_check(stack);
	return (0);
}
