NAME	= so_long
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -sC
MLXP	= mlx
MLX	= $(MLXP)/libmlx.a
MKMLX	= $(MKINP) $(MLXP)
LFTP	= utils/libft
LFT	= $(LFTP)/libft.a
MKLFT	= $(MKINP) $(LFTP)
SRC	= main.c so_long.c read_map_file.c create_imap.c handle_error.c \
	  handle_map_file.c handle_line.c destroy_imap.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(MLXP) -I$(LFTP)/$(ICDP)
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o) $(MLX) $(LFT)
DOBJP	= dobj
DOBJS	= $(SRC:%.c=$(DOBJP)/%.o) $(MLX) $(LFT)
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

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(MLX) $(LFT) $(OBJP) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

$(DOBJP):
		mkdir -p $(DOBJP)

debug:		$(MLX) $(LFT) $(DOBJP) $(DOBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(DOBJS)

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

.PHONY:		all bonus clean fclean re
