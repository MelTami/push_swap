/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:01:55 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/01 14:12:56 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
