#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/ft_atoi.c"
#include "printf/ft_printf.c"

void	send_signal(int pid,unsigned char c)
{
	int	pos;

	pos = 7;
	while(pos >= 0)
	{
		if(c >> pos & 1)
		{
			if(kill(pid,SIGUSR1) < 0)
			{
				ft_printf("Fialed to send signal ");
        			exit(EXIT_FAILURE);
			}	
		}
		else		      	
		{
			if(kill(pid,SIGUSR2) < 0)
			{
				ft_printf("Fialed to send signal ");
        			exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		pos--;
	}
	pos = 8;
	while(pos--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int main(int argc, char *argv[])
{
	int		i;
	char	*str;
	if (argc == 3)
	{
		str = argv[2];
		i = 0;
		if (ft_atoi(argv[1]) < 0)
			return EXIT_FAILURE;
		while(str[i])
		{
			send_signal(ft_atoi(argv[1]), str[i]);
			i++;
		}
		send_signal(ft_atoi(argv[1]),'\0'); //the null terminator mark the end 
		while(1)
			pause();	
	}else
	{
		ft_printf("Fiiled to send signal ");
        	return (EXIT_FAILURE);
	}
	return 0;
}
