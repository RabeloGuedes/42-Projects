/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:17 by arabelo-          #+#    #+#             */
/*   Updated: 2023/12/02 14:56:51 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief  This function displays an error message
// explaining the wrong argument type.
/// @param  
void	no_num_param_error(void)
{
	write(2, NO_NUM_PARAM_ERROR_MESSAGE,
		ft_strlen(NO_NUM_PARAM_ERROR_MESSAGE));
}

/// @brief  This function displays an error message
// explaining the wrong argument amount.
/// @param  
void	wrong_param_amount_error(void)
{
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE1,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE1));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE2,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE2));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE3,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE3));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE4,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE4));
	write(2, WRONG_PARAM_AMOUNT_ERROR_MESSAGE5,
		ft_strlen(WRONG_PARAM_AMOUNT_ERROR_MESSAGE5));
}

/// @brief This function displays an error message
// explaining the signed argument.
/// @param  
void	signed_param_error(void)
{
	write(2, SIGNED_PARAM_ERROR_MESSAGE,
		ft_strlen(SIGNED_PARAM_ERROR_MESSAGE));
}

/// @brief This function displays an error message
// explaning that a mutex initialization failed.
/// @param  
void	mutex_error(void)
{
	write(2, MUTEX_ERROR_MESSAGE, ft_strlen(MUTEX_ERROR_MESSAGE));
}

/// @brief This function displays an error message
// explaning that the pthread create function failed.
/// @param  
void	pthread_create_error(void)
{
	write(2, PTHREAD_CREATE_ERROR_MESSAGE,
		ft_strlen(PTHREAD_CREATE_ERROR_MESSAGE));
}
