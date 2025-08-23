# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baelgadi <baelgadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 01:41:33 by baelgadi          #+#    #+#              #
#    Updated: 2025/08/23 23:56:08 by baelgadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ─────────────────────────────────
#             🎨 COLORS
# ─────────────────────────────────

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
GRAY = \033[90m
UNDERLINE = \033[4m

# ─────────────────────────────────
#         🛠️ CONFIGURATION
# ─────────────────────────────────

NAME = push_swap

BONUS_NAME = checker

# ─────────────────────────────────
#             📂 FILES
# ─────────────────────────────────

PUSH_SWAP =		push_swap

PARSING =		parsing

UTILS =			operations		\
				utils			\
				stack_utils

WRAPPERS =		wrapper_a		\
				wrapper_b		\
				wrapper_both

SORTING =		ez_sort			\
				turk_sort

BONUS =			checker			\
				dispatcher		\
				get_instructions

# ─────────────────────────────────
#      🚧 SETUP & DEPENDENCIES
# ─────────────────────────────────

SRCS = $(addprefix mandatory/push_swap/, $(addsuffix .c,$(PUSH_SWAP))) \
	$(addprefix mandatory/parsing/, $(addsuffix .c,$(PARSING))) \
	$(addprefix mandatory/utils/, $(addsuffix .c,$(UTILS))) \
	$(addprefix mandatory/wrappers/, $(addsuffix .c,$(WRAPPERS))) \
	$(addprefix mandatory/sorting/, $(addsuffix .c,$(SORTING)))

BONUS_SRCS = $(addprefix bonus/, $(addsuffix _bonus.c,$(BONUS))) \
	$(addprefix mandatory/parsing/, $(addsuffix .c,$(PARSING))) \
	$(addprefix mandatory/utils/, $(addsuffix .c,$(UTILS)))

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

DEPS =  $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./include -MMD -MP

# ─────────────────────────────────
#            🎯 TARGETS
# ─────────────────────────────────

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ && printf "$(GREEN)✅ $@ created\n" || printf "$(RED) ❌ $@\n"

bonus: $(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ && printf "$(GREEN)☑️ $@ created\n" || printf "$(RED) ❌ $@\n"

both: $(NAME) $(BONUS_NAME)

# ─────────────────────────────────
#        💽 COMPILATION RULES
# ─────────────────────────────────

.c.o:
	@printf "Compiling $(BLUE)%-35s$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@ && printf "✅\n" || printf "❌\n"

# ─────────────────────────────────
#            🧹 CLEANING
# ─────────────────────────────────

clean:
	@rm -f $(OBJS) $(OBJS:.o=.d) $(BONUS_OBJS) $(BONUS_OBJS:.o=.d)
	@echo "$(YELLOW)🧹 Objects and dependencies deleted (clean)$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(RED)❌ $(NAME) & $(BONUS_NAME) removed (fclean)$(RESET)"

re:	fclean all

# ─────────────────────────────────
#         🌐 HELP & FOOTER
# ─────────────────────────────────

help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "$(YELLOW)all      $(RESET)– Build push_swap (mandatory)"
	@echo "$(YELLOW)bonus    $(RESET)– Build checker (bonus)"
	@echo "$(YELLOW)both     $(RESET)– Build push_swap & checker"
	@echo "$(YELLOW)clean    $(RESET)– Delete .o and .d files"
	@echo "$(YELLOW)fclean   $(RESET)– Full clean"
	@echo "$(YELLOW)re       $(RESET)– fclean + all"

-include $(DEPS)

.PHONY: all clean fclean re bonus both help
