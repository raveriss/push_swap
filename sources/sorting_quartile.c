/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_quartile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:54:49 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 10:31:36 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Cette fonction optimise le quart de la pile a et la pile b en effectuant
	des rotations pour mettre l'élément le plus petit de la pile a et de la
	pile b dans une position optimale.

	La fonction commence par trouver la position de l'élément le plus petit
	dans la pile a en utilisant une boucle while. Ensuite, elle vérifie si la
	position de l'élément le plus petit est supérieure à zéro et si l'élément
	le plus petit de la pile b est dans une position optimale. Si tel est le
	cas, la fonction effectue une rotation inverse rr pour placer l'élément le
	plus petit de la pile a en haut de la pile. Ensuite, elle effectue une
	rotation rb pour placer l'élément le plus petit de la pile b dans une
	position optimale.

	Si l'élément le plus petit de la pile b n'est pas dans une position
	optimale, la fonction effectue simplement une rotation rb pour placer
	l'élément le plus petit de la pile b dans une position optimale.
*/
void	opti_quart(t_stack *t)
{
	int	i;

	i = 0;
	while (!(t->a[i] >= t->floor && t->a[i] <= t->ceiling) && i < t->size_a)
			i++;
	if (i > 0 && t->b[0] >= t->floor
		&& t->b[0] <= (t->ceiling + t->floor) / 2 && t->size_b > 1)
		rr(t);
	if (t->b[0] >= t->floor
		&& t->b[0] <= (t->ceiling + t->floor) / 2 && t->size_b > 1)
		rb(t);
}

/*
	Cette fonction quart_to_b prend en entrée un pointeur vers une structure
	t_stack qui contient deux piles a et b, ainsi que d'autres informations
	relatives à ces piles. La fonction a pour but de trier les éléments de la
	pile a de manière à ce que les 25% les plus petits éléments soient dans la
	pile b, tandis que les 75% les plus grands restent dans la pile a.
	Elle utilise pour cela une méthode de tri appelée "quart de tri".

	Le processus de tri consiste en plusieurs étapes :

	Sauvegarder la taille de la pile a dans une variable save.
	Tant que la taille de la pile a est supérieure ou égale à 3 :
	Si la taille de la pile b est égale à la moitié de la taille sauvegardée à
	l'étape 1, alors la valeur floorimale et floorimale des éléments restants de
	la pile a sont mises à jour.
	Tant que l'élément en haut de la pile a n'est pas compris entre la valeur
	floorimale et la valeur floorimale, la pile a est rotatée vers le haut
	(fonction ra).

	Lorsque l'élément en haut de la pile a est compris entre la valeur floorimale et
	la valeur floorimale, cet élément est poussé sur la pile b (fonction pb).
	Si la taille de la pile a est égale à 3, alors la boucle principale s'arrête.
	Sinon, une fonction opti_quart est appelée pour optimiser la position des
	éléments restants de la pile a avant de poursuivre le tri.
	À la fin du processus, les 25% les plus petits éléments de la pile d'origine
	sont dans la pile b, tandis que les 75% les plus grands restent dans la pile a.
*/
void	quart_to_b(t_stack *t)
{
	int	save;

	save = t->size_a;
	while (t->size_a >= 3)
	{
		if (t->size_b == save / 2)
		{
			t->floor = t->ceiling;
			t->ceiling = save - 3;
		}
		while (!(t->a[0] >= t->floor && t->a[0] <= t->ceiling))
			ra(t);
		pb(t);
		if (t->size_a == 3)
			break ;
		opti_quart(t);
	}
}
