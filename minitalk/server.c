/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:58:00 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/16 15:58:01 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

char	*g_str = NULL;

void	*ft_realloc(char *str, size_t size)
{
	char	*new;
	int		len;

	if (str == NULL)
		len = 0;
	else
		len = ft_strlen(str);
	new = malloc((size + len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_bzero(new, size + len + 1);
	ft_memcpy(new, str, len);
	free(str);
	return (new);
}

void	ft_write(char **str, int *j)
{
	while ((*str)[*j])
	{
		write(1, &(*str)[*j], 1);
		*j = *j + 1;
	}
	*j = 0;
	free(*str);
	*str = NULL;
}

void	write_str(int signal)
{
	static char	c;
	static int	i;
	static int	j;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_write(&g_str, &j);
		else
		{
			g_str = ft_realloc(g_str, 1);
			g_str[ft_strlen(g_str)] = c;
		}
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*pid;

	(void) av;
	if (ac == 1)
	{
		i = getpid();
		pid = ft_itoa(i);
		write(1, "Server PID: ", 12);
		write(1, pid, ft_strlen(pid));
		write(1, "\n", 1);
		free(pid);
		signal(SIGUSR1, write_str);
		signal(SIGUSR2, write_str);
		while (1)
			pause();
	}
	else
		write(1, "Incorrect number of arguments\n./server", 39);
	return (0);
}
