/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:47:16 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 14:29:06 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_elem **a, t_elem **b, t_estr **res, int CHUNK)
{
	int		*chunkt;
	int		*tab;
	int		i;
	int		set;

	chunkt = ft_get_chunkt(*a, CHUNK);
	i = CHUNK - 1;
	while (i >= 0)
	{
		while (ft_is_chunk(*a, chunkt, i, CHUNK))
		{
			set = ft_smart_rotate_a(*a, chunkt, i, CHUNK);
			if (set == 0)
				*b = ft_push_x_to_y(a, *b, 'b', res);
			else if (set == 1)
				*a = ft_rotate(*a, 'a', res);
			else if (set == 2)
				*a = ft_reverse_rotate(*a, 'a', res);
		}
		if (i < CHUNK - 1)
		{
			set = ft_smart_set_a(*a, chunkt, i);
			while ((*a)->val != chunkt[i + 1])
			{
				if (set == 1)
					*a = ft_rotate(*a, 'a', res);
				else if (set == 2)
					*a = ft_reverse_rotate(*a, 'a', res);
			}
		}
		while (*b)
		{
			tab = ft_list_to_tab(*b);
			tab = ft_sort(tab, ft_size_list(*b));
			set = ft_smart_rotate_b(*b, tab, ft_size_list(*b));
			if (set == 1)
			{
				while ((*b)->val != tab[ft_size_list(*b) - 1])
					*b = ft_rotate(*b, 'b', res);
			}
			else if (set == 2)
			{
				while ((*b)->val != tab[ft_size_list(*b) - 1])
					*b = ft_reverse_rotate(*b, 'b', res);
			}
			*a = ft_push_x_to_y(b, *a, 'a', res);
		}
		i--;
	}
}
