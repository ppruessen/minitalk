/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprussen <pprussen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:55:47 by pprussen          #+#    #+#             */
/*   Updated: 2021/12/28 10:33:44 by pprussen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Setting and deleting bits
** Setting a bit
**
** Use the bitwise OR operator (|) to set a bit.
**
** number |= 1 << x;
**
** That will set a bit x.
**
** Clearing a bit
**
** Use the bitwise AND operator (&) to clear a bit.
**
** number &= ~(1 << x);
**
** That will clear bit x. You must invert the bit
** string with the bitwise NOT operator (~), then AND it.
**
*/

void	sig_handler_function(int signum, siginfo_t *si, void *data)
{
	static int					i;
	static unsigned char		c;

	(void)data;
	(void)si;
	if (i <= 7)
	{
		if (signum == SIGUSR1)
		{
			c |= (1 << i);
		}
		else
		{
			c &= ~(1 << i);
		}
	}
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler_function;
	pid = getpid();
	write(1, "PID: ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
	return (0);
}
