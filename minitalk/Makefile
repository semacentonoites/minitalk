CC      	= cc
CFLAGS		= -Wall -Werror -Wextra -g

RM = rm -rf

NAME = server
NAMEC = client
SRCSC = client.o
SRCSS = server.o
OBJSC = $(SRCSC:.c=.o)
OBJSS = $(SRCSS:.c=.o)
LIBFT_DIR = libft
INCLUDES = -I$(LIBFT_DIR)

.PHONY: all clean fclean re

all: $(NAME) $(NAMEC)

$(NAME): $(OBJSS)
	$(MAKE) -C $(LIBFT_DIR)
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJSS) libft.a -o $(NAME)

$(NAMEC): $(OBJSC) 
	$(MAKE) -C $(LIBFT_DIR)
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJSC) libft.a -o $(NAMEC)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJSC) $(OBJSS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAMEC)

re: fclean all
