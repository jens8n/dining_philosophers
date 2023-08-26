/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:42:50 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:43:10 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	nbr_len(long nbr)
{
	long	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(long len)
{
	long	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	long	nbr;
	char	*chard;

	i = 0;
	nbr = n;
	len = nbr_len(nbr);
	chard = (char *)malloc(sizeof(char) * (len + 1));
	if (chard == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		chard[i++] = '-';
		len--;
	}
	while (i < nbr_len(n))
	{
		chard[i++] = ((nbr / ft_div(len--)) % 10) + 48;
	}
	chard[i] = '\0';
	return (chard);
}
