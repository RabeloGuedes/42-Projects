/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:20:44 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:46 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef WAIT_TIME
#  define WAIT_TIME 500
# endif

# include <libft.h>
# include <signal.h>
# include <sys/types.h>

void	send_signal(pid_t server_pid, unsigned char c);
void	send_string(pid_t server_pid, char *str);
void	handle_signal(int signal);
void	handle_signal_bonus(int signal, siginfo_t *siginfo, void *addr);
void	check_signal(int signal);
void	sigaction_config(struct sigaction *sa);
char	*get_string(char *old_message, unsigned char c, int chars_counter);
int		handle_string(char *message, unsigned char c, int *chars_counter);
int		is_pid_valid(char *pid_str);
#endif
