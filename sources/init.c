/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:53:47 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 12:50:07 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Cette fonction prend en entrée le nombre d'arguments et un tab_relleau de
pointeurs vers des chaînes de caractères. Elle vérifie si tous les arguments
sont des entiers valides (c'est-à-dire des chaînes de caractères contenant
uniquement des chiffres) et s'ils sont compris dans la plage des entiers 32
bits signés. Si un argument n'est pas valide, la fonction retourne 1, sinon
elle retourne 0.

------------------------------------------------------------------------------

Déclaration et initialisation des variables i, j et nb à 1, 0 et 0
respectivement. La boucle while se poursuit jusqu'à ce que i soit supérieur à
argc-1. Elle parcourt chaque argument dans le tab_relleau d'arguments.

La variable j est initialisée à 0 pour chaque nouvel argument.
Si le premier caractère de l'argument est '-', j est incrémenté, car cela
signifie que l'argument est négatif.

La boucle while continue jusqu'à ce que le caractère de fin de chaîne ('\0')
soit atteint pour chaque argument. Elle vérifie si chaque caractère est compris
entre '0' et '9', en utilisant la fonction booléenne (1 ou 0) notée "!" pour
inverser le résultat de la comparaison. Si un caractère n'est pas un chiffre,
la fonction retourne immédiatement en renvoyant "error\n" sur la sortie
d'erreur.

La fonction ft_atol (un alias pour "ft_atoi_long") est utilisée pour convertir
la chaîne de caractères de l'argument en un long int. Si l'argument est
supérieur à la plage de représentation des entiers signés 32 bits (2147483647)
ou inférieur à -2147483648, la fonction renvoie immédiatement en renvoyant
"error\n" sur la sortie d'erreur.


La boucle while continue jusqu'à ce que tous les arguments aient été vérifiés.
Si tous les arguments sont valides, la fonction renvoie 0.

*/
int	check_arg(int argc, char **argv)
{
	int			i;
	int			j;
	long int	nb;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (write (STDERR_FILENO, "error\n", 6));
			j++;
		}
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN || j > 11)
			return (write(STDERR_FILENO, "error\n", 6));
		i++;
	}
	return (0);
}

/*
	is_sort() vérifie si le tab_relleau "a" est trié dans l'ordre
	croissant en comparant chaque élément à son suivant, et renvoie 1 si c'est
	le cas, 0 sinon. Si deux éléments sont égaux, la fonction renvoie
	immédiatement en renvoyant "error\n" sur la sortie d'erreur.

*/
int	is_sort(t_stack *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->size_a - 1)
	{
		j = i + 1;
		while (j < t->size_a)
		{
			if (t->a[i] == t->a[j])
				return (write (STDERR_FILENO, "error\n", 6));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < t->size_a - 1)
	{
		if (t->a[i] > t->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
	Cette fonction initialise une structure de données de type t_stack qui est
	utilisée pour représenter deux piles, a et b, qui seront utilisées pour
	effectuer des opérations de tri dans un algorithme de tri par empilement
	(stack sort).

	Plus précisément, cette fonction effectue les actions suivantes :

	Initialise les tailles des piles a et b à 0 (t.size_a et t.size_b).
	Alloue de la mémoire pour stocker argc - 1 entiers dans les piles a et b,
	en utilisant la fonction malloc. Si l'allocation de mémoire échoue pour
	l'une des piles (a ou b), la fonction retourne la structure t initiale, qui
	n'a pas été modifiée. Remplit la pile a avec les entiers passés en
	arguments, en utilisant une boucle while et la fonction ft_atol pour
	convertir les chaînes de caractères en entiers. Les entiers sont stockés
	dans le tab_relleau t.a. Initialise la valeur ceilingimale t.ceiling à 0 et
	la valeur maximale t.max à la moitié de la taille de la pile a. Trie la
	pile a en utilisant la fonction ft_index, qui attribue un index à chaque
	élément de la pile en fonction de leur ordre de tri. La fonction retourne
	la structure t mise à jour avec les piles a et b initialisées et triées.
*/
t_stack	initialize_stack(int argc, char **argv)
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
	t.floor = 0;
	t.ceiling = t.size_a / 2;
	t.a = ft_convert_rela_to_abso(t.a, t.size_a);
	return (t);
}

/*
Cette fonction libère la mémoire allouée pour les tab_relleaux "a" et "b" d'une
structure "t_stack" spécifiée en argument. Elle ne retourne pas de valeur.
*/
void	clean(t_stack *t)
{
	free(t->a);
	free(t->b);
}

/*
	la fonction ft_index() crée un nouveau tab_relleau "tab_abs"
	contenant les indices de chaque élément dans "tab_rel" en fonction de leur
	ordre croissant, libère la mémoire allouée pour le tab_relleau "tab_rel",
	et renvoie un pointeur vers le tab_relleau d'indices "tab_abs".
*/
int	*ft_convert_rela_to_abso(int *tab, int size)
{
	int	index;
	int	i;
	int	j;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		index = 0;
		while (j <= size - 1)
		{
			if (tab[i] > tab[j])
				index++;
			j++;
		}
		tmp[i] = index + 1;
		i++;
	}
	free(tab);
	return (tmp);
}
