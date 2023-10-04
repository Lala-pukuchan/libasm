#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern void ft_write(int fd, const char *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);

int main() {
	char *str = "Hello World!!!\n";
	ft_write(1, str, 15);

	int fd = open("./test.txt", O_RDONLY);
	if (fd == -1) {
		printf("error in opening file.");
		exit(1);
	} else {
		char *buf = malloc(3);
		ssize_t size = ft_read(fd, buf, 3);
		printf("size: %zu\n", size);
		printf("buf: %s\n", buf);
		close(fd);
	}

	return (0);
}