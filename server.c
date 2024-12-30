#include "minitalk.h"

void display_banner(int pid)
{
    ft_printf("\n\t███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\n");
    ft_printf("\t██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n");
    ft_printf("\t██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n");
    ft_printf("\t██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
    ft_printf("\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
    ft_printf("\n\t\tPID: %d\t\t\tBy: yoraji\n", pid);
    ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\n\n");
}

void handle_signal(int signal)
{
    static int count = 0;
    static unsigned char character = 0;

    if (signal == SIGUSR1)
        character = (character << 1) | 1;
    else if (signal == SIGUSR2)
        character = (character << 1);

    count++;
    if (count == 8)
    {
        if (character == '\0')
            write(1, "\n", 1);
        else
            write(1, &character, 1);
        count = 0;
        character = 0;
    }
}

/*
 *	struct sigaction 
 *	{
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
        };
	act.sa_flags = 0; // No specific flags
			  // set the hander for the signal
			  // link SIGUSR2 to the act structure
			  // link SIGUSR2 to the act structure
 * */

int main(void)
{
    struct sigaction act;
    int pid;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid); // Changed `printf` to `ft_printf` for consistency
    display_banner(pid);

    act.sa_flags = 0;
    act.sa_handler = handle_signal; // set a custom handler 
    sigaction(SIGUSR1, &act, NULL); // Handler SIGUSR1
    sigaction(SIGUSR2, &act, NULL); // Handler SIGUSR2
    while (1)
        pause();

    return 0;
}

