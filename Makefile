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
GNLP	= utils/gnl
GNL	= $(GNLP)/libgnl.a
MKGNL	= $(MKINP) $(GNLP)
SRC	= main.c so_long.c read_map_file.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(MLXP) -I$(LFTP) -I$(GNLP)
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o) $(MLX) $(LFT) $(GNL)
RM	= rm -fr
VPATH	= . $(SRCP) $(OBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(LFT):
		$(MKLFT)

$(GNL):
		$(MKGNL)

$(MLX):
		$(MKMLX)

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(LFT) $(GNL) $(MLX) $(OBJP) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
		$(MKLFT) clean
		$(MKGNL) clean
		$(MKMLX) clean
		$(RM) $(OBJP)

fclean:		clean
		$(MKLFT) fclean
		$(MKGNL) fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
