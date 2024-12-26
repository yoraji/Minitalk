#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define END "\033[0m"

// Forward declaration
static int server_pid;

/**
 * Sends a character to another process by encoding it as binary signals
 * @param pid Target process ID
 * @param character Character to send
 */
void send_signal(int pid, unsigned char character) {
    int position = 7;
    while (position >= 0) {
        if (character >> position & 1) {
            kill(pid, SIGUSR1);
        } else {
            kill(pid, SIGUSR2);
        }
        usleep(100);
        position--;
    }
}

/**
 * Displays a decorative banner with the program name and PID
 * @param pid Process ID to display
 */
void display_banner(int pid) {
    const char *banner[] = {
        "\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗%s\n",
        "\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝%s\n",
        "\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗%s\n",
        "\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗%s\n",
        "\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝%s\n",
        "%s\n\t\tPID: %d%s\t\t\t%sBy: youssef raji%s\n",
        "\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\n\n"
    };

    for (int i = 0; i < 5; i++) {
        char formatted[256];
        snprintf(formatted, sizeof(formatted), banner[i], YELLOW, END);
        for (int j = 0; formatted[j]; j++) {
            send_signal(server_pid, formatted[j]);
        }
    }

    char formatted[256];
    snprintf(formatted, sizeof(formatted), banner[5], RED, pid, END, YELLOW, END);
    for (int j = 0; formatted[j]; j++) {
        send_signal(server_pid, formatted[j]);
    }

    const char *decoration = banner[6];
    for (int j = 0; decoration[j]; j++) {
        send_signal(server_pid, decoration[j]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    server_pid = atoi(argv[1]);
    const char *message = argv[2];

    display_banner(server_pid);

    for (size_t i = 0; message[i]; i++) {
        send_signal(server_pid, message[i]);
    }
    send_signal(server_pid, '\0');

    return 0;
}
