NAME	= so_long
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -sC
LFTP	= utils/libft
LFT	= $(LFTP)/libft.a
MKLFT	= $(MKINP) $(LFTP)
GNLP	= utils/gnl
GNL	= $(GNLP)/libgnl.a
MKGNL	= $(MKINP) $(GNLP)
SRC	= main.c so_long.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(LFTP) -I$(GNLP)
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o) $(LFT) $(GNL)
RM	= rm -fr
VPATH	= . $(SRCP) $(ICDP) $(OBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(LFT):
		$(MKLFT)

$(GNL):
		$(MKGNL)

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(LFT) $(GNL) $(OBJP) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
		$(MKLFT) clean
		$(MKGNL) clean
		$(RM) $(OBJP)

fclean:		clean
		$(MKLFT) fclean
		$(MKGNL) fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
