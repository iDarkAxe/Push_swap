.PHONY : all clean fclean re bonus
CC = gcc
CFLAGS = -Wall -Wextra
DEPENDANCIES = -MMD -MP
NAME = push_swap

DEBUG_CC = clang
DEBUG_CFLAGS = -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion

#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = src/
P_INSTRUCTIONS = instructions/
P_STACK = stack/
P_SORT = sort/
P_OPTIONAL = optional/

# Object directories
P_OBJ = .obj/

# Header directories
P_INC = ./

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################
# Headers
INC = \
	ft_pushswap.h

# Source files
# SRC = 

INSTRUCTIONS = \
	ft_push_ps.c \
	ft_swap_ps.c \
	ft_rotate_ps.c \
	ft_rrotate_ps.c

STACK = \
	ft_stack.c \
	ft_filler_ps.c \
	ft_verify.c

SORT = \
	ft_sort.c \
	ft_sort_hardcoded.c

OPTIONAL = \
	test_only.c

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) \
	$(addprefix $(P_SRC)$(P_INSTRUCTIONS), $(INSTRUCTIONS)) \
	$(addprefix $(P_SRC)$(P_STACK), $(STACK)) \
	$(addprefix $(P_SRC)$(P_SORT), $(SORT)) \
	$(addprefix $(P_SRC)$(P_OPTIONAL), $(OPTIONAL))

# List of object files (redirect to P_OBJ)
OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))
P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

# List of depedencies
DEPS = $(OBJS:%.o=%.d)

# List of header files
INCS = $(addprefix $(P_INC)/, $(INC))

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all: $(NAME)

# Create static library
$(NAME): $(OBJS) $(P_OBJ)main.o
	$(CC) $(CFLAGS) $(DEPENDANCIES) -o $(NAME) $^

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -c $< -o $@

checker: $(OBJS) src/checker/checker.c
	ar -rcs libpush_swap.a $^
	$(CC) $(CFLAGS) -I $(P_INC) -o $@ src/checker/checker.c libpush_swap.a

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)

fclean:
	@$(MAKE) --no-print-directory clean
	rm -f $(NAME)
	rm -f libpush_swap.a
	rm -f checker

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

# Aliases
clear: clean
fclear: fclean
flcean: fclean
flcear: fclean

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging
debug:
	$(CC) $(CFLAGS) -g3 -D DEBUG=1 -I ./ $(SRCS) $(P_SRC)main.c -o $(NAME) 

# debug:
# 	@$(MAKE) --no-print-directory DEBUG=1 all

debug-cc:
	$(DEBUG_CC) $(CFLAGS) -g3 $(DEBUG_CFLAGS) -D DEBUG=1 -I ./ -o $(NAME) $(SRCS) $(P_SRC)main.c

debug-print:
	@echo "$(Red)Project: \n\t$(Blue)$(NAME)$(Color_Off)"
	@echo ""
	@echo "$(Red)SRCS: \n\t$(Blue)$(SRCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)OBJS: \n\t$(Blue)$(OBJS)$(Color_Off)"

#############################################################################################
#                                                                                           #
#                                         COSMETIC                                          #
#                                                                                           #
#############################################################################################
# Reset
Color_Off=\033[0m       # Text Reset

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

-include $(DEPS)% 