/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_mnssp_md_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:56:19 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 00:28:47 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_m_md_bonus(const char f, va_list args, char *b, char *a)
{
	int	i;
	int	b_;
	int	a_;

	i = 0;
	b_ = ft_atoi_bonus(b);
	a_ = ft_atoi_bonus(a);
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b_, '-');
	else if (f == 'p')
		i = ft_found_p_md_mi_bonus(va_arg(args, size_t), b_, a_, '-');
	else if (f == 'x')
		i = ft_found_x_md_mi_bonus(va_arg(args, size_t), b_, a_, '-');
	else if (f == 'X')
		i = ft_found_bigx_md_mi_bonus(va_arg(args, size_t), b_, a_, '-');
	else if (f == '%')
		i = ft_found_c_bonus('%', 0, ' ', 0);
	else
		i = ft_md_mi_sub_bonus(f, args, b_, a_);
	free (b);
	free (a);
	return (i);
}

int	ft_p_md_bonus(const char f, va_list args, char *b, char *a)
{
	int	i;
	int	b_;
	int	a_;

	i = 0;
	b_ = ft_atoi_bonus(b);
	a_ = ft_atoi_bonus(a);
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b_, '+');
	else if (f == 'p')
		i = ft_found_p_md_bonus(va_arg(args, size_t), b_, a_, '+');
	else if (f == 'x')
		i = ft_found_x_md_bonus(va_arg(args, size_t), b_, a_, '+');
	else if (f == 'X')
		i = ft_found_bigx_md_bonus(va_arg(args, size_t), b_, a_, '+');
	else if (f == '%')
		i = ft_found_c_bonus('%', 0, ' ', 0);
	else
		i = ft_md_sub_bonus(f, args, b_, a_);
	free (b);
	free (a);
	return (i);
}

int	ft_z_md_bonus(const char f, va_list args, char *b, char *a)
{
	int	i;
	int	b_;
	int	a_;

	i = 0;
	b_ = ft_atoi_bonus(b);
	a_ = ft_atoi_bonus(a);
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b_, '0');
	else if (f == 'p')
		i = ft_found_p_md_bonus(va_arg(args, size_t), b_, a_, '0');
	else if (f == 'x')
		i = ft_found_x_md_bonus(va_arg(args, size_t), b_, a_, '0');
	else if (f == 'X')
		i = ft_found_bigx_md_bonus(va_arg(args, size_t), b_, a_, '0');
	else if (f == '%')
		i = ft_found_c_bonus('%', 0, ' ', 0);
	else
		i = ft_md_sub_bonus(f, args, b_, a_);
	free (b);
	free (a);
	return (i);
}

int	ft_sh_md_bonus(const char f, va_list args, char *b, char *a)
{
	int	i;
	int	b_;
	int	a_;

	i = 0;
	b_ = ft_atoi_bonus(b);
	a_ = ft_atoi_bonus(a);
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b_, '#');
	else if (f == 'p')
		i = ft_found_p_md_bonus(va_arg(args, size_t), b_, a_, '#');
	else if (f == 'x')
		i = ft_found_x_md_bonus(va_arg(args, size_t), b_, a_, '#');
	else if (f == 'X')
		i = ft_found_bigx_md_bonus(va_arg(args, size_t), b_, a_, '#');
	else if (f == '%')
		i = ft_found_c_bonus('%', 0, ' ', 0);
	else
		i = ft_md_sub_bonus(f, args, b_, a_);
	free (b);
	free (a);
	return (i);
}

int	ft_sp_md_bonus(const char f, va_list args, char *b, char *a)
{
	int	i;
	int	b_;
	int	a_;

	i = 0;
	b_ = ft_atoi_bonus(b);
	a_ = ft_atoi_bonus(a);
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b_, ' ');
	else if (f == 'p')
		i = ft_found_p_md_bonus(va_arg(args, size_t), b_, a_, ' ');
	else if (f == 'x')
		i = ft_found_x_md_bonus(va_arg(args, size_t), b_, a_, ' ');
	else if (f == 'X')
		i = ft_found_bigx_md_bonus(va_arg(args, size_t), b_, a_, ' ');
	else if (f == '%')
		i = ft_found_c_bonus('%', 0, ' ', 0);
	else
		i = ft_md_sub_bonus(f, args, b_, a_);
	free (b);
	free (a);
	return (i);
}
