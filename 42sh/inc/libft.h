/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:51:42 by bciss             #+#    #+#             */
/*   Updated: 2016/05/16 12:04:11 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>

typedef unsigned int	t_uint;
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_replace_char(char *str, int find, int replace);
char			**ft_dblstrnew(size_t len);
char			**ft_strsplit(char const *s, char c);
char			*concate(char *name, char *val, char *separator);
char			*ft_itoa(int n);
char			*ft_strcat(char *s1, const char*s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcjoin(char *s1, char *s2, char c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strsupertrim(char *str);
char			*ft_strtrim(char const *s);
int				ft_atoi(char const *str);
int				ft_atoi(char const *str);
int				ft_countc(char *str, char c);
int				ft_hextodec(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_ishexa(int c);
int				ft_isocta(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_octtodec(char *str);
int				ft_pow(int nb, int pow);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_cr(char *color, char *str);
void			ft_putendl_db(char *target, char *result);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_puttab(char **tb);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_swapstr(char **str, char **str2);
void			ft_putstr_cr(char *color, char *path);
int				ft_tblen(char **tb);
void			ft_arrfree(char ***ar);
char			*ft_strremovechars(char *str, char c);
int				ft_arrlen(char **arr);
char			*ft_joinarray(char **av);
char			**ft_arrcpy(char **av);
size_t			ft_strlenc(const char *str, char c);
char			*ft_strdupc(const char *src, char c);
size_t			ft_strlencign(const char *str, char c);
char			*ft_strdupcign(const char *src, char c);
char			*ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strlchr(const char *str, int c, size_t size);
int				ft_tablen(char **tb);
#endif
