NAME	= so_long
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -C
GNLP	= gnl
GNL	= $(GNLP)/libgnl.a
MKGNL	= $(MKINP) $(GNLP)
SRC	= main.c so_long.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(GNLP)
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o) $(GNL)
RM	= rm -fr
VPATH	= . $(SRCP) $(ICDP) $(OBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(GNL):
		$(MKGNL)

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(GNL) $(OBJP) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:
		$(MKGNL) clean -s
		$(RM) $(OBJP)

fclean:		clean
		$(MKGNL) fclean -s
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
