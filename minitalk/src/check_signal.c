/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:01:08 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:50 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sucessfully received!\n");
	else
		ft_printf("Something went wrong, message unsucessfully received!\n");
}
