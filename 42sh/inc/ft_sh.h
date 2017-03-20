/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 01:56:19 by bciss             #+#    #+#             */
/*   Updated: 2016/05/28 19:52:13 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "libft.h"

# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <limits.h>

# define BASIC_PROMPT "> "
# define SILENT_MODE 1
# define BUF_SIZE 2048
# define ENV_SIZE 2048
# define ERR_ALLOC_ENV "Error while allocating space for environment\n"
# define ER "42sh:Environnement variable TERM missing, shell must not be stable"
# define HISTORY_SIZE 30
# define DUALQUOTES 4414242
# define SIMPLEQUOTES 4414247
# define PROMPT_LEN 2
# define NAMESH "21sh"

enum				e_key
{
	TAB = 9,
	UP = 4283163,
	LEFT = 4479771,
	DOWN = 4348699,
	RIGHT = 4414235,
	RETURN = 10,
	DEL = 127,
	DELETE = 2117294875,
	ESC = 27,
	SPC = 32,
	ZERO = 4414256,
	ONE = 4414257,
	TWO = 4414258,
	THREE = 4414259,
	FOUR = 4414260,
	FIVE = 4414261,
	SIX = 4414262,
	SEVEN = 4414263,
	EIGHT = 4414264,
	NINE = 4414265,
	CTRL_E = 5,
	END = 4610843,
	CTRL_A = 1,
	HOME = 4741915,
	SHIFT_LEFT = 17458,
	SHIFT_RIGHT = 17202,
	CTRL_L = 12,
	CTRL_V = 43970,
	PAGE_UP = 2117425947,
	PAGE_DOWN = 2117491483,
};

typedef	struct		s_select
{
	struct s_select *next;
	struct s_select	*prev;
	int				choosed;
	int				begin;
	int				index;
	size_t			size;
	char			word[0xf000];
	int				atm;
	int				inderdsfx;
	int				finish;
}					t_select;

typedef struct		s_data
{
	int				fd2;
	int				fd[256];
	int				spefd[256];
	int				i;
	int				ret;
	int				j;
	int				aggre[256];
}					t_data;

typedef struct		s_hist
{
	char			time[14];
	char			str[0xf000];
	int				index;
	struct s_hist	*next;
}					t_hist;

/*
**	ft_get_line
*/

char				*get_line_ret(char *buf, int i, char *str);
char				*get_line(char *str, char *file, unsigned int line);
char				*get_line_nb(unsigned int line, int fd, char *str);

/*
**	ft_history
*/

char				*history_line_get(char *str, char *file, int line);
char				*history_navigation(int key, char *str);
void				add_str_to_history(char *str, char *file);
void				remove_excess_line(char *file);
void				add_first_line(char *file, char *str);
int					get_timestamp(void);
char				*get_line_wo_tstamp(int line, char *file, char *str);
int					ft_history(char **tb);
int					builtin_history(char **buffer);
char				*edit_slim(char *to_edit);
char				*edit_slim2(char *to_edit, char *truc);
t_hist				*ft_histo_init_clist(char *str);
void				ft_histo_add_clist(t_hist **histo, char *str);
void				ft_clist_remove(t_hist *history);
int					count_lines(t_hist *history);
void				remove_lines(t_hist *history);
void				ft_add_history(char *str);
void				ft_add_history_file(char *time, char *str);
char				*ft_get_line_history(char *to_edit, int line);
int					verif_pattern(char *pattern, char *buf, int start, int end);
char				*get_str_index(char *buf, int start, int end);
void				ft_strpatternsplit(char **array, char *buf, char *pattern);
void				get_history_content(char **array, char *file);
void				ft_init_history(void);
int					count_lines_file(char *file);
void				decrement_index(t_hist *ptr);
void				free_negative(t_hist *ptr);
char				*ft_get_read(void);
char				*history_buffer_check(char *str, char *buf,
		int *line, int nb);

/*
**	Term mode
*/

struct termios		set_term_canon(void);
char				*unset_term_canon(struct termios term_basic,
	char *selected);

/*
**	Edition
*/

