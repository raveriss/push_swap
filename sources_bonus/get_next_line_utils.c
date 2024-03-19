/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:23 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 10:36:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

/*
	ft_strlen() prend en entrée une chaîne de caractères (un tableau de
	caractères terminé par un caractère nul) et renvoie sa longueur(le nombre
	de caractères avant le caractère nul).

	Elle commence par initialiser une variable de type size_t (un type qui
	garantit qu'il peut représenter la taille d'un objet, quelle que soit la
	plateforme) nommée i à 0. Si la chaîne de caractères passée en paramètre
	est NULL, ce qui indique qu'il s'agit d'un pointeur nul, la fonction
	renvoie 0 immédiatement, car la chaîne de caractères est vide.

	Ensuite, la fonction entre dans une boucle while qui se poursuit tant que
	l'élément actuel de la chaîne de caractères n'est pas le caractère nul
	('\0'). Dans chaque itération de la boucle, elle incrémente la variable i.
	Finalement, la fonction retourne la valeur de i, qui est la longueur de la
	chaîne de caractères.
*/
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
	ft_strchr() chercher la première occurrence d'un caractère donné dans une
	chaîne de caractères. Elle prend en entrée un pointeur vers une chaîne de
	caractères "s" et un entier "c" qui représente le caractère à chercher.

	La fonction commence par initialiser un compteur "i" à zéro. Elle vérifie
	ensuite si la chaîne de caractères est nulle (pointeur NULL), et si c'est
	le cas, elle renvoie également un pointeur NULL pour signaler une erreur.

	Ensuite, la fonction parcourt la chaîne de caractères caractère par
	caractère à l'aide d'une boucle while. Si le caractère courant est égal au
	caractère cherché, elle renvoie un pointeur vers ce caractère dans la
	chaîne de caractères en utilisant l'adresse de la chaîne de caractères plus
	l'indice courant "i".

	Si la boucle se termine sans trouver le caractère cherché, la fonction
	renvoie également un pointeur NULL.
*/
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
