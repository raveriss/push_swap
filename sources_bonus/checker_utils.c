/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:08 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 11:22:20 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../get_next_line.h"

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
	La fonction clean prend en entrée un pointeur vers une structure t_stack
	qui contient deux tableaux dynamiques a et b, et libère la mémoire allouée
	pour ces tableaux en utilisant la fonction free(). Elle ne retourne rien
	(void).

	Cette fonction est appelée à la fin du programme pour libérer la mémoire
	utilisée par les tableaux de piles a et b.
*/
int	clean(t_stack *t)
{
	free(t->a);
	free(t->b);
	return (0);
}

/*
	Cette fonction convertit une chaîne de caractères en un nombre entier de
	type long int
*/
long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

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
