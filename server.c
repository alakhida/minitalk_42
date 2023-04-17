/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:09:36 by alakhida          #+#    #+#             */
/*   Updated: 2023/04/03 04:47:28 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *other)
{
	static char		dec;
	static int		i;
	static int		pid;

	(void)other;
	if (signo != SIGUSR1 && signo != SIGUSR2)
		return ;
	signo = signo - SIGUSR1;
	if (pid != info ->si_pid || !pid)
	{
		dec = 0;
		i = 0;
	}
	if (signo)
		dec = dec << 1 | 1;
	else
		dec = dec << 1 | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(dec);
		i = 0;
		dec = 0;
	}	
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	rr;

	rr.sa_sigaction = handler;
	rr.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &rr, NULL);
	sigaction(SIGUSR2, &rr, NULL);
	write(1, "PROCESS ID : ", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
