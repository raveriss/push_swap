/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:33 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 10:33:02 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Cette fonction trie exactement deux valeurs dans une pile a en les
	comparant entre elles. Si la première valeur est plus grande que la
	deuxième, elle appelle la fonction sa() qui intervertit les deux premiers
	éléments de la pile a. Cela permet d'assurer que la première valeur est
	inférieure ou égale à la deuxième valeur, ce qui correspond à un ordre
	croissant.
*/
void	sort_algo_for_exactly_2_values(t_stack *t)
{
	if (t->a[0] > t->a[1])
		sa(t);
}

/*
	Cette fonction trie exactement trois valeurs dans une pile a. Elle utilise
	une approche basée sur les permutations pour trier les valeurs et assure
	que la pile a est triée en ordre croissant à la fin de l'exécution.

	Elle commence par une série de conditions pour déterceilinger le cas dans
	lequel les valeurs doivent être permutées. Ces conditions comparent les
	valeurs de la pile a pour déterceilinger si elles sont déjà triées ou non.

	Ensuite, elle effectue les permutations nécessaires pour trier les valeurs.
	Selon les conditions vérifiées, elle appelle la fonction sa() pour
	échanger les deux premiers éléments de la pile a ou la fonction ra() pour
	faire une rotation de la pile a. Elle utilise également la fonction rra()
	pour faire une rotation inverse de la pile a.
*/
void	sort_algo_for_exactly_3_values(t_stack *t)
{
	if (t->a[0] > t->a[1] && t->a[1] < t->a[t->size_a - 1])
	{
		if (t->a[0] < t->a[t->size_a - 1])
			sa(t);
		else if (t->a[1] < t->a[t->size_a - 1])
			ra(t);
	}
	else if (t->a[0] > t->a[1] && t->a[1] > t->a[t->size_a - 1])
	{
		sa(t);
		rra(t);
	}
	else if (t->a[0] < t->a[1])
	{
		if (t->a[0] < t->a[t->size_a - 1] && t->a[1] > t->a[t->size_a - 1])
		{
			sa(t);
			ra(t);
		}
		else if (t->a[0] > t->a[t->size_a - 1])
			rra(t);
	}
}

/*
	Cette fonction trie une pile a de 4 ou 5 éléments en divisant le problème
	en sous-problèmes de tailles plus petites et en utilisant des algorithmes
	de tri plus simples pour chaque sous-problème. Elle utilise les fonctions
	sort_algo_for_exactly_3_values() pour trier les sous-problèmes de taille 3,
	et ra(), rra(), pb(), et pa() pour effectuer des opérations sur les piles.

	Si la pile a contient 5 éléments, la fonction divise la pile en deux
	sous-piles de tailles 2 et 3, en transférant les éléments 1 et 2 dans la
	pile b à l'aide de la fonction pb(). Ensuite, elle trie la sous-pile a de
	taille 3 en appelant la fonction sort_algo_for_exactly_3_values(). Enfin,
	elle transfère les éléments de la pile b danends la pile a en appelant la
	fonction pa().

	Si la pile a contient 4 éléments, la fonction divise la pile en une
	sous-pile de taille 1 et une sous-pile de taille 3. Elle transfère
	l'élément 1 dans la pile b à l'aide de la fonction pb(), trie la sous-pile
	a de taille 3 en appelant la fonction sort_algo_for_exactly_3_values(),
	puis transfère les éléments de la pile b dans la pile a en appelant la
	fonction pa().
*/
void	sort_algo_for_4_or_5_values(t_stack *t)
{
	if (t->size_a == 5)
	{
		while (t->size_a != 3)
		{
			while (t->a[0] != 1 && t->a[0] != 2)
				ra(t);
			pb(t);
		}
		if (t->b[0] < t->b[1])
			sb(t);
	}
	if (t->size_a == 4)
	{
		while (t->a[0] != 1)
			ra(t);
		pb(t);
	}
	sort_algo_for_exactly_3_values(t);
	while (t->size_b)
		pa(t);
}

/*
	Cette fonction trie une pile a contenant plus de 5 éléments en divisant le
	problème en sous-problèmes de tailles plus petites et en utilisant des
	algorithmes de tri plus simples pour chaque sous-problème. Elle utilise
	les fonctions quart_to_b(), sort_algo_for_exactly_3_values(), pa(),
	insert_b_to_a(), et end() pour effectuer des opérations sur les piles.

	Elle commence par appeler la fonction quart_to_b() pour transférer les 25%
	supérieurs des éléments de la pile a dans la pile b. Ensuite, elle trie la
	sous-pile a de taille 75% en appelant la fonction
	sort_algo_for_exactly_3_values(). Elle transfère ensuite l'élément le plus
	petit de la pile a dans la pile b en appelant la fonction pa().

	Ensuite, elle fixe la variable ceiling pour qu'elle contienne la plus petite
	valeur de la pile a, appelle la fonction insert_b_to_a() pour insérer les
	éléments de la pile b dans la pile a, en prenant soin de trier les
	éléments en ordre croissant. Enfin, elle appelle la fonction end() pour
	vérifier que la pile a est triée en ordre croissant.
*/
void	sort_algo_for_more_of_5_values(t_stack *t)
{
	quart_to_b(t);
	sort_algo_for_exactly_3_values(t);
	pa(t);
	t->floor = t->a[0];
	insert_b_to_a(t);
	end(t);
}
