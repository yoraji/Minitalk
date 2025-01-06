/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:29:25 by yoraji            #+#    #+#             */
/*   Updated: 2025/01/04 13:49:34 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack = 0;

void	wait_for_ack(void)
{
	while (!g_ack)
		usleep(50);
	g_ack = 0;
}

void	ft_send_signal(int pid, unsigned char c)
{
	int	pos;

	pos = 7;
	while (pos >= 0)
	{
		if ((c >> pos) & 1)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("Error: Failed to send SIGUSR1.\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Error: Failed to send SIGUSR2.\n");
				exit(EXIT_FAILURE);
			}
		}
		wait_for_ack();
		pos--;
	}
}

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		write(1, "Message sent\n", 13);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <Message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID.\n");
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}
