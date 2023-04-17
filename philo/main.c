/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:20:22 by jebucoy           #+#    #+#             */
/*   Updated: 2023/04/17 17:47:44 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_sim	sim;
	pthread_t	*p_th;

	p_th = NULL;
	if (ac == 6)
	{
		if (parser(av) == true)
		{
			init_sim_args(av, &sim, p_th);
		}
	}
	return (0);
}
