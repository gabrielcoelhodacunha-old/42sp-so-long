NAME	= libgnl.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRC:%.c=%.o)
AR	= ar -rcs
RM	= rm -f

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
