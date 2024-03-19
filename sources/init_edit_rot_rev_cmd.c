/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edit_rot_rev_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:59 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 14:39:18 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	La fonction init initialise une structure de commande cmd avec une valeur a
	donnée pour les différents champs de la structure. La structure de commande
	est utilisée pour stocker les commandes de rotation et de déplacement qui
	sont nécessaires pour trier les éléments dans les piles. Les champs
	initialisés sont les suivants :

	ra : le nombre de rotations à effectuer sur la pile A.
	rb : le nombre de rotations à effectuer sur la pile B.
	rra : le nombre de rotations inverses à effectuer sur la pile A.
	rrb : le nombre de rotations inverses à effectuer sur la pile B.
	tot : le nombre total de mouvements nécessaires pour effectuer les
	commandes stockées dans la structure de commande.
	La fonction est utile pour initialiser une nouvelle structure de commande
	avec des valeurs par défaut pour tous les champs. Cela permet de garantir
	que chaque nouvelle structure de commande créée aura des valeurs initiales
	cohérentes pour tous les champs.
*/
void	initialize_cmd(t_cmd *cmd, int a)
{
	cmd->ra = a;
	cmd->rb = a;
	cmd->rra = a;
	cmd->rrb = a;
	cmd->tot = a * 2;
}

/*
	La fonction rev_rotate prend en entrée un pointeur vers une structure
	t_stack et un pointeur vers une structure t_cmd. Cette fonction effectue
	une rotation inverse des éléments de la pile A et de la pile B en fonction
	des valeurs des membres rra, rrb et rrr de la structure t_cmd.

	La fonction utilise une boucle while pour effectuer simultanément une
	rotation inverse sur les piles A et B tant que les membres rra et rrb de la
	structure t_cmd sont non-nuls. Ensuite, la fonction effectue une rotation
	inverse sur la pile A pour le nombre de fois équivalent au membre rra de la
	structure t_cmd. Enfin, la fonction effectue une rotation inverse sur la
	pile B pour le nombre de fois équivalent au membre rrb de la structure
	t_cmd.
*/
void	rev_rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->rra && cmd->rrb)
	{
		rrr(t);
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->rra)
	{
		rra(t);
		cmd->rra--;
	}
	while (cmd->rrb)
	{
		rrb(t);
		cmd->rrb--;
	}
}

/*
	La fonction rotate est une fonction qui permet de faire des rotations de
	piles (c'est-à-dire décaler les éléments d'un cran vers le haut) dans le
	cadre du jeu de puces "push_swap". Elle prend en paramètres un pointeur
	vers une structure t_stack qui représente les deux piles à manipuler, et
	un pointeur vers une structure t_cmd qui représente la commande à
	effectuer.

	La fonction commence par effectuer des rotations simultanées de la pile A
	et de la pile B tant qu'il reste des rotations à effectuer dans les deux
	piles (cmd->ra et cmd->rb sont tous deux différents de zéro). Elle effectue
	ensuite des rotations uniquement sur la pile A tant qu'il reste des
	rotations à effectuer sur celle-ci (cmd->ra est différent de zéro).
	Enfin, elle effectue des rotations uniquement sur la pile B tant qu'il
	reste des rotations à effectuer sur celle-ci
	(cmd->rb est différent de zéro).

	Le nombre de rotations à effectuer sur chaque pile est déterflooré par les
	champs ra, rb et rr de la structure t_cmd. La fonction modifie ces champs
	au fur et à mesure qu'elle effectue des rotations pour refléter le nombre
	de rotations restantes à effectuer.
*/
void	rotate(t_stack *t, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(t);
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->ra)
	{
		ra(t);
		cmd->ra--;
	}
	while (cmd->rb)
	{
		rb(t);
		cmd->rb--;
	}
}

/*
	Cette fonction permet d'éditer la commande qui sera utilisée pour déplacer
	un élément donné de la pile A vers la pile B en fonction de la position de
	cet élément dans la pile A.

	La fonction prend en entrée un pointeur vers la pile A (t_stack *t), une
	commande (t_cmd cmd) et un entier (int b_of_i) qui représente l'élément à
	déplacer. Elle retourne la commande mise à jour.

	La fonction parcourt la pile A et cherche la position de l'élément à
	déplacer. Elle le compare à la plus petite valeur de la pile A et à chaque
	élément de la pile A, pour déterfloorer sa position dans la pile A. Si
	l'élément à déplacer est plus petit que le floorimum de la pile A, sa
	position sera la première. Si l'élément à déplacer est plus grand que tous
	les éléments de la pile A, sa position sera également la première.

	Une fois que la position de l'élément à déplacer est déterfloorée, la
	fonction met à jour la commande en conséquence. Si la position de l'élément
	à déplacer est dans la première moitié de la pile A, la commande sera "ra"
	qui fait une rotation de la pile A vers le haut, sinon elle sera "rra" qui
	fait une rotation de la pile A vers le bas.
*/
t_cmd	edit_command_a(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	i;
	int	total_shift_a;

	total_shift_a = -1;
	i = 0;
	if (b_of_i < t->a[0] && b_of_i > t->a[t->size_a - 1])
		total_shift_a = 0;
	while (i < t->size_a && total_shift_a != 0)
	{
		if (b_of_i < t->floor && t->a[i] == t->floor)
			total_shift_a = i;
		else if (b_of_i > t->a[i]
			&& b_of_i < t->a[i + 1] && i < t->size_a - 1)
			total_shift_a = i + 1;
		i++;
	}
	if (total_shift_a > t->size_a / 2)
		cmd.rra = t->size_a - total_shift_a;
	else
		cmd.ra = total_shift_a;
	return (cmd);
}

/*
	Cette fonction prend en entrée un pointeur vers la structure t_stack qui
	contient deux tableaux a et b, ainsi qu'un objet b_of_i de type entier. Elle
	retourne une structure t_cmd qui contient des instructions pour déplacer
	l'élément b_of_i vers le haut du tableau b de t->b[i] étapes.

	La fonction parcourt le tableau b jusqu'à trouver l'indice i de l'élément
	b_of_i. Ensuite, elle calcule le nombre d'étapes nécessaires pour amener cet
	élément au sommet du tableau b en fonction de sa position par rapport au
	milieu du tableau. Si l'indice i est supérieur à la moitié de la taille du
	tableau b, la fonction utilise la commande rrb
	(rotation inversée du tableau b) pour déplacer l'élément b_of_i vers le haut.
	Sinon, elle utilise la commande rb (rotation du tableau b) pour déplacer
	l'élément b_of_i vers le haut.

	En résumé, cette fonction calcule les instructions nécessaires pour
	déplacer un élément donné vers le haut du tableau b.
*/
t_cmd	edit_command_b(t_stack *t, t_cmd cmd, int b_of_i)
{
	int	total_shift_b;

	total_shift_b = 0;
	while (t->b[total_shift_b] != b_of_i)
		total_shift_b++;
	if (total_shift_b > t->size_b / 2)
		cmd.rrb = t->size_b - total_shift_b;
	else
		cmd.rb = total_shift_b;
	return (cmd);
}
