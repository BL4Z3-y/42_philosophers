/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:53:36 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/06 13:57:26 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

/*--------------------------------*/
//LIBFT
/*--------------------------------*/

//HELPERS
int		ft_atoi(const char *str);
int		ft_error(int err);
int		ft_isdigit(int c);
int		parsing(char ** av);
/*--------------------------------*/

#endif