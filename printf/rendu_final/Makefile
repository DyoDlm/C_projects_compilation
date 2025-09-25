NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
TOOLSDIR = tools

SRC = $(SRCDIR)/ft_printf.c \
      $(SRCDIR)/gen_data.c \
      $(SRCDIR)/id_rules.c \
      $(SRCDIR)/gerrors.c \
      $(SRCDIR)/ss.c \
      $(SRCDIR)/putseg.c \
      $(SRCDIR)/store_ics.c \
      $(SRCDIR)/store_puh.c \
      $(SRCDIR)/put_minus.c \
      $(SRCDIR)/put_plus.c \
      $(SRCDIR)/put_precision.c \
      $(SRCDIR)/put_sharp.c \
      $(SRCDIR)/put_space.c \
      $(SRCDIR)/put_zero.c

TOOLSSRC = $(TOOLSDIR)/ft_atoi.c \
           $(TOOLSDIR)/ft_isdigit.c \
           $(TOOLSDIR)/ft_itoa.c \
           $(TOOLSDIR)/ft_putchar.c \
           $(TOOLSDIR)/ft_putnstr.c \
           $(TOOLSDIR)/ft_putstr.c \
           $(TOOLSDIR)/ft_strlen.c \
           $(TOOLSDIR)/ft_count_mod.c \
	   $(TOOLSDIR)/ft_strdup.c \

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

