/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:29:34 by yoraji            #+#    #+#             */
/*   Updated: 2025/01/03 17:30:05 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	display_banner(int pid)
{
	ft_printf("\n\t███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\n");
	ft_printf("\t██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n");
	ft_printf("\t██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n");
	ft_printf("\t██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_printf("\n\t\tPID: %d\t\t\tBy: yoraji\n", pid);
	ft_printf("\t⊱ ─────────────────── {.⋅ ✯ ⋅.} ──────────────────── ⊰\n\n");
}

void	handler(int sig, siginfo_t *info, void __attribute__((unused)) *u)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	if (sig == SIGUSR1)
		character = (character << 1) | 1;
	else if (sig == SIGUSR2)
		character = (character << 1);
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			write(1, &character, 1);
		}
		bit_count = 0;
		character = 0;
	}
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	display_banner(pid);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
			NULL) == -1)
	{
		ft_printf("Error: Failed to set up signal handlers.\n");
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
