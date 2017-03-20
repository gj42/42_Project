# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/17 19:53:34 by bciss             #+#    #+#              #
#    Updated: 2016/05/19 15:51:18 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

CC = clang
CFLAGS = -Werror -Wall -Wextra -o3 -g3
CPATH = src/
CFILES = \
	childsignals.c \
	cursor_movement.c \
	command.c \
	concate.c \
	copy_env.c \
	denit.c \
	echo.c \
	echo2.c \
	env_length.c \
	exec.c \
	exit.c \
	formatting.c \
	free_env.c \
	ft_alias.c \
	ft_cd.c \
	ft_get_word.c \
	ft_logiques_operas.c \
	ft_operas.c \
	ft_pipe.c \
	ft_setenv.c \
	ft_smartsplit.c \
	ft_strfreejoin.c \
	ft_strspetrim.c \
	ft_unsetenv.c \
	get_next_line.c \
	get_val.c \
	init.c \
	is_var.c \
	main.c \
	minimal_prompt.c \
	sh_builtin_env.c \
	sh_builtin_local.c \
	prompt.c \
	redirections.c \
	red_tools.c \
	signals.c \
	traitement.c \
	auto_function.c \
	autocompletion.c \
	circular_list.c \
	edition.c \
	ft_select.c \
	ft_select_function.c \
	get_button.c \
	get_command_path.c \
	get_line.c \
	history.c \
	key.c \
	line_function.c \
	term_mode.c \
	red_pipes.c \
	parsing.c \
	sh_builtin_setenv.c \
	sh_builtin_export.c \
	envmanage.c \
	localmanage.c \
	next_command.c \
	shortcuts.c \
	pre_red.c \
	ft_getcharpos.c \
	sh_builtin_unsetenv.c \
	sh_builtin_unset.c \
	ft_config.c \
	prepare_autocomp.c \
	insert_chars.c \
	find_local_binaries.c \
	free_list.c \
	resize_term.c \
	timestamp.c \
	copy_paste.c \
	builtin_history.c \
	cp_short.c \
	ft_strcatf.c \
	ft_check_line.c \
	multiline_cursor.c \
	ft_history.c \
	parsing_handleinib.c \
	manage_tilde.c \
	edit_slim.c \
	ft_isnumber.c \
	list_history.c \
	histo_func.c \
	ft_patternsplit.c \
	print_different.c \
	ft_select_fu.c \
	cursor_shortcut.c \
	tools.c \
	resize_term2.c \
	ft_check_line2.c \
	function_history.c \

	
MAKEFILE = Makefile
OPATH = obj/
OFILES = $(CFILES:.c=.o)

OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re f

all: $(NAME)

$(NAME): $(MAKEFILE) $(OPATH) $(OBJ)
	make -C libft/ fclean
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME) -lncurses

$(OPATH):
	@mkdir -p $(OPATH)

$(OPATH)%.o: $(CPATH)%.c inc/libft.h inc/ft_sh.h inc/get_next_line.h
	$(CC) $(CFLAGS) -I inc -c -o $@ $< 

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

f: all
	./$(NAME)
