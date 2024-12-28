#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", YELLOW, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: yoraji%s\n", RED, pid, END,
		YELLOW, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	handle_signal(int pid)
{
	static int count = 0;
	static unsigned char character = 0;

	if (pid == SIGUSR1)
		character = (character << 1) | 1;
	else if (pid == SIGUSR2)
		character = (character << 1);
	count++;
	if (count == 8)
	{
		if(character == '\0'){
			write(1,"\n",1);
		}else{
			write(1,&character,1);
		}
		count = 0;
		character = 0;
	}
	write(1,"\n",1);
}

int main(void)
{
	struct sigaction	act;
	char				*tag;

	act.sa_falgs = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	printf("Server PID: %d\n",getpid());
	display_banner(pid);
	while(1)
	{
		signal(SIGUSR1,handle_signal);
		signal(SIGUSR2,handle_signal);
		pause();
	}
	return 0;

