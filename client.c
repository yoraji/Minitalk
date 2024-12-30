#include "minitalk.h"

void send_signal(int pid, unsigned char c)
{
    int pos = 7;

    while (pos >= 0)
    {
        if (c >> pos & 1)
        {
            if (kill(pid, SIGUSR1) < 0)
            {
                ft_printf("Failed to send SIGUSR1 signal\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) < 0)
            {
                ft_printf("Failed to send SIGUSR2 signal\n");
                exit(EXIT_FAILURE);
            }
        }
        usleep(100); // Allow the receiver to process the signal
        pos--;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    char *message;

    if (argc != 3)
    {
        ft_printf("Usage: %s <PID> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid = ft_atoi(argv[1]);
    if (pid <= 0)
    {
        ft_printf("Invalid PID: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    message = argv[2];
    while (*message)
    {
        send_signal(pid, *message);
        message++;
    }

    // Send null terminator to mark the end of the message
    send_signal(pid, '\0');

    return 0;
}

