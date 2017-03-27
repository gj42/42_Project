/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:56:19 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 16:17:40 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <stdlib.h>
# include <sys/resource.h>
# include "libft.h"
# define TINY 'T'
# define SMALL 'S'
# define LARGE 'L'
# define PAGE_SIZE getpagesize()

# define TINY_SIZE (size_t)(PAGE_SIZE)
# define SMALL_SIZE (size_t)(PAGE_SIZE * 20)
# define TINY_SIZE_MAX TINY_SIZE * 101
# define SMALL_SIZE_MAX SMALL_SIZE * 101

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();
void			*calloc(size_t nmemb, size_t size);

typedef struct	s_mdata
{
	size_t		size;
	int			free;
	void		*next;
}				t_mdata;

typedef struct	s_page
{
	size_t		size;
	int			full;
	void		*start;
	char		type;
	void		*next;
}				t_page;

extern t_page	*g_firstpage;

void			*page_push(t_page *first, size_t size, char type);
void			set_metadata(size_t size, t_mdata *mdata, void *next);
t_page			*set_page(t_page *page, char type);
void			*find_page(size_t size);
size_t			get_max_size(char type, size_t size);
void			get_system_limit(size_t size);
void			print_error(char *str);
char			get_sizetype(size_t size);
void			*malloc_large(size_t size);
void			*init_block(void *ptr, size_t size);
void			*first_malloc(size_t size);
void			*do_malloc(size_t size);
t_mdata			*find_mdataptr(void *ptr, t_page *page);
t_page			*find_pageptr(void *ptr);
int				free_page(t_page *page);
void			*do_bigger_realloc(t_mdata *mdata, size_t size, t_page *page,
		void *ptr);
void			*do_smaller_realloc(void *ptr, size_t size);
void			print_adress(void *addr);
void			ft_itoa_hex(uint64_t n, char *buff);
#endif
