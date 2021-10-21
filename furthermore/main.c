/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:48:39 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/21 14:37:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_elem	*a;
	t_elem	*b;
	int		i;

	a = malloc(sizeof(t_elem));
	if (!a)
		return (0);
	a = NULL;
	b = malloc(sizeof(t_elem));
	if (!b)
		return (0);
	b = NULL;
	i = 0;
	while (++i < argc)
		a = ft_eadd_tolist(a, atoi(argv[i]));
	i = 3;
	while (i < 15)
	{
		vars.a = ft_copy_list(a);
		vars.b = ft_copy_list(b);
		vars.res = malloc(sizeof(t_estr));
		vars.res = NULL;
		ft_push_swap(&vars.a, &vars.b, &vars.res, i);
		vars.nchunk[i - 3] = ft_size_listr(vars.res);
		free(vars.res);
		free(vars.a);
		free(vars.b);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		printf("chunk %d, actions %d\n", 3 + i, vars.nchunk[i]);
		i++;
	}
	return (0);
}
