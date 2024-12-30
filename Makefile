.PHONY : all clean fclean re bonus clean-lib clean-bin clean-obj debug debug-cc debug-print
CC = gcc
CFLAGS = -Wall -Wextra
DEPENDANCIES = -MMD -MP
NAME = push_swap

DEBUG_CC = clang
DEBUG_CFLAGS = -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion -Wno-unsafe-buffer-usage -fsanitize=address -fsanitize=leak

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
P_CHECKER = checker/

# Object directories
P_OBJ = .obj/

# Header directories
P_INC = inc/

# Libraries directories
P_LIB = lib/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################
# Headers
INC = \
	ft_pushswap.h \
	ft_checker.h \
	ft_sort.h \
	get_next_line.h \
	ft_printf.h

# Source files
SRC = \
	ft_push_swap.c

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
	ft_print_stacks.c \
	ft_print.c

CHECKER = \
	checker.c \
	checker_parsing.c

GNL = \
	get_next_line.c \
	get_next_line_utils.c

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

SRCS_CHECKER = \
	$(addprefix $(P_SRC)$(P_CHECKER), $(CHECKER))

SRCS_GNL = \
	$(addprefix $(P_SRC)$(P_CHECKER), $(GNL))

# List of object files (redirect to P_OBJ)
OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))
P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

OBJS_CHECKER = $(subst $(P_SRC), $(P_OBJ), $(SRCS_CHECKER:.c=.o))
OBJS_GNL = $(subst $(P_SRC), $(P_OBJ), $(SRCS_GNL:.c=.o))

# List of depedencies
DEPS = $(OBJS:%.o=%.d)

# List of header files
INCS = $(addprefix $(P_INC), $(INC))

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all: $(NAME)

# Create push_swap executable
$(NAME): $(P_OBJ)main.o $(P_LIB)libpush_swap.a 
	$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -o $(NAME) $< -L$(P_LIB) -lpush_swap

# Create library used to create push_swap executable
$(P_LIB)libpush_swap.a: $(OBJS)
	@mkdir -p $(P_LIB)
	ar -rcs $(P_LIB)libpush_swap.a $^

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -c $< -o $@

bonus: $(NAME) checker

# Create checker executable using push_swap library and gnl library
checker: $(P_LIB)libgnl.a $(P_LIB)libpush_swap.a $(OBJS_CHECKER)
	@mkdir -p $(P_LIB)
	$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -o $@ $(OBJS_CHECKER) -L$(P_LIB) -lpush_swap -lgnl

# Create gnl library
$(P_LIB)libgnl.a: $(OBJS_GNL)
	@mkdir -p $(P_LIB)
	ar -rcs $(P_LIB)libgnl.a $^

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)

clean-lib:
	rm -rfd $(P_LIB)

clean-bin:
	rm -f $(NAME)
	rm -f checker

clean-obj:
	@$(MAKE) --no-print-directory clean

fclean:
	@$(MAKE) --no-print-directory clean-obj
	@$(MAKE) --no-print-directory clean-lib
	@$(MAKE) --no-print-directory clean-bin

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
	$(CC) $(CFLAGS) -g3 -D DEBUG=1 -I $(P_INC) $(SRCS) -o $(NAME) 

debug-cc:
	$(DEBUG_CC) $(CFLAGS) -g3 $(DEBUG_CFLAGS) -D DEBUG=1 -I $(P_INC) -o $(NAME) $(SRCS)

debug-print:
	@echo "$(Red)Project: \n\t$(Blue)$(NAME)$(Color_Off)"
	@echo ""
	@echo "$(Red)SRCS: \n\t$(Blue)$(SRCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)OBJS: \n\t$(Blue)$(OBJS)$(Color_Off)"
	@echo ""
	@echo "$(Red)INCS: \n\t$(Blue)$(INCS)$(Color_Off)"

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