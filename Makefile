NAME = libasm.a
SRCS = ft_write.s ft_read.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

withMain: $(NAME)
	gcc -c main.c -o main.o
	gcc main.o -L. -lasm -o test

cleanMain:
	rm -f main.o
	rm -f test

.PHONY: all clean fclean re withMain
