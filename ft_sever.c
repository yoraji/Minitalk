#include "ft_minitalk.h"

int main()
{
	int	pid;
	struct	sigaction sig;

	pid = getpid();
	ft_banner(pid);
	while (1) // make it inifinit loop then puse if you need
	{
		
		pause();
	}
}
