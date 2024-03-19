/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:16 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 13:13:22 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../get_next_line.h"

/*
	initialize_stack() prend en entrée les arguments passés au programme,
	stocke les valeurs dans un tableau d'entiers et renvoie une structure
	t_stack contenant deux tableaux d'entiers (a et b) et leur taille
	respective (size_a et size_b).

	Dans un premier temps, la fonction initialise la taille de chaque tableau
	à zéro et alloue de la mémoire pour chacun des tableaux, en fonction du
	nombre d'arguments passés moins 1 (puisque le premier argument est le nom
	du programme). Si l'allocation échoue, la fonction renvoie la structure t
	initialisée précédemment.

	Ensuite, la fonction parcourt les arguments un par un, convertit chaque
	chaîne de caractères en entier à l'aide de la fonction ft_atol() et stocke
	la valeur obtenue dans le tableau a. La taille de ce tableau est
	incrémentée à chaque itération.

	Finalement, la fonction initialise les variables floor et ceiling de la
	structure t_stack, qui correspondent respectivement à l'indice floorimum
	et ceilingimum des éléments du tableau a. Ici, floor est initialisé à 0 et
	ceiling est initialisé à la moitié de la taille du tableau a.
*/
t_stack	edit(int argc, char **argv)
{
	t_stack	t;

	t.size_a = 0;
	t.size_b = 0;
	t.a = malloc(sizeof(int) * (argc - 1));
	t.b = malloc(sizeof(int) * (argc - 1));
	if (!t.a || !t.b)
		return (t);
	while (t.size_a < argc - 1)
	{
		t.a[t.size_a] = ft_atol(argv[t.size_a + 1]);
		t.size_a++;
	}
	t.min = 0;
	t.max = t.size_a / 2;
	return (t);
}

/*
	exec_commands() est une fonction de dispatcher qui prend en entrée un
	pointeur vers une structure de pile t_stack, un nombre entier nb et un
	caractère c.

	La fonction utilise une série de conditions if/else if pour appeler une
	fonction spécifique en fonction de la combinaison de nb et c. Le numéro nb
	est utilisé pour identifier la fonction spécifique à appeler et le
	caractère c est utilisé pour identifier le type d'opération à effectuer
	(rotation, swap ou push). Si la fonction appelée renvoie une valeur
	différente de 1, cela signifie qu'une erreur s'est produite, et la fonction
	écrit "error\n" sur la sortie d'erreur standard.

	Les fonctions appelées par cette fonction sont vraisemblablement des
	fonctions qui effectuent des opérations spécifiques sur les piles t_stack,
	comme effectuer une rotation, un swap, un push, etc.
*/
void	exec_commands(t_stack *t, int nb, char c)
{
	if (nb == 211 && c == 'r')
		ra(t);
	else if (nb == 212 && c == 'r')
		rb(t);
	else if (nb == 325 && c == 'r')
		rra(t);
	else if (nb == 326 && c == 'r')
		rrb(t);
	else if (nb == 210 && c == 'p')
		pb(t);
	else if (nb == 209 && c == 'p')
		pa(t);
	else if (nb == 212 && c == 's')
		sa(t);
	else if (nb == 213 && c == 's')
		sb(t);
	else if (nb == 230 && c == 's')
		ss(t);
	else if (nb == 228 && c == 'r')
		rr(t);
	else if (nb == 342 && c == 'r')
		rrr(t);
	else
		write (2, "error\n", 6);
}

/*
	read_commands() lit des instructions depuis l'entrée standard et les
	exécute sur la pile t.

	La fonction commence par appeler la fonction get_next_line(0) pour
	récupérer la prochaine ligne de l'entrée standard. Tant qu'il y a une ligne
	disponible, la fonction exécute une boucle while qui parcourt tous les
	caractères de la ligne sauf le caractère de fin de ligne.

	La variable nb est initialisée à zéro et chaque caractère de la ligne est
	ajouté à la variable nb. Lorsque la boucle se terfloore, nb contient la
	somme des codes ASCII de tous les caractères de la ligne, à l'exception du
	caractère de fin de ligne.

	Le premier caractère de la ligne (str[0]) est utilisé pour déterfloorer
	quelles instructions de tri à exécuter sur la pile t. La fonction
	exec_commands(t, nb, str[0]) est appelée avec les arguments appropriés pour
	exécuter l'instruction.

	Après avoir exécuté l'instruction, la mémoire allouée pour la chaîne de
	caractères de la ligne est libérée à l'aide de la fonction free().
	La fonction lit ensuite la prochaine ligne de l'entrée standard en appelant
	à nouveau get_next_line(0). La boucle while continue à s'exécuter jusqu'à
	ce qu'il n'y ait plus de lignes disponibles.
*/
void	read_commands(t_stack *t)
{
	int		i;
	int		nb;
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		i = 0;
		nb = 0;
		while (str[i] != '\n')
		{
			nb += str[i];
			i++;
		}
		exec_commands(t, nb, str[0]);
		free(str);
		str = get_next_line(0);
	}
}

/*
	checker() implémente le point d'entrée du programme. Elle prend en entrée
	les arguments fournis en ligne de commande et appelle une série de
	fonctions pour initialiser et manipuler une pile d'entiers.

	La fonction commence par vérifier que les arguments fournis sont valides
	en appelant la fonction check_arg(). Si les arguments sont invalides, la
	fonction main() retourne 0.

	Ensuite, si le nombre d'arguments est supérieur à 2, la fonction edit() est
	appelée pour créer une pile d'entiers à partir des arguments fournis.
	La fonction check_not_sorted_or_duplicate() est utilisée pour vérifier si
	la pile est déjà triée. Si elle l'est, ou si les piles sont vides, la
	fonction clean() est appelée pour libérer la mémoire allouée et la fonction
	main() retourne "OK".

	Sinon, la fonction read_commands() est appelée pour lire les instructions
	de tri depuis l'entrée standard et manipuler les piles. La fonction
	check_not_sorted_or_duplicate() est utilisée à nouveau pour vérifier si la
	pile est triée à la fin. Si c'est le cas et que la pile B est vide, la
	fonction main() retourne "OK". Sinon, la fonction main() retourne "KO".

	Enfin, la fonction clean() est appelée pour libérer la mémoire allouée
	avant de quitter le programme.
*/
int	main(int argc, char **argv)
{
	t_stack	t;

	if (argc >= 2)
	{
		t = edit(argc, argv);
		if (check_arg(argc, argv))
			return (clean(&t));
		if (!t.a || !t.b)
			return (clean(&t));
		if (is_sort(&t) == 6)
			return (clean(&t));
		read_commands(&t);
		if (is_sort(&t) && t.size_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clean(&t);
	}
	return (0);
}
