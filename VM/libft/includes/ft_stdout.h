/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:00:10 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/18 15:22:28 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDOUT_H
# define FT_STDOUT_H

# define FT_STDOUT ft_stdout()
# define FT_STDOUT_BUF_SIZE 4096

# include <stdlib.h>

t_file		*ft_stdout(void);
uint16_t	ft_flush_stdout(void);

#endif
