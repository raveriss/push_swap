/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_swap_or_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:56 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 10:25:23 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sa(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
	write(1, "sa\n", 3);
}

/*
	Intervertit les 2 premiers éléments au sommet de la pile b.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sb(t_stack *t)
{
	int	tmp;

	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
	write(1, "sb\n", 3);
}

/*
	pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/
void	pb(t_stack *t)
{
	int	i;
	int	stmp_b;

	i = 0;
	stmp_b = t->size_b;
	while (stmp_b > 0)
	{
		t->b[stmp_b] = t->b[stmp_b - 1];
		stmp_b--;
	}
	t->b[0] = t->a[0];
	while (i < t->size_a - 1)
	{
		t->a[i] = t->a[i + 1];
		i++;
	}
	t->size_a -= 1;
	t->size_b += 1;
	write(1, "pb\n", 3);
}

/*
	pa (push a) : Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/
void	pa(t_stack *t)
{
	int	i;
	int	stmp_a;

	i = 0;
	stmp_a = t->size_a;
	while (stmp_a > 0)
	{
		t->a[stmp_a] = t->a[stmp_a - 1];
		stmp_a--;
	}
	t->a[0] = t->b[0];
	while (i < t->size_b - 1)
	{
		t->b[i] = t->b[i + 1];
		i++;
	}
	t->size_a += 1;
	t->size_b -= 1;
	write(1, "pa\n", 3);
}
