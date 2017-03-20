/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 00:16:24 by bciss             #+#    #+#             */
/*   Updated: 2016/05/09 16:52:47 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

#define TOUCHES "qwertyuiopasdfghjklzxcvbnm\0"
#define TOUCHES_MAJ "QWERTYUIOPASDFGHJKLZXCVBNM\0"
#define TOUCHES_OTH "~`!@#$%^&*()-_+=[{]}\\|:;\"\',<.>/? \0"
#define TOUCHES_NUM "0123456789\0"

static char g_touch[27] = {TOUCHES};
static char g_touch_maj[27] = {TOUCHES_MAJ};
static char g_touch_oth[34] = {TOUCHES_OTH};
static char g_touch_num[11] = {TOUCHES_NUM};

static int g_num_min[27] =
{
	113, 119, 101, 114, 116, 121, 117, 105, 111,
	112, 97, 115, 100, 102, 103, 104, 106, 107,
	108, 122, 120, 99, 118, 98, 110, 109, 0
};

static int g_num_maj[27] =
{
	81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 65, 83, 68,
	70, 71, 72, 74, 75, 76, 90, 88, 67, 86, 66, 78, 77,
	0
};

static int g_num_oth[34] =
{
	126, 96, 33, 64, 35, 36, 37, 94, 38, 42, 40,
	41, 45, 95, 43, 61, 91, 123, 93, 125, 92, 124,
	58, 59, 34, 39, 44, 60, 46, 62, 47, 63, 32, 0
};

static int g_num[11] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 0 };

char			get_t(int key)
{
	int			i;

	i = -1;
	while (g_num_min[++i])
		if (g_num_min[i] == key)
			return (g_touch[i]);
	i = -1;
	while (g_num_maj[++i])
		if (g_num_maj[i] == key)
			return (g_touch_maj[i]);
	i = -1;
	while (g_num_oth[++i])
		if (g_num_oth[i] == key)
			return (g_touch_oth[i]);
	i = -1;
	while (g_num[++i])
		if (g_num[i] == key)
			return (g_touch_num[i]);
	return ('\0');
}
