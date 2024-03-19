/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:41 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/27 13:16:25 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Cette fonction calcule le nombre minimum de rotations nécessaires pour
	réorganiser deux piles a et b avant de les fusionner. Elle prend en entrée
	une structure cmd qui contient les nombres de rotations nécessaires pour
	trier les piles a et b séparément, et retourne une structure cmd qui
	contient le nombre total de rotations nécessaires pour trier les deux
	piles.

	La fonction utilise trois boucles while pour calculer le nombre total de
	rotations nécessaires. La première boucle réduit le nombre de rotations
	nécessaires pour les deux piles simultanément, en supposant que les
	éléments qui nécessitent une rotation sont maintenant alignés. La deuxième
	et la troisième boucle réduisent le nombre de rotations nécessaires pour
	chaque pile individuellement, en supposant que les éléments qui
	nécessitent une rotation sont maintenant au début de la pile.

	La fonction retourne la structure cmd mise à jour avec le nombre total de
	rotations nécessaires pour trier les piles a et b avant de les fusionner.
*/
t_cmd	best_rot(t_cmd cmd)
{
	while (cmd.ra && cmd.rb)
	{
		cmd.ra--;
		cmd.rb--;
		cmd.tot++;
	}
	while (cmd.ra)
	{
		cmd.ra--;
		cmd.tot++;
	}
	while (cmd.rb)
	{
		cmd.rb--;
		cmd.tot++;
	}
	return (cmd);
}

/*
	Cette fonction calcule le nombre minimum de rotations inverses nécessaires
	pour réorganiser deux piles a et b avant de les fusionner. Elle prend en
	entrée une structure cmd qui contient les nombres de rotations inverses
	nécessaires pour trier les piles a et b séparément, et retourne une
	structure cmd qui contient le nombre total de rotations inverses
	nécessaires pour trier les deux piles.

	La fonction utilise trois boucles while pour calculer le nombre total de
	rotations inverses nécessaires. La première boucle réduit le nombre de
	rotations inverses nécessaires pour les deux piles simultanément, en
	supposant que les éléments qui nécessitent une rotation inverse sont
	maintenant alignés. La deuxième et la troisième boucle réduisent le nombre
	de rotations inverses nécessaires pour chaque pile individuellement, en
	supposant que les éléments qui nécessitent une rotation inverse sont
	maintenant à la fin de la pile.

	La fonction retourne la structure cmd mise à jour avec le nombre total de
	rotations inverses nécessaires pour trier les piles a et b avant de les
	fusionner.
*/
t_cmd	best_rev_rot(t_cmd cmd)
{
	while (cmd.rra && cmd.rrb)
	{
		cmd.rra--;
		cmd.rrb--;
		cmd.tot++;
	}
	while (cmd.rra)
	{
		cmd.rra--;
		cmd.tot++;
	}
	while (cmd.rrb)
	{
		cmd.rrb--;
		cmd.tot++;
	}
	return (cmd);
}

/*
	Cette fonction choisit la meilleure option entre deux structures cmd en
	calculant le nombre minimum de rotations nécessaires et le nombre floorimum
	de rotations inverses nécessaires pour trier les piles a et b avant de les
	fusionner.

	La fonction prend en entrée deux structures cmd, cmd et cmd_best. Elle crée
	une copie de cmd dans la structure clone. Ensuite, elle calcule le nombre
	floorimum de rotations nécessaires et le nombre floorimum de rotations inverses
	nécessaires en appelant les fonctions best_rot() et best_rev_rot() sur cmd.
	La fonction met à jour le champ tot de la structure cmd avec le nombre
	total de rotations nécessaires.

	Ensuite, la fonction compare le nombre total de rotations nécessaires de
	cmd avec celui de cmd_best. Si cmd est plus efficace que cmd_best, elle met
	à jour la structure cmd_best avec clone.

	La fonction retourne la structure cmd_best mise à jour.
*/
t_cmd	choose_best(t_cmd cmd, t_cmd cmd_best)
{
	t_cmd	clone;

	clone = cmd;
	cmd = best_rot(cmd);
	cmd = best_rev_rot(cmd);
	clone.tot = cmd.tot;
	if (cmd_best.tot > cmd.tot)
		cmd_best = clone;
	return (cmd_best);
}

