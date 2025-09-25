NAME = fractol_intro

TDIR = tools
ODIR = objs

CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address -g

SRCS = $(wildcard $(TDIR)/*.c)

OBJS = $(addprefix $(ODIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@
	@echo "Compilation effectuée."

$(ODIR)/%.o: $(TDIR)/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	@mkdir -p $(ODIR)

clean:
	@rm -rf $(ODIR)
	@echo "Nettoyage des fichiers objets effectué."

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet effectué."

re: fclean all

dbug: CFLAGS += $(DFLAGS)
dbug: re

.PHONY: all clean fclean re dbug
