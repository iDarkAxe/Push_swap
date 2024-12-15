.PHONY : all clean fclean re bonus
CC = gcc
CFLAGS = -Wall -Wextra -MMD -MP
NAME = push_swap

DEBUG_CC = clang
DEBUG_CFLAGS = -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion

#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = ./

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
SRC = \
	main.c

INSTRUCTIONS = \
	ft_push_ps.c \
	ft_swap_ps.c \
	ft_rotate_ps.c \
	ft_rrotate_ps.c

STACK = \
	ft_stack.c

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) \
	$(addprefix $(P_SRC), $(INSTRUCTIONS)) \
	$(addprefix $(P_SRC), $(STACK))

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
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(P_INC) -c $< -o $@
# 
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

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

# Debugging
debug:
	$(CC) $(CFLAGS) -D DEBUG=1 -c *.c
	$(CC) $(CFLAGS) -D DEBUG=1 -o $(NAME) *.o
	@mkdir -p .obj
	@mv *.o *.d .obj

# debug:
# 	@$(MAKE) --no-print-directory DEBUG=1 all

debug-cc:
	$(DEBUG_CC) $(CFLAGS) $(DEBUG_CFLAGS) -D DEBUG=1 -c *.c
	$(DEBUG_CC) $(CFLAGS) $(DEBUG_CFLAGS) -D DEBUG=1 -o $(NAME) *.o
	@mkdir -p .obj
	@mv *.o *.d .obj

debug-print:
	@echo "$(Red)Project: \n\t$(Blue)$(NAME)$(Color_Off)"
	@echo ""
	@echo "$(Red)SRCS: \n\t$(Blue)$(SRCS)$(Color_Off)"
	@echo ""
	@echo "$(Red)OBJS: \n\t$(Blue)$(OBJS)$(Color_Off)"

# Aliases
clear: clean
fclear: fclean
flcean: fclean
flcear: fclean

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