char				*multi_prompt(char **to_edit);
char				*ft_edit_and_history(char *str);
char				*ft_edit(char *str, char *truc);
char				*line_edition(char *to_edit, int key);
int					t_puts(int c);
char				*r_delete(char *to_edit, int cursor);
char				*l_delete(char *to_edit, int cursor);
char				*insert_char(char *to_edit, char c, int *cursor);
char				*insert_last_char(char *to_edit, char c);
char				*ft_return(char *to_edit);
void				ft_copy(void);
char				*insert_str_index(char *buffer, int *cursor, char *str);
char				*ft_paste(void);
char				*ft_strldup(char *str, int l);
int					bs_count(char *to_edit);
int					multiline(char *to_edit, int cursor, int bs);
void				ft_putstr_bold(char *str);
void				ft_putstr_bold_start(char *str, int start, int end);
void				ft_putstr_bold_cr(char *str, char *color);

/*
**	Cursor
*/

int					set_cursor(int cursor, char *buffer);
void				ft_putstr_cursor(char *str, int cursor);
int					ft_strlen_term(char *cmd, int width);
int					ft_strlen_cur(char *cmd, int x, int cursor);
int					cursor_movement(int key, int cursor, char *to_edit);
int					size_until_next_word(char *sentence, int cursor);
int					size_until_prev_word(char *sentence, int cursor);
int					movement_key(int key);
int					move_cursor_x(int cursor, char *to_edit);
int					refresh_cursor(int cursor, char *to_edit);
int					ft_strlen_b4n(char *str, int nb);

/*
**	Useless
*/

void				ft_error(char *str);
void				ft_exit(char *str);
void				ft_refresh(char *to_edit, int cursor);
char				get_t(int key);
char				get_n(int key);
char				ft_print(int key);
void				free_the_shit(t_select **list);
char				*ft_trim_last_space(char *to_edit);
char				*ft_trim_bs(char *to_edit);
char				*nm_trim(char *to_edit);
char				*ac_missing_chars(char *start, int cursor, char *complete);
struct winsize		*get_term_size(int *x, int *y);
int					get_line_term(void);
int					get_col_term(void);
int					set_line(char *to_edit, int cursor);
char				*micro_prompt(void);

/*
**	Autocompletion
*/

char				**autocomp_size(char *str, char *path, int i);
char				*auto_complete(char *to_edit, int *cursor);
int					get_path_size(const char *path);
char				*malloc_tb(char **tb, unsigned int size);
int					get_tab_size(char *path, char *str);
char				*autocomp_word(char *str, char *path);
char				*autocomp_command(char *str, char *path, int i);
int					is_empty(char *to_edit);
int					is_command(char *str);
int					verify_buffer(char *to_edit, char *path);
int					something_to_complete(char *to_edit, char *path);
int					is_command_launch(char *to_edit);
char				*autocomp_binary(char *to_edit, char *path);
char				**get_autocomp_path(char *to_complete);
char				*ft_absolute_path(char *path);
char				**ft_command_split_last_c(char *to_complete, char c);
int					binary_launch(int cursor, char *to_edit);
char				**find_local_binaries(char *path);
int					get_nb_word(char *str);
void				get_cursor_word(char *to_edit, int cursor, char *dest);
int					ft_isspace(int c);
char				*get_missing_chars(char *start, int cursor, char *complete);
char				*prepare_autocomp(char *ptr);
char				*complete_other(char **tb, char *to_edit);
char				*complete_binary(char **tb, char *to_edit, int nb);
char				*complete_command(char *to_edit, int cursor);

/*
**	Ft_select
*/

char				*ft_select(char **av);
void				choose(t_select *list);
char				*do_select(t_select *list);
char				*get_choosen_word(t_select *list);
void				do_refresh(t_select *list);
void				display(t_select *list, size_t size);
void				c_right(t_select *list);
void				c_left(t_select *list);
void				c_up(t_select *list);
void				c_down(t_select *list);
void				key_wait(t_select *list);
void				display_select(t_select *sl);
int					ft_precision(char *str, size_t len);

/*
**	Circular list
*/

void				ft_add_after_root_clist(t_select **circ, char *str);
void				ft_add_before_root_clist(t_select **circ, char *str);
t_select			*ft_select_init_clist(char *str);

/*
**	Shortcuts
*/

int					movement_key(int key);
int					history_key(int key);
int					edition_key(int key);
char				*edition_func(char *to_edit, int *cursor, int key);
void				ft_clear_screen(char *to_edit, int cursor);

/*
**	Command
*/

void				get_command(char *str);
int					use_command(char *command);

extern int			g_size;
extern char			**g_env;
extern char			**g_local;
extern int			g_status;
extern int			g_pipe;
extern int			g_hist;
extern int			g_opts;
extern char			**g_new_env;
extern char			**g_alias;
extern char			g_history_file[MAXPATHLEN];
extern char			g_history_string[0xf000];
extern struct s_hist	*g_history;
extern char			*g_command;

