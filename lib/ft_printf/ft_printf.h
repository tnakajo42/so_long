/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:53:02 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 17:26:13 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_printf_bonus(const char *f, va_list args, int j, int i);
int		ft_printf_od_bonus(const char format, va_list args, int i);
int		ft_printd_ad_bonus(const char *f, va_list args, int j, int i);
int		ft_check_bonus(const char *format, int j, char *flags);
int		ft_found_c(int c, int i);
int		ft_found_s(char *s, int i);
int		ft_found_p(size_t p, int i);
int		ft_to_hex(size_t hex, int i);
int		ft_found_i_plus_d(int d, int i);
int		ft_found_u(unsigned int u, int i);
int		ft_found_x(size_t x, int i);
int		ft_found_bigx(size_t bigx, int i);
int		ft_found_sharp_bonus(const char format, va_list args, char *a, int i);
int		ft_found_zsharp_bonus(const char format, va_list args, char *a, int i);
int		ft_found_plus_bonus(va_list args, int i);
int		ft_found_space_bonus(const char format, va_list args, int i);
int		ft_not_found_mnd_bonus(const char *f, va_list args, char *a, int j);
int		ft_not_found_mnd_ad_bonus(const char *f, va_list args, char *a, int j);
int		ft_found_mnd_bonus(const char *f, va_list args, char *a, int j);
int		ft_found_mnd_ad_bonus(const char *f, va_list args, char *a, int j);
int		ft_found_minus_bonus(const char format, va_list args, char *a, int i);
int		ft_found_minus_ad_bonus(const char f, va_list args, char *a, int i);
int		ft_found_dot_mi_bonus(const char f, va_list args, char *a, char flag);
int		ft_found_zero_bonus(const char format, va_list args, char *a, int i);
int		ft_found_zero_ad_bonus(const char format, va_list args, char *a, int i);
int		ft_found_dot_bonus(const char format, va_list args, char *a, int i);
int		ft_atoi_bonus(const char *nptr);
char	*ft_itoa_bonus(long n);
size_t	ft_strlen_bonus(const char *s);
void	*ft_m_bonus(void *dest, const void *src, size_t n, size_t j);
int		ft_found_c_bonus(int c, int i, char flag, int n);
int		ft_found_c_md_bonus(int c, int b, char flag);
int		ft_found_s_bonus(char *s, int i, char flag, int n);
int		ft_found_s_ad_bonus(char *s, int i, char flag, int n);
int		ft_found_s_mi_bonus(char *s, int i, char flag, int n);
int		ft_found_s_md_bonus(char *s, int b, int a);
int		ft_found_s_md_mi_bonus(char *s, int b, int a);
int		ft_found_p_bonus(size_t p, int i, char flag, int n);
int		ft_found_p_md_bonus(size_t p, int b, int a, char flag);
int		ft_found_p_md_mi_bonus(size_t p, int b, int a, char flag);
int		ft_found_i_plus_d_bonus(int d, int i, char f, int n);
int		ft_found_i_plus_d_ad_bonus(int d, int i, char flag, int n);
int		ft_found_i_plus_d_od_bonus(int d, int i);
int		ft_found_i_plus_d_md_bonus(int d, int b, int a);
int		ft_found_i_plus_d_md_mi_bonus(int d, int b, int a);
int		ft_found_i_plus_d_mi_bonus(int d, int i, int n);
int		ft_found_u_bonus(unsigned int u, int i, char flag, int n);
int		ft_found_u_ad_bonus(unsigned int u, int i, char flag, int n);
int		ft_found_u_od_bonus(unsigned int u, int i);
int		ft_found_u_md_bonus(unsigned int u, int b, int a);
int		ft_found_u_md_mi_bonus(unsigned int u, int b, int a);
int		ft_found_x_bonus(size_t x, int i, char flag, int n);
int		ft_found_x_ad_bonus(size_t x, int i, char flag, int n);
int		ft_found_x_od_bonus(size_t x, int i);
int		ft_found_x_md_bonus(size_t x, int b, int a, char flag);
int		ft_found_x_md_mi_bonus(size_t x, int b, int a, char flag);
int		ft_found_x_mi_bonus(size_t x, int i, char flag, int n);
int		ft_found_bigx_bonus(size_t bigx, int i, char flag, int n);
int		ft_found_bigx_ad_bonus(size_t x, int i, char flag, int n);
int		ft_found_bigx_od_bonus(size_t bigx, int i);
int		ft_found_bigx_md_bonus(size_t bigx, int b, int a, char flag);
int		ft_found_bigx_md_mi_bonus(size_t bigx, int b, int a, char flag);
int		ft_found_bigx_mi_bonus(size_t bigx, int i, char flag, int n);
int		ft_found_c_od_bonus(int c, int i);
int		ft_found_p_od_bonus(size_t p, int i);
int		ft_p_len_bonus(size_t hex, int len);
int		ft_x_len_bonus(size_t x, int len);
int		ft_flagf_bonus(int len, int n, char flag, int i);
int		ft_print_minusd_bonus(char *d_, int n, char flag, int i);
int		ft_checknum_bonus(const char *f, int j, char *flags, int k);
int		ft_found_md_bonus(const char *f, va_list args, int j, int m);
int		ft_m_md_bonus(const char f, va_list args, char *b, char *a);
int		ft_p_md_bonus(const char f, va_list args, char *b, char *a);
int		ft_z_md_bonus(const char f, va_list args, char *b, char *a);
int		ft_sh_md_bonus(const char f, va_list args, char *b, char *a);
int		ft_sp_md_bonus(const char f, va_list args, char *b, char *a);
int		ft_md_sub_bonus(const char f, va_list args, int b_, int a_);
int		ft_md_mi_sub_bonus(const char f, va_list args, int b_, int a_);

#endif
