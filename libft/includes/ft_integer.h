/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:42:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 01:42:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTEGER_H
# define FT_INTEGER_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

long long	ft_atoll(const char *str);
int			ft_atoi(const char *str);
int			ft_atoui(const char *str);
char		*ft_itoa(int n);
int			ft_nbrlen(long n, int base);
char		*ft_ltoa_base(long n, char const *base);
char		*ft_uitoa(unsigned int n);
char		*ft_uitoa_base(unsigned int n, char const *base);

#endif
