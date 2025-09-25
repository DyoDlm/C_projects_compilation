NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
TOOLSDIR = tools

SRC = $(SRCDIR)/ft_printf.c \
      $(SRCDIR)/ft_parse_flags.c \
      $(SRCDIR)/ft_print_conversion.c

TOOLSSRC = $(TOOLSDIR)/ft_atoi.c \
           $(TOOLSDIR)/ft_isdigit.c \
           $(TOOLSDIR)/ft_itoa.c \
           $(TOOLSDIR)/ft_print_percent.c \
           $(TOOLSDIR)/ft_print_pointer.c \
           $(TOOLSDIR)/ft_print_unsigned.c \
           $(TOOLSDIR)/ft_putchar.c \
           $(TOOLSDIR)/ft_put_padding.c \
           $(TOOLSDIR)/ft_putnstr.c \
           $(TOOLSDIR)/ft_putstr.c \
           $(TOOLSDIR)/ft_strlen.c \
           $(TOOLSDIR)/ft_utoa.c \
           $(TOOLSDIR)/ft_utoa_base.c \
	   $(TOOLSDIR)/ft_count_mod.c \
	   $(TOOLSDIR)/seg_input.c

SRCS = $(SRC) $(TOOLSSRC)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Bibliothèque $(NAME) créée avec succès !"

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilé : $<"

clean:
	@rm -f $(OBJ)
	@echo "Nettoyage des fichiers objets terminé."

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet terminé."

re: fclean all

.PHONY: all clean fclean re

