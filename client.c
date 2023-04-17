/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:46:03 by alakhida          #+#    #+#             */
/*   Updated: 2023/04/03 04:50:06 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int		i;

	i = 8;
	while (i-- > 0)
	{
		if (c >> i & 1)
			kill (pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	check_pid(char	*str)
{
	int		pid;
	int		i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i == -1)
		return (0);
	return (pid);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = check_pid(argv[1]);
		if (pid > 0)
		{
			str = argv[2];
			while (str[i])
			{
				send_char(pid, str[i]);
				i++;
			}
		}
		else
			write(1, "WRONG PID :(\n", 13);
	}
	else
		write(1, "<PID> <MESSAGE>\n", 16);
	return (0);
}
