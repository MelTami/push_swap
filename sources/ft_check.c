/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:01:55 by mvavasso          #+#    #+#             */
/*   Updated: 2023/01/28 00:32:36 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check(t_stack *stack)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	while (stack[i])
	{
		while (stack[i][aux])
		{
			if (!ft_isdigit(stack[i][aux]))
				ft_error();
			aux++;
		}
		i++;
	}			
}
