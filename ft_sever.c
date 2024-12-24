#include "ft_minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗%s\n", YELLOW, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝%s\n", YELLOW, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗%s\n", YELLOW, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗%s\n", YELLOW, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝%s\n", YELLOW, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: youssef raji%s\n", RED, pid, END, YELLOW, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\n\n");
}


int main()
{
	int	pid;
	struct	sigaction act;

	pid = getpid(); // getting the current process ID
	ft_banner(pid); // call the function banner using PID
	act.sa_sigaction = action; // it tell the program that when a signal is recieved (user1 or user2) the custum function action must executed.
	sigemptyset(act.sa_mask); // 
	act.sa_flags = SA_SIGINFO;
	while (1) // make it inifinit loop then puse if you need
	{
		sigaction(SIGUSER1, &sig, 0);
		sigaction(SIGUSER2, &sig, 0);
		pause();
	}
	return(EXIT_FAILURE)
}