void				sh_builtin_setenv_mng(char *name, char *value, char ***env);
int					ft_echo(char **tb);
char				**copy_env(void);
char				**ft_smartsplit(char *str, char w);
char				**ft_strsplitenter(char *str, char c);
int					ft_alias(char **str);
int					ft_unalias(char **str);
char				*ft_count_pipes(char *str);
char				*ft_formatting(char *str);
char				*ft_get_word(char *str, int nb, int all);
char				*ft_inhib(char *s);
char				*ft_strfreejoin(char *s1, char *s2);
char				*ft_strspetrim(char *s, int i, int j);
char				*get_val(char *var);
int					do_command(void);
int					ft_and(char *left, char *right);
int					ft_cd(char **path);
int					ft_check_exe(char **parsed, char *get_val);
int					sh_builtin_exit(char **av);
int					ft_one_left(char *left, char *right);
int					ft_one_right(char *left, char *right);
int					ft_opera_handler(char *str);
int					ft_or(char *left, char *right);
int					ft_pipe(char *left, char *right);
int					ft_setenv(char *name, char *val);
int					ft_traitement(char *str);
int					ft_two_right(char *left, char *right);
int					writting(char *str, unsigned int flags);
pid_t				save_cpid(pid_t *father);
size_t				env_length(char **env);
size_t				is_var(char *var);
void				denit(void);
void				execute_command(char *str);
void				free_env(void);
void				ft_trafic_regulator(char **tb);
void				ft_unsetenv(char *var);
int					init(char **av, char **env);
void				init_signals(void);
void				minimal_prompt(void);
int					prompt(void);
void				sh_signals(void);
void				sh_wrong_exit(int signum, char *son);
char				**parse_command(char *str);
int					sh_builtin_env(char **av);
int					sh_builtin_local(char **av);
void				ft_fd_from(char **tb, t_data *d);
void				ft_where(char **tb, t_data *d);
int					check_check(char *str);
void				check_pid(int fildes[2], t_data d, char *ll, char *left);
void				red_pipe(char *left, t_data d, char *ll);
int					sh_builtin_export(char **av);
int					sh_builtin_setenv(char **av);
void				sh_builtin_export2(char **av, char ***env);
void				sh_builtin_setenv2(char **av, char ***env);
int					sh_statpath(char *path);
char				*sh_replace_home(char *path, char **env, int ret);
int					sh_get_env_pos(char *find, char **env);
int					sh_get_local_pos(char *find, char **env);
char				*sh_get_env(char *find, char **env);
char				**sh_parse_env(char *find, char **env);
int					sh_builtin_unsetenv(char **av);
int					sh_builtin_unset(char **av);
void				ft_errexit(char *str);
void				pre_red(char *str);
int					ft_getcharpos(char *str, char c, int a);
int					ft_config(char **file);
char				*ft_calias(char *str);
char				*ft_strcatf(char *dest, char *src, int n);
int					ft_check_key_words(char *str);
int					get_cursor_above(char *buf, int cur);
int					get_cursor_below(char *buf, int cur);
char				*get_buf(void);
void				set_buf(char *str);
int					get_buf_len(void);
int					print_history(char **arg);
char				*sh_get_env_var(char *find);
char				*sh_treatinib(char *str);
char				*manage_tilde(char *str);
int					ft_isnumber(char *str);
void				ft_putstr_bold(char *str);
int					ft_end_with_pipe(char *str);
int					ft_missing_operator(char *str);
int					ft_quotes_quota(char *str);
int					check_adjacent(char *str, int i);
int					check_adjacent_red(char *str, int i);
void				set_time(t_hist *histo);
int					alias_open_err(char *file, char **path, int fd);
int					check_adjacent_red(char *str, int i);
int					ft_file_or_dir(char *str);
int					ft_precision(char *str, size_t len);
int					get_col_term(void);
char				**sh_handle_equal_var(char **parsed);
void				sh_builtin_export_mng(char *name, char *value, char ***env);
void				add_line(char *str);
char				*get_histo_line(int i);
int					get_tb_len(void);

typedef struct		s_parse
{
	int		i;
	int		n;
	char	*val;
	int		flag;
	int		flagb;
}					t_parse;

typedef struct		s_line
{
	char			*str;
	int				*pos;
	char			**tb;
}					t_line;

#endif
