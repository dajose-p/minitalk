NAME = libft.a
BON_NAME = .bonus
AR= ar rcs
SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_utils.c ft_itoa_uns.c \
	get_next_line.c get_next_line_utils.c ft_printf.c ft_itoa_uns.c ft_printf_utils.c \
	ft_putcount_base.c ft_putcount_ptr.c

BONUSSRC = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BONUSSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)
	
$(BON_NAME): $(OBJECTS) $(BOBJECTS)
	$(AR) $(BON_NAME) $(OBJECTS) $(BOBJECTS)
	$(AR) $(NAME) $(OBJECTS) $(BOBJECTS)
bonus: $(BON_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME) $(BON_NAME)

re: fclean all

.PHONY: bonus clean fclean re
