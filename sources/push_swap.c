/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:57:22 by raveriss          #+#    #+#             */
/*   Updated: 2023/03/24 09:50:11 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_arg(argc, argv))
		return (0);
	if (argc > 2)
	{
		t = initialize_stack(argc, argv);
		if (is_sort(&t) || !t.a || !t.b)
		{
			clean(&t);
			return (0);
		}
		if (argc == 3)
			sort_algo_for_exactly_2_values(&t);
		if (argc == 4)
			sort_algo_for_exactly_3_values(&t);
		if (argc > 4 && argc < 7)
			sort_algo_for_4_or_5_values(&t);
		if (argc > 6)
			sort_algo_for_more_of_5_values(&t);
		clean(&t);
	}
	return (0);
}
