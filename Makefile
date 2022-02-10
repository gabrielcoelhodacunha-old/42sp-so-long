NAME	= so_long
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -sC
MLXP	= mlx
MLX	= $(MLXP)/libmlx.a
MKMLX	= $(MKINP) $(MLXP)
LFTP	= libft
LFT	= $(LFTP)/libft.a
MKLFT	= $(MKINP) $(LFTP)
SRC	= main.c so_long.c create_matrix.c destroy_matrix.c exit_with_error.c \
	  check_map_description_file.c create_map_description.c fill_map_description.c \
	  check_map_description.c check_mlx.c handle_mouse.c handle_close.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(MLXP) -I$(LFTP)/$(ICDP)
LIBS	= -L$(LFTP) -lft -L$(MLXP) -lmlx -lXext -lX11
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o)
DOBJP	= dobj
DOBJS	= $(SRC:%.c=$(DOBJP)/%.o)
RM	= rm -fr
VGD	= valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes
VPATH	= . $(SRCP) $(OBJP) $(DOBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

$(DOBJP)/%.o:	%.c
		$(CC) $(CFLAGS) -g $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(MLX):
		$(MKMLX)

$(LFT):
		$(MKLFT) bonus
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
