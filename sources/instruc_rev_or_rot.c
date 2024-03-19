/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_rev_or_rot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:07 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 10:26:01 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	ra (rotate a) : Décale d’une position vers le haut tous les élements de la
	pile a. Le premier élément devient le dernier
*/
void	ra(t_stack *t)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->a[t->size_a - 1] = tmp;
	write(1, "ra\n", 3);
}

/*
	rb (rotate b) : Décale d’une position vers le haut tous les élements de la
	pile b. Le premier élément devient le dernier.
*/
void	rb(t_stack *t)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->b[t->size_b - 1] = tmp;
	write(1, "rb\n", 3);
}

/*
	rra (reverse rotate a) : Décale d’une position vers le bas tous les
	élements de la pile a. Le dernier élément devient le premier.
*/
void	rra(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_a;
	tmp = t->a[size - 1];
	while (size > 1)
	{
		t->a[size - 1] = t->a[size - 2];
		size--;
	}
	t->a[0] = tmp;
	write(1, "rra\n", 4);
}

/*
	rrb (reverse rotate b) : Décale d’une position vers le bas tous les
	élements de la pile b. Le dernier élément devient le premier.
*/
void	rrb(t_stack *t)
{
	int	tmp;
	int	size;

	size = t->size_b;
	tmp = t->b[size - 1];
	while (size > 1)
	{
		t->b[size - 1] = t->b[size - 2];
		size--;
	}
	t->b[0] = tmp;
	write(1, "rrb\n", 4);
}
