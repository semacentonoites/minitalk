#include <stdio.h>
#include <unistd.h>

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void	write_char(int signal)
{
	char c;
	static int	i;

	c = 0;
	
			printf("received 1");
	if (signal == SIGUSR1)
	{

			printf("received 1");
		c = (c << 1) | 1;
	}
	else
		c = (c << 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

/*

int	main(int ac, char **av)
{
	if(ac == 1)
	{
	
	    signal(SIGUSR1, write_char);
	    signal(SIGUSR2, write_char);

   		 printf("Receiver PID: %d\n", getpid());

    	while (1) {
        	pause();
    	}

	}
	else
	{
		printf("Mensagem de erro.\n");
	}
	return (0);
}*//*
int main(int ac, char **av) {
    while (ac == 1) {
        struct sigaction sa;
        sa.sa_handler = write_char;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);

       if( !sigaction(SIGUSR1, &sa, NULL))
		       {printf("ai");
		       }
        sigaction(SIGUSR2, &sa, NULL);

        printf("Receiver PID: %d\n", getpid());

        while (1) {
            pause();
        }
    } else {
        printf("Mensagem de erro.\n");
    }
    return 0;
}*/
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("\033[91mError: wrong format.\033[0m\n");
		printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, write_char);
		signal(SIGUSR2, write_char);
		pause ();
	}
	return (0);
}
