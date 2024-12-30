#include <signal.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "printf/ft_printf.c"
#include "printf/ft_putchar.c"
#include "printf/ft_putstr.c"
#include "printf/ft_point.c"
#include "printf/ft_hexdecimal.c"
#include "printf/ft_unsigned.c"
#include "printf/ft_putnbr.c"

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define END "\033[0m"

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

int main(void)
{
    struct sigaction act;
    int pid;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid); // Changed `printf` to `ft_printf` for consistency
    display_banner(pid);

    act.sa_flags = 0;
    act.sa_handler = handle_signal;

    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    while (1)
        pause();

    return 0;
}

