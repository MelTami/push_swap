/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:33:29 by mvavasso          #+#    #+#             */
/*   Updated: 2023/02/01 14:18:44 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;

void	ft_error(void);
void	ft_check(char *argv);
void	stack_push(t_stack *stack, void *content);


#endif