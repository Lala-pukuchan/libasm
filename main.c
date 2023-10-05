#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern void ft_write(int fd, const char *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern ssize_t ft_strlen(const char *buf);
char *ft_strcpy(char *dest, const char *src);

int main() {

	// ft_write
	char *str = "Hello World!";
	ft_write(1, str, 12);

	// ft_read
	int fd = open("./test.txt", O_RDONLY);
	if (fd == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(3);
		ssize_t size = ft_read(fd, buf, 3);
		printf("\nsize: %zu\n", size);
		printf("buf: %s\n", buf);
		close(fd);
	}

	// ft_strlen
	printf("len: %zu\n", ft_strlen(str));

	// ft_strcpy
	char *dst = malloc(12);
	ft_strcpy(dst, str);
	printf("dst: %s\n---\n", dst);

	system("leaks a.out");
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
