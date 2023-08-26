/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:41:53 by jebucoy           #+#    #+#             */
/*   Updated: 2023/08/17 21:42:33 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*cn;

	cn = (char *)src;
	i = 0;
	j = 0;
	while (cn[i] != '\0')
		i++;
	if (dstsize != 0)
	{
		while (cn[j] != '\0' && j < dstsize - 1)
		{
			dst[j] = cn[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

static size_t	newstrlen(char *str, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == dstsize)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = newstrlen(dst, dstsize);
	j = 0;
	src_len = ft_strlen(src);
	dst_len = newstrlen(dst, dstsize);
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != i)
		dst[i] = '\0';
	if (dstsize > dst_len)
		return (src_len + dst_len);
	else
		return (src_len + dstsize);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len);
	return (str);
}
