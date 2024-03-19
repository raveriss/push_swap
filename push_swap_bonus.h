/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:56:17 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 09:48:01 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	min;
	int	max;
}		t_stack;

void	sa(t_stack *t);
void	sb(t_stack *t);
void	ss(t_stack *t);
void	pb(t_stack *t);
void	pa(t_stack *t);
void	ra(t_stack *t);
void	rb(t_stack *t);
void	rr(t_stack *t);
void	rra(t_stack *t);
void	rrb(t_stack *t);
void	rrr(t_stack *t);
int		check_arg(int argc, char **argv);
int		is_sort(t_stack *t);
t_stack	edit(int argc, char **argv);
int		clean(t_stack *t);
long	ft_atol(const char *nptr);

#endif
