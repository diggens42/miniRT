CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-Ofast
# CFLAGS	+=	-fsanitize=address -g
LDFLAGS	=	-ldl -lglfw -pthread -lm
RM		=	rm -rf
MLX_URL =	https://github.com/codam-coding-college/MLX42.git

NAME	=	miniRT
SRCS	=	./src/main.c \
			./src/parse.c \
			./src/utils/tuple_arithmetics.c \
			./src/utils/tuple_create.c \
			./src/utils/tuple_vec_ops.c
OBJS	=	$(SRCS:.c=.o)
HEADERS	=	./include/miniRT.h

LIBFT	=	./libft/libft.a
MLX42	=	./MLX42/build/libmlx42.a

RESET	=	\033[0m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@ $(RESET)"
	@echo "$(YELLOW)Creating executable finished.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) -c $< -o $@ $(RESET)"
	@echo "$(YELLOW)Creating object file finished.$(RESET)"

$(LIBFT):
	@git submodule init
	@git submodule update --remote
	@$(MAKE) -C ./libft

$(MLX42):
	@if [ ! -d "./MLX42" ]; then \
		git clone $(MLX_URL) ./MLX42; \
	fi
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

bonus: CFLAGS += -D BONUS=1
bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "$(RED) $(RM) $(OBJS) $(RESET)"
	@echo "$(YELLOW)Deleting object files finished.$(RESET)"

	@$(RM) ./MLX42/build
	@echo "$(RED) $(RM) ./MLX42/build $(RESET)"
	@echo "$(YELLOW)Deleting MLX42 files finished.$(RESET)"

	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) $(RM) $(NAME) $(RESET)"
	@echo "$(YELLOW)Deleting executable finished.$(RESET)"

	@$(MAKE) fclean -C ./libft

re: fclean
	@$(MAKE) all

docker-build:
	@docker build -t minirt .
	@echo "$(YELLOW)Docker image 'minirt' built successfully.$(RESET)"

docker-run:
	@docker run --rm minirt
	@echo "$(YELLOW)Docker container finished.$(RESET)"

docker: docker-build
	@echo "$(YELLOW)Build verified in Linux container.$(RESET)"

.PHONY: all clean fclean re docker-build docker-run docker
