SRCS = 	main.c \
		instructions/ft_instructions.c instructions/ft_instructions_utils.c  instructions/ft_instructions_utils2.c\
		algorithme/ft_algorithme_03.c  algorithme/ft_algorithme_03_utils.c algorithme/ft_simplified.c ft_checkerrors.c algorithme/ft_push_b_to_a.c \
		algorithme/ft_algorithme_00.c algorithme/ft_push_a_to_b.c

OBJDIR = objets
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_BONNUS = $(SRCS_BONNUS:%.c=$(OBJDIR)/%.o)
LIB = make -C ./libft
INCS = includes
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = push_swap

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[1;34m
NC = \033[0m

all: titre ${NAME}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR) $(OBJDIR)/instructions $(OBJDIR)/checker $(OBJDIR)/algorithme 
	@${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

${NAME}: ${OBJS}
	@${LIB}
	@echo "${GREEN}compiling push_swap...${NC}"
	@${CC} ${CFLAGS} -fsanitize=address -g ${OBJS} -L./libft -lft -o ${NAME}
	@printf "\r${YELLOW}Compiling: [${GREEN}%-50s${YELLOW}] %d/%d${NC}" $$(printf "#%.0s" $$(seq 1 $$(expr $$(find $(OBJDIR) -type f -name '*.o' | wc -l) \* \
	 50 / $(words $(SRCS))))) $$(find $(OBJDIR) -type f -name '*.o' | wc -l) $(words $(SRCS))
	@echo "\n${BLUE} ./push_swap [parametters] ready to use ${NC}"


titre:
	@echo "\n"
	@echo "${BLUE}██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████ "
	@echo "██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██ "
	@echo "██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████  "
	@echo "██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██      "
	@echo "██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██      "
	@echo "\n \n"

clean:
	@${RM} -r ${OBJDIR}
	@make clean -C ./libft

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ./libft 

re: fclean all

.PHONY: all clean fclean re
