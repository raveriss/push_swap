/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_swa_or_pus_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:40 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 09:47:53 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../get_next_line.h"

void	sa(t_stack *t)
{
	int	tmp;

	tmp = t->a[0];
	t->a[0] = t->a[1];
	t->a[1] = tmp;
}

void	sb(t_stack *t)
{
	int	tmp;

	tmp = t->b[0];
	t->b[0] = t->b[1];
	t->b[1] = tmp;
}

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
}

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
}
