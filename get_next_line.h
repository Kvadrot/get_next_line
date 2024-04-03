/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:50 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/31 16:20:59 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef GNL_H
# define HNL_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd);

#endif