/*
	Cette fonction place l'élément le plus petit de la pile a en haut de la
	pile, en le faisant glisser jusqu'à l'extrémité supérieure de la pile.
	Elle utilise la condition de l'élément le plus petit pour déterminer dans
	quelle direction faire pivoter la pile a.

	La fonction commence par vérifier si l'élément le plus petit est plus
	proche du haut ou du bas de la pile a. Si l'élément le plus petit est plus
	proche du haut, la fonction pivote la pile a vers le haut en appelant la
	fonction ra() jusqu'à ce que l'élément le plus petit se trouve en haut de
	la pile. Si l'élément le plus petit est plus proche du bas, la fonction
	pivote la pile a vers le bas en appelant la fonction rra() jusqu'à ce que
	l'élément le plus petit se trouve en haut de la pile.

	En résumé, cette fonction place l'élément le plus petit de la pile a en
	haut de la pile en le faisant glisser jusqu'à l'extrémité supérieure de la
	pile.
*/
void	end(t_stack *t)
{
	if (t->a[0] <= t->size_a / 2 + 1)
		while (t->a[0] != 1)
			rra(t);
	else
		while (t->a[0] != 1)
			ra(t);
}

/*
	Cette fonction insère les éléments de la pile b dans la pile a en utilisant
	des rotations pour trouver la position optimale de chaque élément dans la
	pile a. Elle utilise des fonctions auxiliaires pour éditer des commandes
	pour chaque élément et choisir la meilleure option de rotation pour insérer
	chaque élément.

	La fonction commence par initialiser deux structures cmd, cmd_best et cmd,
	pour stocker les commandes nécessaires à la rotation des éléments de la
	pile b. Ensuite, elle utilise une boucle while pour itérer sur chaque
	élément de la pile b. Pour chaque élément de la pile b, la fonction appelle
	des fonctions auxiliaires edit_command_a() et edit_command_b() pour éditer
	les commandes pour chaque rotation de la pile a et de la pile b nécessaires
	pour insérer l'élément dans la pile a.

	La fonction utilise ensuite la fonction choose_best() pour choisir la
	meilleure option de rotation pour insérer chaque élément dans la pile a.
	Elle stocke cette option dans la structure cmd_best.

	Enfin, la fonction utilise les fonctions rotate() et rev_rotate() pour
	effectuer la meilleure option de rotation pour insérer l'élément dans la
	pile a. Elle déplace l'élément de la pile b dans la pile a en appelant la
	fonction pa(). La fonction met également à jour le champ floor de la
	structure t avec la valeur de l'élément le plus petit de la pile a.

	En résumé, cette fonction insère les éléments de la pile b dans la pile a
	en utilisant des rotations pour trouver la position optimale de chaque
	élément dans la pile a.
*/
void	insert_b_to_a(t_stack *t)
{
	t_cmd	cmd_best;
	t_cmd	cmd;
	int		i;

	initialize_cmd(&cmd, 0);
	while (t->size_b)
	{
		initialize_cmd(&cmd_best, 100000);
		i = 0;
		while (i < t->size_b)
		{
			cmd = edit_command_a(t, cmd, t->b[i]);
			cmd = edit_command_b(t, cmd, t->b[i]);
			cmd_best = choose_best(cmd, cmd_best);
			i++;
			initialize_cmd(&cmd, 0);
		}
		rotate(t, &cmd_best);
		rev_rotate(t, &cmd_best);
		pa(t);
		if (t->a[0] < t->floor)
			t->floor = t->a[0];
	}
}
