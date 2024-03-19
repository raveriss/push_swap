/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:56:25 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 09:48:04 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	floor;
	int	ceiling;
}		t_stack;

typedef struct cmd
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	tot;
}		t_cmd;

int		*ft_convert_rela_to_abso(int *tab, int size);
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
void	initialize_cmd(t_cmd *cmd, int a);
void	rev_rotate(t_stack *t, t_cmd *cmd);
void	rotate(t_stack *t, t_cmd *cmd);
void	opti_quart(t_stack *t);
void	quart_to_b(t_stack *t);
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i);
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i);
t_cmd	best_rot(t_cmd cmd);
t_cmd	best_rev_rot(t_cmd cmd);
t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best);
void	end(t_stack *t);
void	insert_b_to_a(t_stack *t);
void	sort_algo_for_more_of_5_values(t_stack *t);
void	sort_algo_for_4_or_5_values(t_stack *t);
void	sort_algo_for_exactly_3_values(t_stack *t);
int		check_arg(int argc, char **argv);
int		is_sort(t_stack *t);
void	sort_algo_for_exactly_2_values(t_stack *t);
t_stack	initialize_stack(int argc, char **argv);
void	clean(t_stack *t);
long	ft_atol(const char *nptr);

#endif
