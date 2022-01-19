NAME	= so_long
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MKINP	= $(MAKE) -C
GNLP	= gnl
MKGNL	= $(MKINP) $(GNLP)
SRC	= main.c
SRCP	= src
ICDP	= include
ICDS	= -I. -I$(ICDP) -I$(GNLP)
LIBS	= -L$(GNLP) -lgnl
OBJP	= obj
OBJS	= $(SRC:%.c=$(OBJP)/%.o)
RM	= rm -fr
VPATH	= . $(SRCP) $(ICDP) $(OBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

all:		$(NAME)

bonus:		all

$(OBJP):
		mkdir -p $(OBJP)

$(NAME):	$(OBJP) $(OBJS)
		$(MKGNL)
		$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS) 

clean:
		$(MKGNL) clean -s
		$(RM) $(OBJP)

fclean:		clean
		$(MKGNL) fclean -s
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
