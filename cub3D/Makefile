# [TARGET]
NAME           					:= cub3D

# [DEBUG OPTION]
DEBUG          					:=  -fsanitize=address -g3 # basic leak test
# DEBUG2      					:=  -g #leaks -> export mallocstack=1 : locates the exact root of the memory leak

# [COMPILATION FLAGS]
CFLAGS        					:= -Wall -Wextra -Werror #$(DEBUG)

# CC
CC								:=  cc

# [MAINSTREAM DIR]
SRC_DIR        					:=  ./srcs/
OBJS_DIR       					:=  ./objs/
HEADER_DIR     					:=  ./

# [HEADER DIR FOR ARCHIVE]
AR_HEADER_DIR   				:=  srcs/ar/header
AR_HEADER_FILES 				:=  $(AR_HEADER_DIR)/libft.h \
									$(AR_HEADER_DIR)/ft_printf.h \
									$(AR_HEADER_DIR)/get_next_line.h

MLX_DIR	  = mlx
LINK_FLAG = -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

# [COLOR SETTINGS]
BLACK          					:=  \033[0;30m
RED            					:=  \033[0;31m
GREEN          					:=  \033[0;32m
GREEN_BOLD     					:=  \033[1;32m
YELLOW         					:=  \033[0;33m
BLUE           					:=  \033[0;34m
PURPLE         					:=  \033[0;35m
CYAN           					:=  \033[0;36m
WHITE          					:=  \033[0;37m
DEF_COLOR      					:=  \033[0;39m
LF             					:=  \e[1K\r

# [DELAY_TIME]
DELAY_OBJS	 					:= 0
DELAY_CLEAR 					:= 0
DELAY_CLEAR2 					:= 0

# # ================================== MANDATORY PART ======================================= #

###############################################################################################
############################### [MANDATORY directory] #########################################
###############################################################################################

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [HEADER FILES]
HEADER_MANDATORY_DIR			:=  $(HEADER_DIR)/header

HEADER_FILES_MANDATORY			:=  $(HEADER_MANDATORY_DIR)/cub3d.h

PARSING_DIR						:= $(SRC_DIR)parse/
EXEC_DIR						:= $(SRC_DIR)execution/
DISPLAY_DIR						:= $(SRC_DIR)display

# [AGGREGATION OF ALL MANDATORY CLASSES]
SRCS_PARSE					:=	$(addprefix $(PARSING_DIR), \
								elements.c \
								error.c \
								find.c \
								heap.c \
								heap2.c \
								main.c \
								map.c \
								utils.c \
								utils2.c \
								validation.c \
								validation2.c)

SRCS_EXEC					:=	$(addprefix $(EXEC_DIR), draw.c \
								module.texture.c\
								module.init.c\
								module.calc.c\
								module.move.c)
									
SRCS						:= $(SRCS_PARSE) \
							   $(SRCS_EXEC)
# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [MANDATORY OBJS DIRECTORY]
OBJS 				    		:= $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

##############################################################################################
##############################################################################################
##############################################################################################

# [LIBFT ARCHIVE DIRECTORY]
LIB_DIR 			   			:= ./srcs/ar/
LIB 				   			:= $(LIB_DIR)libft.a

# [PROGRESS BAR SETTING]
# [FILE DATA]
TOTAL_FILES 	        		:= $(words $(SRCS))
CURRENT_FILE 		    		:= 1

# [BAR DATA]
progress_bar                    =	printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
          					    	printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
   	        				    	printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(GREEN_BOLD)[OK]$(DEF_COLOR) \033[A\033[999C\e[?25l"; \


# [MAKE ALL : MANDATORY RULE]
all: $(OBJS_DIR) $(NAME)

# [CREATING TARGET FILE + LIBFT ARCHIVE(libft.a)]
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\n"
	@sleep $(DELAY_CLEAR2)
	@printf "$(GREEN)===============================================\n$(DEF_COLOR)"
	@printf "$(GREEN)|     🥳  [$(NAME)] compile success. 🥳    |\n$(DEF_COLOR)"
	@printf "$(GREEN)===============================================\n\n$(DEF_COLOR)"
	@printf "\e[?25h"

# [CREATING OBJECT FILES]
$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY) $(AR_HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_MANDATORY_DIR) -I$(AR_HEADER_DIR) -I$(MLX_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep $(DELAY_OBJS)

# [CREATING OBJECT DIRECTORY]
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# =========================================================================================== #

# [LIBFT ARCHIVE FILE]
$(LIB): $(AR_HEADER_FILES)	
	@sleep $(DELAY_CLEAR)
	@clear
	@sleep $(DELAY_CLEAR)
	@echo "\n\t$(GREEN)cub3D$(DEF_COLOR) compliation has been successfully finished.\n"
	@sleep $(DELAY_CLEAR2)
	@clear
	@sleep $(DELAY_CLEAR)
	@echo "\n\t$(GREEN)LIBFT ARCHIEVE$(DEF_COLOR) compliation process begins...$(DEFAULT_COLOR)\n"
	@sleep $(DELAY_CLEAR2)
	@clear
	@sleep $(DELAY_CLEAR)
	@printf "\n$(GREEN_BOLD)LIBFT ARCHIEVE compliation in progress...$(DEFAULT_COLOR)\n\n"
	@$(MAKE) -C $(LIB_DIR) 

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep $(DELAY_CLEAR)

# ============================================================================================= #

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"	
	@sleep $(DELAY_CLEAR2)
	@clear
	@printf "$(DEF_COLOR)"

re: fclean
	@sleep $(DELAY_CLEAR2)
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
