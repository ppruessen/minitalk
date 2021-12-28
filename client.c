/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:55:51 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/28 10:05:23 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(300);
		i++;
		c = c >> 1;
	}
}

int	main(int argv, char **argc)
{
	int	server_pid;
	int	i;

	if (argv != 3)
	{
		write(1, "Please enter the PID and the string you want to send\n", 54);
		return (0);
	}
	server_pid = ft_atoi(argc[1]);
	i = 0;
	while (argc[2][i])
	{
		ft_send_char(server_pid, argc[2][i]);
		i++;
	}
	return (0);
}
