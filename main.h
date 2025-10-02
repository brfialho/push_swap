/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:55:02 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/02 19:18:40 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/headers/libft.h"

struct s_number {
	long	number;
	long	index;
} typedef t_number;

struct s_data {
	t_list	**head_a;
	t_list	**head_b;
} typedef t_data;

#endif