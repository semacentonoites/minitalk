/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:57:54 by erferrei          #+#    #+#             */
/*   Updated: 2024/07/16 15:57:56 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	send(int pid, char c)
{
	char	f;
	int		i;

	i = 8;
	while (i > 0)
	{
		f = c;
		f = f >> (i - 1);
		if (f & 1)
		{
			kill(pid, SIGUSR1);
			usleep(400);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(400);
		}
		i--;
	}
}

int	ft_allnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		if (ft_allnum(av[1]))
			pid = ft_atoi(av[1]);
		else
		{
			printf("Invalid PID argument\n");
			return (0);
		}
		while (av[2][i])
		{
			send(pid, av[2][i]);
			i++;
		}
		send(pid, av[2][i]);
	}
	else
		printf("Incorrect number of arguments\n./client [PID] [message]\n");
	return (0);
}
