/*
vou ter que enviar caracter a caracter, bit a bit. Ou seja, por cada caracter que mandar, vou ter que mandar 8 signals,, no outro vou ler os signals 
e dar um carcater 

*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>/*
void	send(int pid, char c)
{
	//entao c pode ser escrito em binario 
	//	ou seja
	//	c -> 8 caratceres na realidade, trabaçhamos com eles atraves de bitwise operators
	//	quero mandar SIG1 quando e 1 e seg2 quando é 
	int i;
	int f;

	i = 8;
	while (i > 0)
	{

		f = c;
			//printf("entered while");
		f = f >> (i - 1);
		printf("f = %d\n", f);
		if (f & 1)
		{
			printf("sent 1\n");
			kill(pid, SIGUSR1);
			sleep(1);
		}
		else
		{
			printf("sent 0\n");
			kill(pid, SIGUSR2);
			sleep(1);
		}
		i--;
	}
}
*/

void	send_bit(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}


int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	pid;
		int	i;
		//char	*str;
		i = 0;
		pid = atoi(av[1]); //manage errors
		//str =  av[2];
		printf("%d\n", pid);
		while (av[2][i])
		{
			send_bit(pid, av[2][i]);
			i++;
		}			
	}
	else
	{
		printf("Mensagem de erro\n");
	}
	return (0);
}
