NAME	= so_long
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -sC
MLXP	= mlx
MLX	= $(MLXP)/libmlx.a
MKMLX	= $(MKINP) $(MLXP)
LFTP	= libft
LFT	= $(LFTP)/libft.a
MKLFT	= $(MKINP) $(LFTP)
SRC	= check_allocation.c check_args.c check_images.c check_map.c check_map_file.c \
	  check_mlx.c check_window.c configure_collectibles.c configure_images.c \
	  configure_map.c configure_mlx.c configure_player.c create_game.c create_map.c \
	  destroy_game.c exit_with_error.c fill_map.c finish_game.c handle_close.c \
	  handle_keyboard.c handle_movement.c main.c render_game.c so_long.c
SRCP	= src
UTILS	= create_matrix.c destroy_matrix.c
UTILSP	= utils
ICDP	= include
ICDS	= -I$(ICDP) -I$(MLXP) -I$(LFTP)/$(ICDP)
LIBS	= -L$(LFTP) -lft -L$(MLXP) -lmlx -lXext -lX11
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o) \
	$(UTILS:%.c=$(OBJP)/%.o)
DOBJP	= dobj
DOBJS	= $(SRC:%.c=$(DOBJP)/%.o) \
	$(UTILS:%.c=$(DOBJP)/%.o)
RM	= rm -fr
VGD	= valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes
VPATH	= . $(SRCP) $(UTILSP) $(OBJP) $(DOBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

$(DOBJP)/%.o:	%.c
		$(CC) $(CFLAGS) -g $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(MLX):
		$(MKMLX)

$(LFT):
		$(MKLFT) gnl
		$(MKLFT) printf

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(MLX) $(LFT) $(OBJP) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(DOBJP):
		mkdir -p $(DOBJP)

debug:		$(MLX) $(LFT) $(DOBJP) $(DOBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(DOBJS) $(LIBS)

valgrind:	all
		$(VGD) ./so_long $(BER)

clean:
		$(MKMLX) clean
		$(MKLFT) clean
		$(RM) $(OBJP)
		$(RM) $(DOBJP)

fclean:		clean
		$(MKLFT) fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re debug valgrind
