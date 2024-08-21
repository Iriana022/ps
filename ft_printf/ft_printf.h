/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:21:53 by irazafim          #+#    #+#             */
/*   Updated: 2024/05/11 13:48:12 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# ifndef H_U
#  define H_U "0123456789abcdef"
# endif
# ifndef H_U_M
#  define H_U_M "0123456789ABCDEF"
# endif

int		ft_printf(const char *s, ...);
void	ft_put_u_int(unsigned int nb, int *count);
void	ft_puthexa_lower(unsigned int nb, char *hex_char, int *count);
void	ft_puthexa_lower_l(unsigned long nb, char *hex_char, int *count);
void	ft_puthexa_upper(unsigned int nb, char *hex_char, int *count);
void	ft_putpointer(unsigned long ptr, int *count);
#endif
